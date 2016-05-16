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

#include "PEOne.h"
#include <ElementPositionTrigger.h>
#include <iostream>

namespace Test {

  PEOne::PEOne(isaac::IProcessingElement::ProcessType ac_enumPEType,
    std::string ac_szSceneName) :
    isaac::IProcessingElement(ac_enumPEType, ac_szSceneName)
  {
    ;
  }

  void PEOne::mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
    std::shared_ptr<const isaac::CTransientDataCollection>& ac_xTransientData)
  {
    mv_xShape = std::make_shared<sf::ConvexShape>();

    mv_xShape->setPointCount(3);
    mv_xShape->setPoint(0, sf::Vector2f(0, 0));
    mv_xShape->setPoint(1, sf::Vector2f(0, 10));
    mv_xShape->setPoint(2, sf::Vector2f(25, 5));
    mv_xShape->setOutlineColor(sf::Color::Red);
    mv_xShape->setOutlineThickness(5);
    mv_xShape->setPosition(300, 300);

    std::cout << "PE one- Init" << std::endl;
  }

  void PEOne::mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>& ac_xGlobalTriggersColl,
    const std::shared_ptr<isaac::CTriggerCollection>& ac_xLoacalTriggersColl)
  {
    const std::shared_ptr<const isaac::ITrigger> lv_pTrigger = ac_xLoacalTriggersColl->mf_xGetTriggerByName(("tpe"));
    const std::shared_ptr<isaac::CElementPositionTrigger> lv_pPosition =
      std::const_pointer_cast<isaac::CElementPositionTrigger>(std::static_pointer_cast<const isaac::CElementPositionTrigger>(lv_pTrigger));

    lv_pPosition->mp_InitTrigger(mv_xShape.get(), 500);
  }

  void PEOne::mp_UpdateScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
    std::shared_ptr<const isaac::CTransientDataCollection>& ac_xTransientData,
    sf::Event av_eventSFMLEvent,
    bool& av_bReturnedBool_WindowClosed)
  {
    mv_xShape->move(1, 0);
  }

  void PEOne::mp_DrawScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const
  {
    ac_xMainWindow->draw(*mv_xShape);
  }

  void PEOne::mp_Release(std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName)
  {

  }

  PEOne::~PEOne()
  {
  }
}