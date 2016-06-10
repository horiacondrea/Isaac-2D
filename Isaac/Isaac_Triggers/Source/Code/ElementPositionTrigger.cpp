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
1.0      | hc       | March 2014 | Created
*/
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#include <ElementPositionTrigger.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  CElementPositionTrigger::CElementPositionTrigger(std::string ac_szTriggerName) :
   isaac::ITrigger(ac_szTriggerName),
   mv_PositionProp({ isaac::Signs::en_UnknowPosition, isaac::Axis::en_Unknow, 0.0 })
  {
  }


  CElementPositionTrigger::~CElementPositionTrigger()
  {
   
  }

  void CElementPositionTrigger::mp_InitTrigger(sf::Transformable* ac_pShape, const PositionProp& ac_PositionProp) const
  {
    mv_pShape = ac_pShape;
    mv_PositionProp = ac_PositionProp;
  }

  const bool CElementPositionTrigger::mp_CalculateTrigger() const
  {
    switch (mv_PositionProp.mc_enumPosition)
    {
    case en_GraterThen:
    {
      switch (mv_PositionProp.mc_enumAxis)
      {
      case en_X:
      {
        if (mv_pShape->getPosition().x > mv_PositionProp.mc_dfPositionValue)
          return true;
        else
          return false;
      }
      case en_Y:
      {
        if (mv_pShape->getPosition().y > mv_PositionProp.mc_dfPositionValue)
          return true;
        else
          return false;
      }
      case en_Unknow:
        return false;
      default:
        break;
      }
    }
    break;
    case en_LessThen:
    {
      switch (mv_PositionProp.mc_enumAxis)
      {
      case en_X:
      {
        if (mv_pShape->getPosition().x < mv_PositionProp.mc_dfPositionValue)
          return true;
        else
          return false;
      }
      case en_Y:
      {
        if (mv_pShape->getPosition().y < mv_PositionProp.mc_dfPositionValue)
          return true;
        else
          return false;
      }
      case en_Unknow:
        return false;
      default:
        break;
      }
    }
    case en_EqualWith:
    {
      switch (mv_PositionProp.mc_enumAxis)
      {
      case en_X:
      {
        if (mv_pShape->getPosition().x == mv_PositionProp.mc_dfPositionValue)
          return true;
        else
          return false;
      }
      case en_Y:
      {
        if (mv_pShape->getPosition().y == mv_PositionProp.mc_dfPositionValue)
          return true;
        else
          return false;
      }
      case en_Unknow:
        return false;
      default:
        break;
      }
    }
    default:
      break;
    }
    return false;
  }

  const bool CElementPositionTrigger::mf_bCheckTrigger(sf::Event) const
  {
    return mp_CalculateTrigger();
  }

}