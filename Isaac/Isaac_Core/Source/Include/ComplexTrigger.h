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
#include <TriggerCollection.h>
#include <ITrigger.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac {

  /*!
  A complex trigger is defined by at least one trigger. When all the triggers are
  returning TRUE the complex trigger will be disturbed, in other cases the complex
  trigger will retrurn FALSE
  */
  class EXPORT_API CComplexTrigger : public CTriggerCollection, public ITrigger
  {
  public:
    CComplexTrigger(std::string ac_szTriggerName);

    /*!
    Return the current status of the trigger

    Return value : True if the trigger condition was accomplished, false otherwise [bool]

    Arguments    :
    - SFML Event [sf::Event>]
    */
    const bool mf_bCheckTrigger(sf::Event event) const;

    ~CComplexTrigger();

  private:

  };
}