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

#include "..\Include\Orchestrator.h"
#include <BufferITriggerCollection.h>
#include <IDynamicState.h>
#include <list>

namespace Core
{
  COrchestrator::COrchestrator(std::shared_ptr<const Foundation::Interfaces::IState>& ac_xInitialState, 
                               std::shared_ptr<const Foundation::Interfaces::IStateCollection>& ac_xStateCollection,
                               std::shared_ptr<const Foundation::Interfaces::ITransitionCollection>& ac_xTransitionCollection) :
    mc_xInitialState(ac_xInitialState),
    mc_xStateCollection(ac_xStateCollection),
    mc_xTransitionCollection(ac_xTransitionCollection)
  {
    BOOST_ASSERT_MSG(mc_xInitialState != nullptr, "InitialState is null");
    BOOST_ASSERT_MSG(mc_xStateCollection != nullptr, "State collection is null");
    BOOST_ASSERT_MSG(mc_xStateCollection->mp_GetSize() != 0, "There is no state defined");
    BOOST_ASSERT_MSG(mc_xTransitionCollection != nullptr, "Transition collection is null");

    mv_bIsThisFirstTimeHere = true;
    mv_szLastTriggerName = "NoTrigger";
    mp_OrganizeDynamicStates();
  }

  std::pair<std::shared_ptr< const Foundation::Interfaces::IState >, const CString>  COrchestrator::mf_xGetStateToBeDisplayed(bool& av_bHasAnyTriggerDisturbed, sf::Event av_Event)
  {
    av_bHasAnyTriggerDisturbed = false;
    if (mc_xTransitionCollection->mp_GetSize() == 0)
    {
      mc_xCurrentState = mc_xInitialState;
    }
    else
    {
      if (mv_bIsThisFirstTimeHere)
      {
        mc_xCurrentState = mc_xInitialState;
        mv_bIsThisFirstTimeHere = false;
        av_bHasAnyTriggerDisturbed = false;
      }
      else
      {
        std::list<CString> av_listStateNames;
        std::shared_ptr<const Foundation::Interfaces::IState> lv_xLocalState = mc_xCurrentState;
        av_listStateNames.push_back(lv_xLocalState->mf_szGetStateName());
        if (mc_xCurrentState->mf_bIsSubState())
        {
          do
          {
            lv_xLocalState = lv_xLocalState->mf_xGetFatherState();
            av_listStateNames.push_back(lv_xLocalState->mf_szGetStateName());
          } while (lv_xLocalState->mf_bIsSubState());
        }

        for (const auto& lv_pTransition : *mc_xTransitionCollection->mf_mapGetRawMap())
        {
          for (const auto& item : av_listStateNames)
          {
            if (lv_pTransition.second->mf_xGetSourceState()->mf_szGetStateName() == item)
            {
              if (lv_pTransition.second->mf_bCheckTransition(av_Event))
              {
                mc_xCurrentState = lv_pTransition.second->mf_xGetDestinationState();
                mv_szLastTriggerName = lv_pTransition.second->mf_xGetTrigger()->mf_szGetTriggerName();
                av_bHasAnyTriggerDisturbed = true;
                return std::make_pair(mc_xCurrentState, mv_szLastTriggerName);
                break;
              }
              else
              {
                av_bHasAnyTriggerDisturbed = false;
              }
            }
          }
        }
      }
    }
    return std::make_pair(mc_xCurrentState, mv_szLastTriggerName);
  }

  std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& COrchestrator::mf_xGetTriggersPerState() const
  {

    mv_xTriggersPerState = std::make_shared<Foundation::CBufferITriggerCollection>();

    std::list<CString> av_listStateNames;
    std::shared_ptr<const Foundation::Interfaces::IState> lv_xLocalState = mc_xCurrentState;
    av_listStateNames.push_back(lv_xLocalState->mf_szGetStateName());
    if (mc_xCurrentState->mf_bIsSubState())
    {
      do
      {
        lv_xLocalState = lv_xLocalState->mf_xGetFatherState();
        av_listStateNames.push_back(lv_xLocalState->mf_szGetStateName());
      } while (lv_xLocalState->mf_bIsSubState());
    }

    for (const auto& lv_pTransition : *mc_xTransitionCollection->mf_mapGetRawMap())
    {
      for (const auto & item : av_listStateNames)
      {
        if (lv_pTransition.second->mf_xGetSourceState()->mf_szGetStateName() == item)
        {
          const std::shared_ptr<const Foundation::Interfaces::ITrigger> lv_pTrigger = lv_pTransition.second->mf_xGetTrigger();
          mv_xTriggersPerState->mp_AddTrigger(lv_pTrigger);
        }
      }
    }
    return mv_xTriggersPerState;
  }

  void COrchestrator::mp_OrganizeDynamicStates() const
  {
    BOOST_ASSERT_MSG(mc_xStateCollection->mp_GetSize() != 0, "There is no state defined");
    for (const auto& item : *mc_xStateCollection->mf_mapGetRawMap())
    {
      if (item.second->mp_bIsDynamicState())
      {
        mv_mapDynamicMapMirror.emplace(item.first, false);
      }
    }
  }

  const bool COrchestrator::mf_bGetDynamicStateStatus(const CString ac_szDynamicStateName) const
  {
    BOOST_ASSERT_MSG(ac_szDynamicStateName != _T(""), "Dynamic State Name is undefined");

    bool result = false;
    if (ac_szDynamicStateName != _T(""))
    {
      if (mv_mapDynamicMapMirror.size() > 0)
      {
        const auto& item = mv_mapDynamicMapMirror.find(ac_szDynamicStateName);
        if (item->second)
        {
          result = false;
          const std::shared_ptr<const Foundation::Interfaces::IState> lc_xDynamicState = mc_xStateCollection->mf_xGetStateByName(ac_szDynamicStateName);
          if (lc_xDynamicState->mp_bIsDynamicState())
          {
            std::shared_ptr<const Foundation::Interfaces::IDynamicState> lc_xCurrentDynState = std::static_pointer_cast<const Foundation::Interfaces::IDynamicState>(lc_xDynamicState);
            lc_xCurrentDynState->mp_ResetProcessingElements();
          }
        }
        else
        {
          result = true;
          mv_mapDynamicMapMirror.erase(ac_szDynamicStateName);
          mv_mapDynamicMapMirror.emplace(ac_szDynamicStateName, true);
        }
      }
    }
    return result;
  }

  COrchestrator::~COrchestrator()
  {
  }
}