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

#include "Orchestrator.h"
#include <TriggerCollection.h>
#include <IDynamicScene.h>
#include <list>

namespace isaac
{
  COrchestrator::COrchestrator(Scene & ac_xInitialScene, 
                               SceneCollection& ac_xCSceneCollection,
                               TransitionCollection& ac_xTransitionCollection) :
    mc_xInitialScene(ac_xInitialScene),
    mc_xCSceneCollection(ac_xCSceneCollection),
    mc_xTransitionCollection(ac_xTransitionCollection)
  {
    BOOST_ASSERT_MSG(mc_xInitialScene != nullptr, "InitialScene is null");
    BOOST_ASSERT_MSG(mc_xCSceneCollection != nullptr, "Scene collection is null");
    BOOST_ASSERT_MSG(mc_xCSceneCollection->mp_GetSize() != 0, "There is no Scene defined");
    BOOST_ASSERT_MSG(mc_xTransitionCollection != nullptr, "Transition collection is null");

    mv_bIsThisFirstTimeHere = true;
    mv_szLastTriggerName = "NoTrigger";
    mp_OrganizeDynamicScenes();
  }

  std::pair<Scene, std::string>  COrchestrator::mf_xGetSceneToBeDisplayed(bool& av_bHasAnyTriggerDisturbed, sf::Event av_Event)
  {
    av_bHasAnyTriggerDisturbed = false;
    if (mc_xTransitionCollection->mp_GetSize() == 0)
    {
      mc_xCurrentScene = mc_xInitialScene;
    }
    else
    {
      if (mv_bIsThisFirstTimeHere)
      {
        mc_xCurrentScene = mc_xInitialScene;
        mv_bIsThisFirstTimeHere = false;
        av_bHasAnyTriggerDisturbed = false;
      }
      else
      {
        std::list<std::string> av_listSceneNames;
        Scene lv_xLocalScene = mc_xCurrentScene;
        av_listSceneNames.push_back(lv_xLocalScene->mf_szGetSceneName());
        if (mc_xCurrentScene->mf_bIsSubScene())
        {
          do
          {
            lv_xLocalScene = lv_xLocalScene->mf_xGetFatherScene();
            av_listSceneNames.push_back(lv_xLocalScene->mf_szGetSceneName());
          } while (lv_xLocalScene->mf_bIsSubScene());
        }

        for (const auto& lv_pTransition : mc_xTransitionCollection->mf_mapGetRawMap())
        {
          for (const auto& item : av_listSceneNames)
          {
            if (lv_pTransition.second->mf_xGetSourceScene()->mf_szGetSceneName() == item)
            {
              if (lv_pTransition.second->mf_bCheckTransition(av_Event))
              {
                mc_xCurrentScene = lv_pTransition.second->mf_xGetDestinationScene();
                mv_szLastTriggerName = lv_pTransition.second->mf_xGetTrigger()->mf_szGetTriggerName();
                av_bHasAnyTriggerDisturbed = true;
                return std::make_pair(mc_xCurrentScene, mv_szLastTriggerName);
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
    return std::make_pair(mc_xCurrentScene, mv_szLastTriggerName);
  }

  TriggerCollection& COrchestrator::mf_xGetTriggersPerScene() const
  {

    mv_xTriggersPerScene = std::make_shared<isaac::CTriggerCollection>();

    std::list<std::string> av_listSceneNames;
    Scene lv_xLocalScene = mc_xCurrentScene;
    av_listSceneNames.push_back(lv_xLocalScene->mf_szGetSceneName());
    if (mc_xCurrentScene->mf_bIsSubScene())
    {
      do {
        lv_xLocalScene = lv_xLocalScene->mf_xGetFatherScene();
        av_listSceneNames.push_back(lv_xLocalScene->mf_szGetSceneName());
      } while (lv_xLocalScene->mf_bIsSubScene());
    }

    for (const auto& lv_pTransition : mc_xTransitionCollection->mf_mapGetRawMap())
    {
      for (const auto & item : av_listSceneNames)
      {
        if (lv_pTransition.second->mf_xGetSourceScene()->mf_szGetSceneName() == item)
        {
          const auto& lv_pTrigger = lv_pTransition.second->mf_xGetTrigger();
          mv_xTriggersPerScene->mp_AddTrigger(lv_pTrigger);
        }
      }
    }
    return mv_xTriggersPerScene;
  }

  void COrchestrator::mp_OrganizeDynamicScenes() const
  {
    BOOST_ASSERT_MSG(mc_xCSceneCollection->mp_GetSize() != 0, "There is no Scene defined");
    for (const auto& item : mc_xCSceneCollection->mf_mapGetRawMap())
    {
      if (item.second->mp_bIsDynamicScene())
      {
        mv_mapDynamicMapMirror.emplace(item.first, false);
      }
    }
  }

  const bool COrchestrator::mf_bGetDynamicSceneStatus(std::string ac_szDynamicSceneName) const
  {
    BOOST_ASSERT_MSG(!ac_szDynamicSceneName.empty(), "Dynamic Scene Name is undefined");

    bool result = false;
    if (!ac_szDynamicSceneName.empty())
    {
      if (mv_mapDynamicMapMirror.size() > 0)
      {
        const auto& item = mv_mapDynamicMapMirror.find(ac_szDynamicSceneName);
        if (item->second)
        {
          result = false;
          const auto& lc_xDynamicScene = mc_xCSceneCollection->mf_xGetSceneByName(ac_szDynamicSceneName);
          if (lc_xDynamicScene->mp_bIsDynamicScene())
          {
            auto& lc_xCurrentDynScene = std::static_pointer_cast<const isaac::IDynamicScene>(lc_xDynamicScene);
            lc_xCurrentDynScene->mp_ResetProcessingElements();
          }
        }
        else
        {
          result = true;
          mv_mapDynamicMapMirror.erase(ac_szDynamicSceneName);
          mv_mapDynamicMapMirror.emplace(ac_szDynamicSceneName, true);
        }
      }
    }
    return result;
  }

  COrchestrator::~COrchestrator()
  {
  }
}