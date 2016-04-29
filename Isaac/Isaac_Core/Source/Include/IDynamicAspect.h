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
#include "IStaticAspect.h"
#include <TransitionCollection.h>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  /*!
   IDynamicAspect is probably one of the most important interfaces from this
   namespace. You will for sure have a class that will inherit this interfaces
   in you game, in order to define yout game transitions, your game transient
   data and the initial Scene of the game.
   */
  class EXPORT_API IDynamicAspect : public isaac::CTransitionCollection
  {
    // Public Methods
  public:

    /*!
    All the transitions between scenes need to by defined in this method
    Return value : void
    Arguments    : none
    */
    virtual void mp_DefineScenesTransitions() const = 0;

    /*!
    Initial scene name should be defined in this method
    Return value : void
    Arguments    : none
    */
    virtual void mp_DefineInitialScene() const = 0;

    /*!
    Rettun the StaticAspect object as a shared_ptr
    Return value : void
    Arguments    : none
    */
    virtual const StaticAspect& mf_xGetStaticAspect() const
    {
      return mv_xStaticAspect;
    }

    /*!
    This method is used to insert the Static Aspect in the Dynamic one
    Return value : void
    Arguments    : StaticAspect [std::shared_ptr< const isaac::IStaticAspect >]
    */
    virtual void mp_InsertStaticAspect(const StaticAspect& ac_xStaticAspect)
    {
      BOOST_ASSERT_MSG(ac_xStaticAspect != nullptr, "Static Aspect is null");
      if (ac_xStaticAspect != nullptr)
        mv_xStaticAspect = ac_xStaticAspect;
    }

    /*!
    Returnes the initial scene as a smart IScene object
    Return value : InitialScene [std::shared_ptr< const isaac::IScene >]
    Arguments    : none
    */
    virtual const Scene& mp_GetInitialScene() const
    {
      return mv_pInitialScene;
    }

    virtual ~IDynamicAspect()
    {
      ;
    }

    // Protected member variables
  protected:
    /*!
    Utility method that return a smart Transition
    Return value : Transition [std::shared_ptr<const isaac::CTransition>]
    Arguments    : name of the source scene
                 : name of the trigger that has to be disturbed in order
                   to move to the destination scene
                 : name of the destination scene
    */
    const Transition mf_xDefineTransition(std::string ac_szSourceSceneIdentifier,
      std::string ac_szTriggerIdentifier,
      std::string ac_szDestinationSceneIdentifier) const
    {
      return std::make_shared<isaac::CTransition>(mv_xStaticAspect->mf_xGetSceneByName(ac_szSourceSceneIdentifier),
        mv_xStaticAspect->mf_xGetTriggerByName(ac_szTriggerIdentifier),
        mv_xStaticAspect->mf_xGetSceneByName(ac_szDestinationSceneIdentifier));
    }

    /*!
    Utility method for defining an initial scene.
    Return value : InitialScene [std::shared_ptr< const isaac::IScene >]
    Arguments    : name of the Scene that will be the iniital scene
    */
    Scene mf_xDefineInitialScene(std::string ac_szInitialSceneIdentifier) const
    {
      return mv_xStaticAspect->mf_xGetSceneByName(ac_szInitialSceneIdentifier);
    }

  protected:
    StaticAspect mv_xStaticAspect;
    mutable Scene mv_pInitialScene;
  };

  typedef std::shared_ptr< const isaac::IDynamicAspect > DynamicAspect;
}