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
#include "ElementColorTrigger.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  CElementColorTrigger::CElementColorTrigger(std::string ac_szTriggerName) :
    isaac::ITrigger(ac_szTriggerName)
  {
    mv_ColorProp = { ColorWhere::en_Unknow, sf::Color::Transparent };
  }

  void CElementColorTrigger::mp_InitTrigger(sf::Shape* ac_pShape, const ColorProp& ac_ColorProp) const
  {
    mv_pElement = ac_pShape;
    mv_ColorProp = ac_ColorProp;
  }

  const bool CElementColorTrigger::mf_bCheckTrigger(sf::Event) const
  {
    switch (mv_ColorProp.mv_colorWere)
    {
    case ColorWhere::en_FillColor:
    {
      const sf::Color lc_Color = mv_pElement->getFillColor();
      if (lc_Color == mv_ColorProp.mv_Color)
        return true;
      return false;
      break;
    }
    case ColorWhere::en_OutlineColor:
    {
      const sf::Color lc_Color = mv_pElement->getOutlineColor();
      if (lc_Color == mv_ColorProp.mv_Color)
        return true;
      return false;
      break;
    }
    case ColorWhere::en_Unknow:
      return false;
    default:
      break;
    }
  }

  CElementColorTrigger::~CElementColorTrigger()
  {
  }
}