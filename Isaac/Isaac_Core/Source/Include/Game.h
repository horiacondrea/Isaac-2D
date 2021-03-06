//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                  
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
---------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | Feb   2014 | Created
*/                      
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <SFML/Graphics.hpp>
#include <SceneMachine.h>
#include <Orchestrator.h>
#include <IDynamicAspect.h>
#include "defines.h"

/////////////////////////////////////////////////////////////////////////////

namespace isaac 
{
  typedef std::shared_ptr< sf::RenderWindow > RenderWindow;

  /*!                               
   This is the main class for this Framework. In CGame all the information
   that you already define will gather here and it will spread towards
   those componenets that are resposible for them.
  */
  class EXPORT_API CGame
  {
  public:

    /*!                        
    This methid will fill almost all the member variables in this class 
    with data provided by you in the Static Aspect and Dynamic Aspect.

    Return value : void 

    Arguments:
    - DynamicAspect [std::shared_ptr< const isaac::IDynamicAspect]
    */
    void mp_DefineGameAspect(const DynamicAspect& ac_xGameAspect);

    /*!                              
    mp_Start is the main method for your game, this method keep your window
    alive, and it is responsabile for the MainLoop, initializing the other 
    two most important components : the SceneMachine and the Orchestrator
   
    Return value : void

    Arguments    : 
    - Window Title
    - Window Width
    - Window Heigh
    */
    void mp_Start(std::string ac_szGameTitle, const unsigned int &ac_nGameWidth, const unsigned int &ac_nGameHeigh);

    /*!
    This class is Singleton, so you can only have one 'instance'

    Return value : CGame 

    Arguments    : none
    */
    static CGame &instance() {

      static CGame sv_Game;
      return sv_Game;
    }

    // We are not going to destroy anything, since we use only smart pointers
    ~CGame();

  private:
    // Private Constructor
    CGame() 
    {
      ; 
    };

    // Private Methods //

    /*!                         
    The Game Loop will work as long as the window remain open

    Return value : void

    Arguments    : none
    */
    void mp_GameLoop();

    // Private variables //

    RenderWindow mv_xMainWindow;
    SceneMachine mv_xSceneMachine;
    Orchestrator mv_xSceneOrchestrator;

    // Separate the game aspect in tiny elements in order to
    // be processed by other game components

    SceneCollection         mc_xCSceneCollection;
    Scene                   mc_xInitialScene;
    TransitionCollection    mc_xTransitionCollection;
    TransientDataCollection mc_xTransientData;

  };

}