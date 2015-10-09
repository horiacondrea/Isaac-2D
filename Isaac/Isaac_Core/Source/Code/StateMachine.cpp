///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    
//                                                          //  IsaacFramework  //
//                                                         //////////////////////
// 
// Copyright (c) 2014 Horatiu Condrea
// 
// This software is provided 'as-is', without any express or implied warranty. 
// In no event will the authors be held liable for any damages arising from the use of this software.
// 
// Permission is granted to anyone to use this software for any purpose, including commercial applications, 
// and to alter it and redistribute it freely, subject to the following restrictions:
// 
//  1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. a
//     If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
// 
//  2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
// 
//  3. This notice may not be removed or altered from any source distribution.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Copyright @ 2014
Author Horatiu Condrea [ horiacondrea.com ]
Revision | Who      | Date       | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | Feb   2014 | Created
*/

#include "StateMachine.h"
#include <IDynamicState.h>

namespace Core
{

  CStateMachine::CStateMachine(std::shared_ptr<sf::RenderWindow>& av_xMainWindow, 
                               std::shared_ptr<Core::COrchestrator>& av_xStateOrchetrator,
                               std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData ) :
                                                                                                    mv_xMainWindow(av_xMainWindow) ,
                                                                                                    mv_xStateOrchestrator(av_xStateOrchetrator) ,
                                                                                                    mc_xTransientData(av_xTransientData)
  {
    mv_bHasThisStateInit = false;

    BOOST_ASSERT_MSG(mv_xMainWindow != nullptr, "Main Window is null");
    BOOST_ASSERT_MSG(mv_xStateOrchestrator != nullptr, "Orchestrator is not up");
    BOOST_ASSERT_MSG(mc_xTransientData != nullptr, "Transient data is not defined");
  }

  void CStateMachine::mp_InitCurrentState(sf::Event av_Event)
  {
    bool lv_bCheckForAutomaticBlock;
    std::pair< std::shared_ptr<const Foundation::Interfaces::IState >, const char*> lv_StateAndTrigger = mv_xStateOrchestrator->mf_xGetStateToBeDisplayed(lv_bCheckForAutomaticBlock, av_Event);
    mv_xCurrentState = std::const_pointer_cast<Foundation::Interfaces::IState>(lv_StateAndTrigger.first);
    mv_szLastTriggerName = lv_StateAndTrigger.second;

    if (mv_xCurrentState != mv_xPrevState && mv_xPrevState != nullptr)
    {
      mp_ReleseState(mv_xPrevState);
      mv_bHasThisStateInit = false;
    }
    else
    {
      //Chek if we are dealing with an automatic block
      if (mv_xCurrentState == mv_xPrevState)
      {
        if (lv_bCheckForAutomaticBlock)
        {
          mv_bHasThisStateInit = false;
          mp_ReleseState(mv_xPrevState);
        }
      }
    }
    mv_xPrevState = mv_xCurrentState;

    if (!mv_bHasThisStateInit)
    {
      mv_mapHierarchyOfStates.clear();
      if (!(mv_xCurrentState->mf_bIsSubState()))
      {
        if (mv_xCurrentState->mp_bIsDynamicState())
        {
          std::shared_ptr<Foundation::Interfaces::IDynamicState> lc_xCurrentDynState = std::static_pointer_cast<Foundation::Interfaces::IDynamicState>(mv_xCurrentState);
          if (mv_xStateOrchestrator->mf_bGetDynamicStateStatus(lc_xCurrentDynState->mf_szGetStateName()))
          {
            lc_xCurrentDynState->mp_DefineProcess();
          }
        }
        mv_xCurrentState->mp_InitState(mv_xMainWindow, mc_xTransientData);
        mv_xCurrentState->mp_InitTriggers(mv_xStateOrchestrator->mf_xGetTriggersPerState());
        mv_bHasThisStateInit = true;
      }
      else
      {
        std::shared_ptr<Foundation::Interfaces::IState> lv_xLocalState = mv_xCurrentState;
        mv_mapHierarchyOfStates.push_front(std::make_pair(lv_xLocalState, true));
        do
        {
          const bool isFatherActive = lv_xLocalState->mf_bIsFatherStateActive();
          lv_xLocalState = std::const_pointer_cast<Foundation::Interfaces::IState>(lv_xLocalState->mf_xGetFatherState());
          mv_mapHierarchyOfStates.push_front(std::make_pair(lv_xLocalState, isFatherActive));
        } while (lv_xLocalState->mf_bIsSubState());

        for (const auto& item : mv_mapHierarchyOfStates)
        {
          if (item.first->mp_bIsDynamicState())
          {
            std::shared_ptr<Foundation::Interfaces::IDynamicState> lc_xCurrentDynState = std::static_pointer_cast<Foundation::Interfaces::IDynamicState>(item.first);
            if (mv_xStateOrchestrator->mf_bGetDynamicStateStatus(lc_xCurrentDynState->mf_szGetStateName()))
            {
              lc_xCurrentDynState->mp_DefineProcess();
            }
          }
          item.first->mp_InitState(mv_xMainWindow, mc_xTransientData);
          item.first->mp_InitTriggers(mv_xStateOrchestrator->mf_xGetTriggersPerState());
          mv_bHasThisStateInit = true;
        }
      }
    }
  }

  void CStateMachine::mp_ActivateCurrentState(sf::Event event)
  {
    bool lv_bCurrentStateProvideExitState;
    if (!(mv_xCurrentState->mf_bIsSubState()))
    {
      mv_xCurrentState->mp_UpdateState(mv_xMainWindow, mc_xTransientData, event, lv_bCurrentStateProvideExitState);
      mv_xCurrentState->mp_DrawState(mv_xMainWindow);
    }
    else
    {
      for (const auto& item : mv_mapHierarchyOfStates)
      {
        if (item.second)
          item.first->mp_UpdateState(mv_xMainWindow, mc_xTransientData, event, lv_bCurrentStateProvideExitState);
        item.first->mp_DrawState(mv_xMainWindow);
      }
    }

    if (event.type == sf::Event::Closed)
    {
      mv_xMainWindow->close();
      mp_ReleseState(mv_xCurrentState);
    }
    if (lv_bCurrentStateProvideExitState)
    {
      mp_ReleseState(mv_xCurrentState);
    }
  }

  void CStateMachine::mp_ReleseState(std::shared_ptr< Foundation::Interfaces::IState >& av_xStateToRelease)
  {
    av_xStateToRelease->mp_Release(mc_xTransientData, mv_szLastTriggerName);
    if (av_xStateToRelease->mf_bIsSubState())
    {
      do
      {
        av_xStateToRelease = std::const_pointer_cast<Foundation::Interfaces::IState>(mv_xPrevState->mf_xGetFatherState());
        av_xStateToRelease->mp_Release(mc_xTransientData, mv_szLastTriggerName);
      } while (av_xStateToRelease->mf_bIsSubState());
    }
  }


  CStateMachine::~CStateMachine()
  {
  }
}