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

#include "../Include/Game.h"

namespace isaac
{
  void CGame::mp_Start(std::string av_szGameTitle, const unsigned int &av_nGameWidth = 800, const unsigned int &av_nGameHeigh = 600)
  {
    mv_xMainWindow = std::make_shared<sf::RenderWindow>();

    BOOST_ASSERT_MSG(mc_xCSceneCollection != nullptr , "Scene collection is not defined");
    BOOST_ASSERT_MSG(mc_xCSceneCollection->mp_GetSize() > 0, "There is no Scene defined");
    BOOST_ASSERT_MSG(mc_xTransientData != nullptr, "Transient data is not defined");
    BOOST_ASSERT_MSG(mc_xTransitionCollection != nullptr, "Transition collection is not defined");

    if(!(av_szGameTitle.empty())            && 
      mc_xCSceneCollection        != nullptr &&
      mc_xCSceneCollection->mp_GetSize() > 0 &&
      mc_xTransientData          != nullptr &&
      mc_xTransitionCollection   != nullptr && 
      mv_xMainWindow             != nullptr )
    {
      mv_xMainWindow->create(sf::VideoMode(av_nGameWidth, av_nGameHeigh), av_szGameTitle, sf::Style::Close);

      mv_xSceneOrchestrator = std::make_shared<isaac::COrchestrator>(mc_xInitialScene, mc_xCSceneCollection, mc_xTransitionCollection);
      mv_xSceneMachine = std::make_shared<isaac::CSceneMachine>(mv_xMainWindow, mv_xSceneOrchestrator, mc_xTransientData);

      sf::Clock clock;
      float lastTime = 0;

      while (mv_xMainWindow->isOpen()) {

        mp_GameLoop();
        mv_xMainWindow->setFramerateLimit(60);

        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / (currentTime - lastTime);
        lastTime = currentTime;
      }
    }
  }

  void CGame::mp_GameLoop()
  {
    sf::Event event;
    mv_xMainWindow->pollEvent(event);

    mv_xSceneMachine->mp_InitCurrentScene(event);
    mv_xSceneMachine->mp_ActivateCurrentScene(event);

    mv_xMainWindow->display();
    mv_xMainWindow->clear(sf::Color::Black);
  }


  void CGame::mp_DefineGameAspect(const std::shared_ptr<const isaac::IDynamicAspect>& ac_xGameAspect)
  {
    BOOST_ASSERT_MSG(ac_xGameAspect != nullptr , "DynamicAspect is not defined");
    if (ac_xGameAspect != nullptr) {
      // Static elements
      ac_xGameAspect->mf_xGetStaticAspect()->mp_DefineScenes();
      ac_xGameAspect->mf_xGetStaticAspect()->mp_DefineTriggers();
      ac_xGameAspect->mf_xGetStaticAspect()->mp_DefineTransientData();

      mc_xCSceneCollection = std::static_pointer_cast<const isaac::CSceneCollection>(ac_xGameAspect->mf_xGetStaticAspect());
      mc_xTransientData = std::static_pointer_cast<const isaac::CTransientDataCollection>(ac_xGameAspect->mf_xGetStaticAspect());

      //Dynamic elemens
      ac_xGameAspect->mp_DefineScenesTransitions();
      ac_xGameAspect->mp_DefineInitialScene();

      mc_xTransitionCollection = std::static_pointer_cast<const isaac::CTransitionCollection>(ac_xGameAspect);
      mc_xInitialScene = ac_xGameAspect->mp_GetInitialScene();
    }
  }

  CGame::~CGame()
  {
  }
}