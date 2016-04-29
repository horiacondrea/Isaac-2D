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
#include <boost\assert.hpp>
#include <SFML/Graphics.hpp>
#include <TriggerCollection.h>
#include <TransientDataCollection.h>
#include <memory>
#include "defines.h"


namespace isaac
{
  typedef std::shared_ptr< sf::RenderWindow > RenderWindow;

  class EXPORT_API IScene
  {
  public:
    typedef std::shared_ptr< const isaac::IScene > Scene;

    virtual void mp_InitScene(RenderWindow av_xMainWindow, TransientDataCollection& av_xTransientData) = 0;

    virtual void mp_InitTriggers(TriggerCollection& av_xTriggerCollection) = 0;

    virtual void mp_UpdateScene(RenderWindow av_xMainWindow, TransientDataCollection& av_xTransientData,
      sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed) = 0;

    virtual void mp_DrawScene(RenderWindow av_xMainWindow) const = 0;

    virtual void mp_Release(TransientDataCollection& av_xTransientData, std::string ac_szTriggerName) = 0;

    virtual bool mp_bIsDynamicScene() const = 0;

    virtual std::string mf_szGetSceneName() const
    {
      return mc_szSceneName;
    }

    virtual void mp_SetFatherScene(const Scene ac_xFatherScene, const bool& ac_bIsActive = true) const
    {
      BOOST_ASSERT_MSG(ac_xFatherScene != nullptr, "Father Scene is null");
      if (ac_xFatherScene != nullptr)
        mv_xFatherScene = ac_xFatherScene;
      mv_bIsFatherSceneActive = ac_bIsActive;
    }

    virtual Scene mf_xGetFatherScene() const
    {
      return mv_xFatherScene;
    }

    virtual bool mf_bIsSubScene() const
    {
      if (mv_xFatherScene == nullptr)
      {
        return false;
      }
      return true;
    }

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