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
1.0      | hc       | June 2016 | Created
*/
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <ITrigger.h>
#include "SFML/Graphics.hpp"
#include <memory>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  /*!
  CElementMouseTrigger will help you if you need a trigger based on a
  mouse element event 
  */
  class EXPORT_API CElementMouseTrigger : public isaac::ITrigger
  {

  public:
    /*!
    Specify the mouse event type that the trigger it will going to check.
    */
    enum MouseTriggerType
    {
     en_LeftClick,
     en_RightClick,
     en_MidClick,
     en_RollOver,
     en_RollOut,
     en_Unknow
    };

    mutable sf::Shape* mv_xElement;
    mutable std::shared_ptr<sf::RenderWindow> mv_xMainWindow;
    mutable MouseTriggerType mv_enumType;
    mutable bool mv_bMouseRollOver;

  public:
    CElementMouseTrigger(std::string ac_szTriggerIdentifier);

    /*!
    Init the trigger with the element the render window variable and the type of event to be checked
    */
    void InitTrigger(sf::Shape* av_xElement, std::shared_ptr<sf::RenderWindow> av_xMainWindow, const MouseTriggerType& av_enumType) const;

    const bool mf_bCheckTrigger(sf::Event event) const;

    virtual ~CElementMouseTrigger();
  };

}