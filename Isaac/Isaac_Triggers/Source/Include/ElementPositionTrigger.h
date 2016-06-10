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
#pragma once
#include <ITrigger.h>
#include "SFML/Graphics.hpp"
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  class EXPORT_API CElementPositionTrigger : public isaac::ITrigger
  {
  public:
    struct PositionProp
    {
      Signs mc_enumPosition;
      Axis mc_enumAxis;
      double mc_dfPositionValue;
    };

  private:

    mutable PositionProp mv_PositionProp;
    mutable sf::Transformable* mv_pShape;

    const bool mp_CalculateTrigger() const;

  public:
    CElementPositionTrigger(std::string ac_szTriggerName);
    virtual ~CElementPositionTrigger();

    void mp_InitTrigger(sf::Transformable* ac_pShape, const PositionProp& ac_PositionProp ) const;

    const bool mf_bCheckTrigger(sf::Event) const;

  };

}