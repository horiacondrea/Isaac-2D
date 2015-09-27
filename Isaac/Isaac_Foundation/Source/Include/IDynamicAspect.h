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
#include "IStaticAspect.h"
#include "BufferITransitionCollection.h"


namespace Foundation
{
  /*                              Interfaces
  /////////////////////////////////////////////////////////////////////////////
  // In the Interfaces namespace you will find the most important interfaces
  // used in the Framework. You can modify these files if you want, but first
  // make sure you understand how these works.
  /////////////////////////////////////////////////////////////////////////////
  */
  namespace Interfaces
  {
    /*                           IDynamicAspect
    /////////////////////////////////////////////////////////////////////////////
    // IDynamicAspect is probably one of the most important interfaces from this
    // namespace. You will for sure have a class that will inherit this interfaces
    // in you game, in order to define yout game transitions, your game transient
    // data and the initial state of the game.
    /////////////////////////////////////////////////////////////////////////////
    */
    class __declspec(dllexport) IDynamicAspect : public Foundation::BufferITransitionCollection

    {
      // Public Methods
    public:

      /* mp_Define_States_Transitions | mp_Define_Transient_Data | mp_Define_Initial_State
      /////////////////////////////////////////////////////////////////////////////////////////
      // These names says everything
      /////////////////////////////////////////////////////////////////////////////////////////
      */
      virtual void mp_Define_States_Transitions() const = 0;

      virtual void mp_Define_Initial_State() const = 0;

      // Protected member variables
    protected:
      std::shared_ptr<const Interfaces::IStaticAspect> mv_xStaticAspect;
      mutable std::shared_ptr<const Interfaces::IState> mv_pInitialState;

      const std::shared_ptr<const Foundation::CTransition> mf_xDefineTransition(const char* ac_szSourceStateIdentifier,
        const char* ac_szTriggerIdentifier,
        const char* ac_szDestinationStateIdentifier) const
      {
        return std::make_shared<Foundation::CTransition>(mv_xStaticAspect->mf_xGetStateByName(ac_szSourceStateIdentifier),
          mv_xStaticAspect->mf_xGetTriggerByName(ac_szTriggerIdentifier),
          mv_xStaticAspect->mf_xGetStateByName(ac_szDestinationStateIdentifier));
      }

      std::shared_ptr<const Interfaces::IState> mf_xDefineInitialState(const char* ac_szInitialStateIdentifier) const
      {
        return mv_xStaticAspect->mf_xGetStateByName(ac_szInitialStateIdentifier);
      }

      // Public Methods
    public:

      virtual const std::shared_ptr<const Interfaces::IStaticAspect>& mf_xGetStaticAspect() const
      {
        return mv_xStaticAspect;
      }

      virtual void mp_Insert_Static_Aspect(const std::shared_ptr<const Interfaces::IStaticAspect>& ac_xStaticAspect)
      {
        BOOST_ASSERT_MSG(ac_xStaticAspect != nullptr, "Static Aspect is null");
        if (ac_xStaticAspect != nullptr)
          mv_xStaticAspect = ac_xStaticAspect;
      }

      virtual const std::shared_ptr<const Interfaces::IState>& mp_GetInitialState() const
      {
        return mv_pInitialState;
      }

      virtual ~IDynamicAspect()
      {
        ;
      }


    };
  }
}