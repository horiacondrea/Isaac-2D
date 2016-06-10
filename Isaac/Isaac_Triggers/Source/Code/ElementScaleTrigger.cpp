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
1.0      | hc       | June 2016| Created
*/
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#include <ElementScaleTrigger.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  CElementScaleTrigger::CElementScaleTrigger(std::string ac_szTriggerName) :
    isaac::ITrigger(ac_szTriggerName)
  {
    mv_ScaleProp = { isaac::Signs::en_UnknowPosition, sf::Vector2f(1, 1) };
  }

  void CElementScaleTrigger::mp_InitTrigger(sf::Transformable* ac_pShape, const ScaleProp& ac_ScaleProp) const
  {
    mv_pElement = ac_pShape;
    mv_ScaleProp = ac_ScaleProp;
  }

  const bool CElementScaleTrigger::mf_bCheckTrigger(sf::Event) const
  {
    const sf::Vector2f lc_Scale = mv_pElement->getScale();

    switch (mv_ScaleProp.mv_Signs)
    {
    case isaac::Signs::en_EqualWith:
    {
      if (lc_Scale.x == mv_ScaleProp.mv_ScaleXY.x && lc_Scale.y == mv_ScaleProp.mv_ScaleXY.y)
        return true;
      return false;
      break;
    }
    case isaac::Signs::en_GraterThen:
    {
      if (lc_Scale.x > mv_ScaleProp.mv_ScaleXY.x && lc_Scale.y > mv_ScaleProp.mv_ScaleXY.y)
        return true;
      return false;
      break;
    }
    case isaac::Signs::en_LessThen:
    {
      if (lc_Scale.x < mv_ScaleProp.mv_ScaleXY.x && lc_Scale.y < mv_ScaleProp.mv_ScaleXY.y)
        return true;
      return false;
      break;
    }
    case isaac::Signs::en_UnknowPosition:
      return false;
    default:
      break;
    }
  }

  CElementScaleTrigger::~CElementScaleTrigger()
  {
  }
}