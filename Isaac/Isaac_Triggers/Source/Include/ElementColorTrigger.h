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
/////////////////////////////////////////////////////////////////////////////


namespace isaac {

  /*!
  CElementColorTrigger will help you if you need a trigger based on the 
  collor of an element.
  */
  class EXPORT_API CElementColorTrigger : public isaac::ITrigger
  {
  public:
    /*!
     Specify the place where the needed color it will be checked.  
    */
    enum ColorWhere
    {
      en_FillColor,
      en_OutlineColor,
      en_Unknow
    };

    /*!
    Structure defining the trigger properties.
    */
    struct ColorProp
    {
      ColorWhere mv_colorWere;
      sf::Color mv_Color;
    };

  private:
    mutable sf::Shape* mv_pElement;
    mutable ColorProp  mv_ColorProp;

  public:
    CElementColorTrigger(std::string ac_szTriggerName);

    /*!
    Init the trigger with the element and the wanted properties.
    */
    void mp_InitTrigger(sf::Shape* ac_pShape, const ColorProp& ac_ColorProp) const;

    const bool mf_bCheckTrigger(sf::Event) const override;

    virtual ~CElementColorTrigger();
  };
}

