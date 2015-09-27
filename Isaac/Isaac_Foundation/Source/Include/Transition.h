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
#include "IState.h"
#include "ITrigger.h"

namespace Foundation
{
  class __declspec(dllexport) CTransition
  {
  protected:
    const std::shared_ptr< const Interfaces::IState >     mc_xSourceState;
    const std::shared_ptr< const Interfaces::ITrigger>     mc_xTrigger;
    const std::shared_ptr< const Interfaces::IState >     mc_xDestinationState;
  public:

    CTransition(const std::shared_ptr< const Interfaces::IState >& ac_xSourceState, 
                const std::shared_ptr< const Interfaces::ITrigger >& ac_xTrigger, 
                const std::shared_ptr<const Interfaces::IState >& ac_xDestinationState) :
      mc_xSourceState(ac_xSourceState) ,
      mc_xTrigger(ac_xTrigger) ,
      mc_xDestinationState(ac_xDestinationState)
    {
      BOOST_ASSERT_MSG(mc_xSourceState != nullptr, "Source State is null");
      BOOST_ASSERT_MSG(mc_xTrigger != nullptr, "Trigger is null");
      BOOST_ASSERT_MSG(mc_xDestinationState != nullptr, "Destination State is null");
    }

    const std::shared_ptr< const Interfaces::IState >& mf_xGetSourceState() const
    { 
      return mc_xSourceState;
    }

    const std::shared_ptr <const Interfaces::ITrigger >& mf_xGetTrigger() const
    {
      return mc_xTrigger;
    }

    const std::shared_ptr< const Interfaces::IState >& mf_xGetDestinationState() const
    {
      return mc_xDestinationState;
    }

    const bool mf_bCheckTransition(sf::Event event) const
    {
      return mc_xTrigger->mf_bWas_This_Trigger_Disturbed(event);
    }

    virtual ~CTransition()
    {
    }
  };
}