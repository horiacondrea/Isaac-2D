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
#include "StateMachine.h"
#include "Orchestrator.h"
#include <IDynamicAspect.h>
#include <IStateCollection.h>
#include "common/defines.h"

/////////////////////////////////////////////////////////////////////////////

/*                                Core 
/////////////////////////////////////////////////////////////////////////////
// In the Core namespace you will find the most important components, this
// components are directly implicated in the behavior that your game will
// have.
/////////////////////////////////////////////////////////////////////////////
*/
namespace Core 
{
  /*                                CGame
  ////////////////////////////////////////////////////////////////////////////
  // This is the main class for this Framework. In CGame all the information
  // that you already define will gather here and it will spread towards
  // those componenets that are resposible for them.
  ////////////////////////////////////////////////////////////////////////////
  */
  class EXPORT_API CGame
  {
  public:

    /*                        mp_DefineGameAspect
    /////////////////////////////////////////////////////////////////////////
    // This methid will fill almost all the member variables in this class 
    // with data provided by you in the Static Aspect and Dynamic Aspect.
    /////////////////////////////////////////////////////////////////////////
    */
    void mp_DefineGameAspect(const std::shared_ptr<const Foundation::Interfaces::IDynamicAspect>& ac_xGameAspect);

    /*                              mp_Start
    /////////////////////////////////////////////////////////////////////////
    // mp_Start is the main method for your game, this method keep your window
    // alive, and it is responsabile for the MainLoop and is responsible for 
    // initializing the other two most important components : the StateMachine
    // and the Orchestrator
    /////////////////////////////////////////////////////////////////////////
    */
    void mp_Start(const char* ac_szGameTitle, const unsigned int &ac_nGameWidth, const unsigned int &ac_nGameHeigh);


    // This class is Singleton, so you can only have one 'instance'
    static CGame &instance()
    {
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

    /*                          mp_GameLoop
    /////////////////////////////////////////////////////////////////////////
    // The Game Loop will work as long as the window remain open
    /////////////////////////////////////////////////////////////////////////
    */
    void mp_GameLoop();

    // Private variables //
    std::shared_ptr< sf::RenderWindow >                                      mv_xMainWindow;
    std::shared_ptr< CStateMachine >                                         mv_xStateMachine;
    std::shared_ptr< COrchestrator >                                         mv_xStateOrchestrator;

    // Separate the game aspect in tiny elements in order to
    // be processed by other game components

    std::shared_ptr< const Foundation::Interfaces::IStateCollection >        mc_xStateCollection;
    std::shared_ptr< const Foundation::Interfaces::IState >                  mc_xInitialState;
    std::shared_ptr< const Foundation::Interfaces::ITransitionCollection >   mc_xTransitionCollection;
    std::shared_ptr< const Foundation::Interfaces::ITransientData >          mc_xTransientData;

  };

}