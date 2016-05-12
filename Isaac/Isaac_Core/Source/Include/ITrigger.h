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
#include <list>
#include <boost/any.hpp>
#include <SFML/Graphics.hpp>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  class EXPORT_API ITrigger
  {
  protected:
    std::string mc_szTriggerName;

  public:
    ITrigger(std::string ac_szTriggerName) : mc_szTriggerName(ac_szTriggerName)
    {
      ;
    }

    const virtual bool mf_bWas_This_Trigger_Disturbed(sf::Event event) const = 0;

    std::string mf_szGetTriggerName() const
    {
      return mc_szTriggerName;
    }

    virtual ~ITrigger()
    {
      //delete mc_szTriggerName;
    }
  };

  typedef std::shared_ptr<const ITrigger> Trigger;
}