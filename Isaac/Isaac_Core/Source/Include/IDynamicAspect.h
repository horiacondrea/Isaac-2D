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
	*/
    virtual void mp_DefineScenesTransitions() const = 0;
	
	/*!
	Initial scene name should be defined in this method
	*/
    virtual void mp_DefineInitialScene() const = 0;

	/*!
	Rettun the StaticAspect object as a shared_ptr
	*/
	virtual const std::shared_ptr<const isaac::IStaticAspect>& mf_xGetStaticAspect() const
	{
		return mv_xStaticAspect;
	}

	/*!
	This method is used to insert the Static Aspect in the Dynamic one
	*/
	virtual void mp_InsertStaticAspect(const std::shared_ptr<const isaac::IStaticAspect>& ac_xStaticAspect)
	{
		BOOST_ASSERT_MSG(ac_xStaticAspect != nullptr, "Static Aspect is null");
		if (ac_xStaticAspect != nullptr)
			mv_xStaticAspect = ac_xStaticAspect;
	}

	/*!
	Returnes the initial scene as a smart IScene object
	*/
	virtual const std::shared_ptr<const isaac::IScene>& mp_GetInitialScene() const
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
	ac_szSourceSceneIdentifier - name of the source scene
	ac_szTriggerIdentifier     - name of the trigger that has to be disturbed in order
								 to move to the destination scene
	ac_szDestinationSceneIdentifier - name of the destination scene
	*/
    const std::shared_ptr<const isaac::CTransition> mf_xDefineTransition(std::string ac_szSourceSceneIdentifier,
      std::string ac_szTriggerIdentifier,
      std::string ac_szDestinationSceneIdentifier) const
    {
      return std::make_shared<isaac::CTransition>(mv_xStaticAspect->mf_xGetSceneByName(ac_szSourceSceneIdentifier),
        mv_xStaticAspect->mf_xGetTriggerByName(ac_szTriggerIdentifier),
        mv_xStaticAspect->mf_xGetSceneByName(ac_szDestinationSceneIdentifier));
    }

	/*!
	Utility method for defining an initial scene. Retuns a smart IScene object.
	ac_szInitialSceneIdentifier - name of the Scene that it will be the iniital scene.
	This name has to be avialabe in the scene collection.
	*/
    std::shared_ptr<const isaac::IScene> mf_xDefineInitialScene(std::string ac_szInitialSceneIdentifier) const
    {
      return mv_xStaticAspect->mf_xGetSceneByName(ac_szInitialSceneIdentifier);
    }

  private:
	  std::shared_ptr<const isaac::IStaticAspect> mv_xStaticAspect;
	  mutable std::shared_ptr<const isaac::IScene> mv_pInitialScene;
  };
}