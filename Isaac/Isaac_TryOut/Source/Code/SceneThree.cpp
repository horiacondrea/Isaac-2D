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
1.0      | hc       | August 2014 | Created
*/

#include "SceneThree.h"
#include <ElementMouseTrigger.h>
#include <iostream>

namespace Test {

  SceneThree::SceneThree(std::string ac_szSceneName) :
    isaac::IStaticScene(ac_szSceneName)
  {
    ;
  }

  void SceneThree::mp_InitScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
    std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData)
  {
    mv_xMainWindow = av_xMainWindow;
    mv_pCircle = std::make_shared<sf::CircleShape>(30);
    mv_pCircle->setPosition(300, 300);

    mv_pButton = new isaac::TextButton("Test Button", "C:\\Windows\\Fonts\\tahoma.ttf");
    mv_pButton->setPosition(20,20);

    mv_pBox = new sf::RectangleShape(sf::Vector2f(30, 30));
    mv_pCheck = new sf::RectangleShape(sf::Vector2f(10, 10));
    mv_pCheck->setFillColor(sf::Color::Red);

    mv_pCheckBox = new isaac::CheckBox(mv_pBox, mv_pCheck, false);
    mv_pCheckBox->setPosition(20, 200);

    std::cout << "Scene three - Init" << std::endl;
  }

  void SceneThree::mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>& ac_xGlobalTriggersColl)
  {
    const std::shared_ptr<const isaac::ITrigger> lv_pTrigger = ac_xGlobalTriggersColl->mf_xGetTriggerByName(("t3"));
    const std::shared_ptr<isaac::CElementMouseTrigger> lv_pClickTrigger =
      std::const_pointer_cast<isaac::CElementMouseTrigger>(std::static_pointer_cast<const isaac::CElementMouseTrigger>(lv_pTrigger));

    lv_pClickTrigger->InitTrigger(mv_pCircle.get(), mv_xMainWindow, isaac::CElementMouseTrigger::en_RollOut);
  }

  void SceneThree::mp_UpdateScene(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
    std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData,
    sf::Event av_eventSFMLEvent,
    bool& av_bReturnedBool_WindowClosed)
  {

    mv_pCheckBox->mp_Update(av_pMainWindow, av_eventSFMLEvent);
  }

  void SceneThree::mp_DrawScene(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const
  {
    av_pMainWindow->draw(*mv_pCircle);
    av_pMainWindow->draw(*mv_pButton);
    av_pMainWindow->draw(*mv_pCheckBox);
  }

  void SceneThree::mp_Release(std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName)
  {
    delete mv_pButton;
    delete mv_pBox;
    delete mv_pCheck;
    delete mv_pCheckBox;
  }

  SceneThree::~SceneThree()
  {
    
  }
}