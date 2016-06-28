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
#include "SceneOne.h"
#include <ITrigger.h>
#include <iostream>

namespace Test {

  SceneOne::SceneOne(std::string ac_szSceneName) :
    isaac::IStaticScene(ac_szSceneName)
  {
    ;
  }

  void SceneOne::mp_InitScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
    std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData)
  {
    mv_pRect = new sf::RectangleShape(sf::Vector2f(40, 40));

    std::cout << "Scene one - Init" << std::endl;
  }

  void SceneOne::mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>& ac_xGlobalTriggersColl)
  {
    const std::shared_ptr<const isaac::ITrigger> lv_pTrigger = ac_xGlobalTriggersColl->mf_xGetTriggerByName(("t1"));
    const std::shared_ptr<isaac::CElementPositionTrigger> lv_pPosition =
      std::const_pointer_cast<isaac::CElementPositionTrigger>(std::static_pointer_cast<const isaac::CElementPositionTrigger>(lv_pTrigger));

    //std::shared_ptr<Triggers::CElementPositionTrigger> lv_pPosition = ac_xGlobalTriggersColl->mf_xGetTriggerByNameAndType<Triggers::CElementPositionTrigger>(_T("t1"));

    isaac::CElementPositionTrigger::PositionProp prop = { isaac::Signs::en_GraterThen, isaac::Axis::en_X, 200.0 };

    lv_pPosition->mp_InitTrigger(mv_pRect, prop);
  }

  void SceneOne::mp_UpdateScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
    std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData,
    sf::Event av_eventSFMLEvent,
    bool& av_bReturnedBool_WindowClosed)
  {
    av_bReturnedBool_WindowClosed = false;

    const int speed = av_xTransientData->mf_xGetTransientData<const int>("speed");

    mv_pRect->move(speed, 0);
  }

  void SceneOne::mp_DrawScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow) const
  {
    av_xMainWindow->draw(*mv_pRect);
  }

  void SceneOne::mp_Release(std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName)
  {
    delete mv_pRect;
  }

  SceneOne::~SceneOne()
  {
  }
}