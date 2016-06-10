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
Copyright @ 2016
Author Horatiu Condrea [ horiacondrea.com ]
Revision | Who      | Date       | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | June 2016 | Created
*/
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#include <ElementMouseTrigger.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  namespace {
    template <typename T>
    bool IsInBounds(const T& value, const T& low, const T& high) {
      return !(value < low) && !(high < value);
    }
  }

  CElementMouseTrigger::CElementMouseTrigger(std::string ac_szTriggerIdentifier) : isaac::ITrigger(ac_szTriggerIdentifier)
  {
    mv_bMouseRollOver = false;
  }

  void CElementMouseTrigger::InitTrigger(sf::Shape* av_xElement, std::shared_ptr<sf::RenderWindow> av_xMainWindow, const MouseTriggerType& av_enumType) const
  {
    mv_xElement = av_xElement;
    mv_xMainWindow = av_xMainWindow;
    mv_enumType = av_enumType;
  }

  const bool CElementMouseTrigger::mf_bCheckTrigger(sf::Event event) const
  {
    const int lc_nMouseX = sf::Mouse::getPosition(*mv_xMainWindow).x;
    const int lc_nMouseY = sf::Mouse::getPosition(*mv_xMainWindow).y;

    const float lc_dfShapeY = mv_xElement->getPosition().y;
    const float lc_dfShapeX = mv_xElement->getPosition().x;

    const float lc_dfShapeWidth = mv_xElement->getGlobalBounds().width;
    const float lc_dfShapeHeight = mv_xElement->getGlobalBounds().height;

    if (IsInBounds<float>(lc_nMouseX, lc_dfShapeX, lc_dfShapeX + lc_dfShapeWidth) &&
      IsInBounds<float>(lc_nMouseY, lc_dfShapeY, lc_dfShapeY + lc_dfShapeHeight)) {

      switch (mv_enumType)
      {
      case en_LeftClick:
      {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
          return true;
        return false;
        break;
      }
      case en_RightClick:
      {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
          return true;
        return false;
        break;
      }
      case en_MidClick:
      {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
          return true;
        return false;
        break;
      }
      case en_RollOver:
      {
       
        return true;
      }
      case en_RollOut:
      {
        mv_bMouseRollOver = true;
        break;
      }
      case en_Unknow:
        return false;
      default:
        break;
      }
    }
    else{
      if (mv_bMouseRollOver && mv_enumType == en_RollOut) {
        mv_bMouseRollOver = false;
        return true;
      }
    }

    return false;
  }

  CElementMouseTrigger::~CElementMouseTrigger()
  {
  }
}