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
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <SFML/Graphics.hpp>
#include "IScene.h"
#include <memory>
#include <defines.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  class EXPORT_API IStaticScene : public IScene
  {
  public:

    /*!
    In this method you do the initialization of the proces. This method is called
    before the starting of the scene

    Return value : void

    Arguments    : 
    - SFML Render Window [std::shared_ptr< sf::RenderWindow >]
    - Transient Data Collection [std::shared_ptr< const isaac::CTransientDataCollection >]
    */
    virtual void mp_InitScene(RenderWindow av_xMainWindow, TransientDataCollection& av_xTransientData) = 0;

    /*!
    Init all the needed defined triggers. This method is called before the starting of
    the scene, right after the init

    Return value : void

    Arguments    : 
    - Trigger Collection [std::shared_ptr<isaac::CTriggerCollection>]
    */
    virtual void mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>&) = 0;

    /*!
    Do the scene logic. This method is called in a loop while the scene is active

    Return value : void

    Arguments    : 
    - SFML Render Window [std::shared_ptr< sf::RenderWindow >]
    - Transient Data Collection [std::shared_ptr< const isaac::CTransientDataCollection >]
    - SFML Event [sf::Event]
    - reference bool, must be set to true before you decide to close
      the window. See examples on horiacondrea.com about how to use
      this parameter in the right way.
    */
    virtual void mp_UpdateScene(RenderWindow av_xMainWindow, TransientDataCollection& av_xTransientData,
      sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed) = 0;

    /*!
    Draw what ever you need on the scene. This method is called in a loop while the 
    scene is active

    Return value : void

    Arguments    : 
    - Transient Data Collection [std::shared_ptr< const isaac::CTransientDataCollection >]
    */
    virtual void mp_DrawScene(RenderWindow av_xMainWindow) const = 0;

    /*!
    Release(reset or delete) what ever you need. This method is called right before
    the final release of the scene

    Return value : void

    Arguments    : 
    - Transient Data Collection [std::shared_ptr< const isaac::CTransientDataCollection >]
    - Name of the last trigger that was called
    */
    virtual void mp_Release(TransientDataCollection& av_xTransientData, std::string ac_szTriggerName) = 0;

    /*!
    Return value : False

    Arguments    : none
    */
    virtual bool mp_bIsDynamicScene() const
    {
      return false;
    }

    virtual ~IStaticScene()
    {
    }

  protected:
    IStaticScene(std::string ac_szSceneName) : IScene(ac_szSceneName)
    {
      ;
    }

  };

  typedef std::shared_ptr< const isaac::IStaticScene > StaticScene;
}