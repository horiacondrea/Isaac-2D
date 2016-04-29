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

#include "SceneMachine.h"
#include <IDynamicScene.h>

namespace isaac
{

  CSceneMachine::CSceneMachine(std::shared_ptr<sf::RenderWindow>& av_xMainWindow, 
                               std::shared_ptr<isaac::COrchestrator>& av_xSceneOrchetrator,
                               std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData ) :
                                                                                                    mv_xMainWindow(av_xMainWindow) ,
                                                                                                    mv_xSceneOrchestrator(av_xSceneOrchetrator) ,
                                                                                                    mc_xTransientData(av_xTransientData)
  {
    mv_bHasThisSceneInit = false;

    BOOST_ASSERT_MSG(mv_xMainWindow != nullptr, "Main Window is null");
    BOOST_ASSERT_MSG(mv_xSceneOrchestrator != nullptr, "Orchestrator is not up");
    BOOST_ASSERT_MSG(mc_xTransientData != nullptr, "Transient data is not defined");
  }

  void CSceneMachine::mp_InitCurrentScene(sf::Event av_Event)
  {
    bool lv_bCheckForAutomaticBlock;
    const auto& lv_SceneAndTrigger = mv_xSceneOrchestrator->mf_xGetSceneToBeDisplayed(lv_bCheckForAutomaticBlock, av_Event);
    mv_xCurrentScene = std::const_pointer_cast<isaac::IScene>(lv_SceneAndTrigger.first);
    mv_szLastTriggerName = lv_SceneAndTrigger.second;

    if (mv_xCurrentScene != mv_xPrevScene && mv_xPrevScene != nullptr)
    {
      mp_ReleseScene(mv_xPrevScene);
      mv_bHasThisSceneInit = false;
    }
    else
    {
      //Chek if we are dealing with an automatic block
      if (mv_xCurrentScene == mv_xPrevScene)
      {
        if (lv_bCheckForAutomaticBlock)
        {
          mv_bHasThisSceneInit = false;
          mp_ReleseScene(mv_xPrevScene);
        }
      }
    }
    mv_xPrevScene = mv_xCurrentScene;

    if (!mv_bHasThisSceneInit)
    {
      mv_mapHierarchyOfScenes.clear();
      if (!(mv_xCurrentScene->mf_bIsSubScene()))
      {
        if (mv_xCurrentScene->mp_bIsDynamicScene())
        {
          auto lc_xCurrentDynScene = std::static_pointer_cast<isaac::IDynamicScene>(mv_xCurrentScene);
          if (mv_xSceneOrchestrator->mf_bGetDynamicSceneStatus(lc_xCurrentDynScene->mf_szGetSceneName()))
          {
            lc_xCurrentDynScene->mp_DefineProcess();
          }
        }
        mv_xCurrentScene->mp_InitScene(mv_xMainWindow, mc_xTransientData);
        mv_xCurrentScene->mp_InitTriggers(mv_xSceneOrchestrator->mf_xGetTriggersPerScene());
        mv_bHasThisSceneInit = true;
      }
      else
      {
        auto lv_xLocalScene = mv_xCurrentScene;
        mv_mapHierarchyOfScenes.push_front(std::make_pair(lv_xLocalScene, true));
        do
        {
          const bool isFatherActive = lv_xLocalScene->mf_bIsFatherSceneActive();
          lv_xLocalScene = std::const_pointer_cast<isaac::IScene>(lv_xLocalScene->mf_xGetFatherScene());
          mv_mapHierarchyOfScenes.push_front(std::make_pair(lv_xLocalScene, isFatherActive));
        } while (lv_xLocalScene->mf_bIsSubScene());

        for (const auto& item : mv_mapHierarchyOfScenes)
        {
          if (item.first->mp_bIsDynamicScene())
          {
            auto lc_xCurrentDynScene = std::static_pointer_cast<isaac::IDynamicScene>(item.first);
            if (mv_xSceneOrchestrator->mf_bGetDynamicSceneStatus(lc_xCurrentDynScene->mf_szGetSceneName()))
            {
              lc_xCurrentDynScene->mp_DefineProcess();
            }
          }
          item.first->mp_InitScene(mv_xMainWindow, mc_xTransientData);
          item.first->mp_InitTriggers(mv_xSceneOrchestrator->mf_xGetTriggersPerScene());
          mv_bHasThisSceneInit = true;
        }
      }
    }
  }

  void CSceneMachine::mp_ActivateCurrentScene(sf::Event event)
  {
    bool lv_bCurrentSceneProvideExitScene;
    if (!(mv_xCurrentScene->mf_bIsSubScene()))
    {
      mv_xCurrentScene->mp_UpdateScene(mv_xMainWindow, mc_xTransientData, event, lv_bCurrentSceneProvideExitScene);
      mv_xCurrentScene->mp_DrawScene(mv_xMainWindow);
    }
    else
    {
      for (const auto& item : mv_mapHierarchyOfScenes)
      {
        if (item.second)
          item.first->mp_UpdateScene(mv_xMainWindow, mc_xTransientData, event, lv_bCurrentSceneProvideExitScene);
        item.first->mp_DrawScene(mv_xMainWindow);
      }
    }

    if (event.type == sf::Event::Closed)
    {
      mv_xMainWindow->close();
      mp_ReleseScene(mv_xCurrentScene);
    }
    if (lv_bCurrentSceneProvideExitScene)
    {
      mp_ReleseScene(mv_xCurrentScene);
    }
  }

  void CSceneMachine::mp_ReleseScene(std::shared_ptr< isaac::IScene >& av_xSceneToRelease)
  {
    av_xSceneToRelease->mp_Release(mc_xTransientData, mv_szLastTriggerName);
    if (av_xSceneToRelease->mf_bIsSubScene())
    {
      do
      {
        av_xSceneToRelease = std::const_pointer_cast<isaac::IScene>(mv_xPrevScene->mf_xGetFatherScene());
        av_xSceneToRelease->mp_Release(mc_xTransientData, mv_szLastTriggerName);
      } while (av_xSceneToRelease->mf_bIsSubScene());
    }
  }


  CSceneMachine::~CSceneMachine()
  {
  }
}