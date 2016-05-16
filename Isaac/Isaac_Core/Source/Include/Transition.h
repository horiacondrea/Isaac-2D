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
#include <IScene.h>
#include <ITrigger.h>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  class EXPORT_API CTransition
  {
  protected:
    const Scene mc_xSourceScene;
    const Trigger mc_xTrigger;
    const Scene mc_xDestinationScene;
  public:

    CTransition(const Scene& ac_xSourceScene, 
                const Trigger& ac_xTrigger, 
                const Scene& ac_xDestinationScene) :
      mc_xSourceScene(ac_xSourceScene) ,
      mc_xTrigger(ac_xTrigger) ,
      mc_xDestinationScene(ac_xDestinationScene)
    {
      BOOST_ASSERT_MSG(mc_xSourceScene != nullptr, "Source Scene is null");
      BOOST_ASSERT_MSG(mc_xTrigger != nullptr, "Trigger is null");
      BOOST_ASSERT_MSG(mc_xDestinationScene != nullptr, "Destination Scene is null");
    }

    /*!
    Get the Source Scene for the current transition
    */
    const Scene& mf_xGetSourceScene() const
    { 
      return mc_xSourceScene;
    }

    /*!
    Get the avilalbe Trigger for the current transition
    */
    const Trigger& mf_xGetTrigger() const
    {
      return mc_xTrigger;
    }

    /*!
    Get the Destination Scene for the current transition
    */
    const Scene& mf_xGetDestinationScene() const
    {
      return mc_xDestinationScene;
    }

    /*!
    Check the Trigger for the avilable transition
    */
    const bool mf_bCheckTransition(sf::Event event) const
    {
      return mc_xTrigger->mf_bCheckTrigger(event);
    }

    virtual ~CTransition()
    {
    }
  };

  typedef std::shared_ptr< const isaac::CTransition > Transition;
}