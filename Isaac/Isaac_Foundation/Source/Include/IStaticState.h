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
1.0      | hc       | April 2014 | Created
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "ITriggerCollection.h"
#include "ITransientData.h"
#include "IState.h"
#include <memory>
#include <common/defines.h>

namespace Foundation
{
  /*                               Interfaces
  /////////////////////////////////////////////////////////////////////////////
  // In the Interfaces namespace you will find the most important interfaces
  // used in the Framework. You can modify these files if you want, but first
  // make sure you understand how these works.
  /////////////////////////////////////////////////////////////////////////////
  */
  namespace Interfaces
  {
    class EXPORT_API IStaticState : public IState
    {
    public:

      virtual void mp_InitState(std::shared_ptr<sf::RenderWindow>, std::shared_ptr<const Interfaces::ITransientData>&) = 0;

      virtual void mp_InitTriggers(std::shared_ptr<Interfaces::ITriggerCollection>&) = 0;

      virtual void mp_UpdateState(std::shared_ptr<sf::RenderWindow>, std::shared_ptr<const Interfaces::ITransientData>&,
        sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed) = 0;

      virtual void mp_DrawState(std::shared_ptr<sf::RenderWindow>) const = 0;

      virtual void mp_Release(std::shared_ptr<const Interfaces::ITransientData>& av_xTransientData, const char* ac_szTriggerName) = 0;

      virtual bool mp_bIsDynamicState() const
      {
        return false;
      }

      virtual ~IStaticState()
      {
      }

    protected:
      IStaticState(const char* ac_szStateName) : IState(ac_szStateName)
      {
        ;
      }

    };
  }
}