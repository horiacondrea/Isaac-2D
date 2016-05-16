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

#pragma once

#include <IProcessingElement.h>
namespace Test {

  class PETwo : public isaac::IProcessingElement
  {
  public:
    PETwo(isaac::IProcessingElement::ProcessType ac_enumPEType,
      std::string ac_szSceneName);

    void mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
      std::shared_ptr<const isaac::CTransientDataCollection>& ac_xTransientData);

    void mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>& ac_xGlobalTriggersColl,
      const std::shared_ptr<isaac::CTriggerCollection>& ac_xLoacalTriggersColl);

    void mp_UpdateScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
      std::shared_ptr<const isaac::CTransientDataCollection>& ac_xTransientData,
      sf::Event av_eventSFMLEvent,
      bool& av_bReturnedBool_WindowClosed);

    void mp_DrawScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const;

    void mp_Release(std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName);

    ~PETwo();
  };

}