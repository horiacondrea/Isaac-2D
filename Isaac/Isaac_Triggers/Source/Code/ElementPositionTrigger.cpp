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

#include "..\Include\ElementPositionTrigger.h"

namespace Triggers
{

  CElementPositionTrigger::CElementPositionTrigger(const Position ac_enumPosition, const CString ac_szTriggerName) :
    mc_enumPosition(ac_enumPosition) ,
   Foundation::Interfaces::ITrigger(ac_szTriggerName)
  {
    mv_bWasThisTriggerInit = false;
  }


  CElementPositionTrigger::~CElementPositionTrigger()
  {
   
  }

  void CElementPositionTrigger::mp_InitTrigger( sf::Shape* ac_pShape,  double ac_dfPosition)
  {
    mc_pShape = ac_pShape;
    mc_dfPosition = ac_dfPosition;
    mv_bWasThisTriggerInit = true;
  }

  const bool CElementPositionTrigger::mp_CalculateTrigger() const
  {
    if (mv_bWasThisTriggerInit)
    {
      switch (mc_enumPosition)
      {
      case en_GraterThen:
      {
                          if (mc_pShape->getPosition().x > mc_dfPosition)
                          {
                            return true;
                          }
                          else
                          {
                            return false;
                          }
      }
        break;
      case en_LessThen:
      {
                        if (mc_pShape->getPosition().x < mc_dfPosition)
                        {
                          return true;
                        }
                        else
                        {
                          return false;
                        }
      }
      default:
        break;
      }
    }
    return false;
  }

  const bool CElementPositionTrigger::mf_bWas_This_Trigger_Disturbed(sf::Event) const
  {
    return mp_CalculateTrigger();
  }

}