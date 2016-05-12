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
#include <boost\assert.hpp>
#include <SFML/Graphics.hpp>
#include <TriggerCollection.h>
#include <TransientDataCollection.h>
#include <memory>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  typedef std::shared_ptr< sf::RenderWindow > RenderWindow;

  class EXPORT_API IScene
  {
  public:
    typedef std::shared_ptr< const isaac::IScene > Scene;

    /*!
    In this method you do the initialization of the proces. This method is called
    before the starting of the scene
    Return value : void
    Arguments    : SFML Render Window [std::shared_ptr< sf::RenderWindow >]
                 : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
    */
    virtual void mp_InitScene(RenderWindow av_xMainWindow, TransientDataCollection& av_xTransientData) = 0;

    /*!
    Init all the needed defined triggers. This method is called before the starting of
    the scene, right after the init
    Return value : void
    Arguments    : Trigger Collection [std::shared_ptr<isaac::CTriggerCollection>]
    */
    virtual void mp_InitTriggers(TriggerCollection& av_xTriggerCollection) = 0;

    /*!
    Do the scene logic. This method is called in a loop while the scene is active
    Return value : void
    Arguments    : SFML Render Window [std::shared_ptr< sf::RenderWindow >]
                 : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
                 : SFML Event [sf::Event]
                 : reference bool, must be set to true before you decide to close
                   the window. See examples on horiacondrea.com about how to use
                   this parameter in the right way.
    */
    virtual void mp_UpdateScene(RenderWindow av_xMainWindow, TransientDataCollection& av_xTransientData,
      sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed) = 0;

    /*!
    Draw what ever you need on the scene. This method is called in a loop while the 
    scene is active
    Return value : void
    Arguments    : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
    */
    virtual void mp_DrawScene(RenderWindow av_xMainWindow) const = 0;

    /*!
    Release(reset or delete) what ever you need. This method is called right before
    the final release of the scene
    Return value : void
    Arguments    : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
                 : name of the last trigger that was called
    */
    virtual void mp_Release(TransientDataCollection& av_xTransientData, std::string ac_szTriggerName) = 0;

    /*!
    Return value : True if the current scene is dynamic false otherwise
    Arguments    : none
    */
    virtual bool mp_bIsDynamicScene() const = 0;

    /*!
    Return the name of the scene
    Return value : name of the scene [std::scene]
    Arguments    : none
    */
    virtual std::string mf_szGetSceneName() const
    {
      return mc_szSceneName;
    }

    /*!
    Set a father scene to the current scene. For more information about how is this
    affecting you game, please read the tutorials from horiacondrea.com
    Return value : void
    Arguments    : Father Scene [Scene]
                 : Activate or not the father scene [bool ; default = true]
    */
    virtual void mp_SetFatherScene(const Scene ac_xFatherScene, const bool& ac_bIsActive = true) const
    {
      BOOST_ASSERT_MSG(ac_xFatherScene != nullptr, "Father Scene is null");
      if (ac_xFatherScene != nullptr)
        mv_xFatherScene = ac_xFatherScene;
      mv_bIsFatherSceneActive = ac_bIsActive;
    }

    /*!
    Retun the father scene of the current scene
    Return value : Father scene [Scene], nullptr if the current scene doesn't have
                   a father scene
    Arguments    : none
    */
    virtual Scene mf_xGetFatherScene() const
    {
      return mv_xFatherScene;
    }

    /*!
    Return value : true if the current scene does have a father scene false otherwise
    Arguments    : none
    */
    virtual bool mf_bIsSubScene() const
    {
      if (mv_xFatherScene == nullptr)
      {
        return false;
      }
      return true;
    }

    /*!
    Return value : true if the current scene does have a father scene active false otherwise
    Arguments    : none
    */
    virtual bool mf_bIsFatherSceneActive() const
    {
      return mv_bIsFatherSceneActive;
    }

    virtual ~IScene()
    {

    }

  protected:

    IScene(std::string ac_szSceneName) : mc_szSceneName(ac_szSceneName)
    {

    }

    mutable Scene mv_xFatherScene;
    mutable bool mv_bIsFatherSceneActive;
    std::string mc_szSceneName;
  };

  typedef std::shared_ptr< const isaac::IScene > Scene;
  
}