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

#pragma once
#include <SFML\Graphics.hpp>
#include "ITriggerCollection.h"
#include "ITransientData.h"
#include <memory>
#include <atlstr.h>

#ifdef DEBUG
#include <vld.h>
#endif


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
    class __declspec(dllexport) IState
    {
    public:

      virtual void mp_InitState(std::shared_ptr<sf::RenderWindow>, std::shared_ptr<const Interfaces::ITransientData>&) = 0;

      virtual void mp_InitTriggers(std::shared_ptr<Interfaces::ITriggerCollection>&) = 0;

      virtual void mp_UpdateState(std::shared_ptr<sf::RenderWindow>, std::shared_ptr<const Interfaces::ITransientData>&,
        sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed) = 0;

      virtual void mp_DrawState(std::shared_ptr<sf::RenderWindow>) const = 0;

      virtual void mp_Release() = 0;

      virtual bool mp_bIsDynamicState() const = 0;

      virtual const CString& mf_szGetStateName() const
      {
        return mc_szStateName;
      }

      virtual void mp_SetFatherState(const std::shared_ptr<const Interfaces::IState> ac_xFatherState, const bool& ac_bIsActive = true) const
      {
        BOOST_ASSERT_MSG(ac_xFatherState != nullptr, "Father State is null");
        if (ac_xFatherState != nullptr)
          mv_xFatherState = ac_xFatherState;
        mv_bIsFatherStateActive = ac_bIsActive;
      }

      virtual std::shared_ptr<const Interfaces::IState> mf_xGetFatherState() const
      {
        return mv_xFatherState;
      }

      virtual bool mf_bIsSubState() const
      {
        if (mv_xFatherState == nullptr)
        {
          return false;
        }
        return true;
      }

      virtual bool mf_bIsFatherStateActive() const
      {
        return mv_bIsFatherStateActive;
      }

      virtual ~IState()
      {

      }

    protected:

      IState(const CString ac_szStateName) : mc_szStateName(ac_szStateName)
      {
        
      }

      mutable std::shared_ptr<const Interfaces::IState> mv_xFatherState;
      mutable bool mv_bIsFatherStateActive;

      const CString mc_szStateName;
    };
  }
}