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
1.0      | hc       | Feb   2014 | Created
*/

//                             Headers
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <SFML/Graphics.hpp>
#include "Orchestrator.h"
#include <ITransientData.h>
#include <list>
/////////////////////////////////////////////////////////////////////////////

/*                             Core
/////////////////////////////////////////////////////////////////////////////
// In the Core namespace you will find the most important components, this
// components are directly implicated in the behavior that your game will
// have.
/////////////////////////////////////////////////////////////////////////////
*/
namespace Core
{
  /*                           CStateMachine
  /////////////////////////////////////////////////////////////////////////////
  // CStateMachine class check the feedback provided by the COrchestrator in
  // order to Update and Draw the required state. This class creates a hierarchy
  // of states, (if necesary for) that states that have a 'father' state 
  /////////////////////////////////////////////////////////////////////////////
  */
  class CStateMachine final
  {
    // Private variables //
    std::shared_ptr< sf::RenderWindow > mv_xMainWindow;
    std::shared_ptr< Core::COrchestrator > mv_xStateOrchestrator;
    std::shared_ptr< const Foundation::Interfaces::ITransientData > mc_xTransientData;
      
    std::shared_ptr< Foundation::Interfaces::IState > mv_xCurrentState;
    std::shared_ptr< Foundation::Interfaces::IState > mv_xPrevState;

    bool mv_bHasThisStateInit;
    std::list< std::pair<std::shared_ptr< Foundation::Interfaces::IState >, bool> > mv_mapHierarchyOfStates;

    std::string mv_szLastTriggerName;

  public:

    // Constructor
    CStateMachine( std::shared_ptr< sf::RenderWindow >& av_xMainWindow, 
                   std::shared_ptr< Core::COrchestrator >& av_xStateOrchetrator,
                   std::shared_ptr< const Foundation::Interfaces::ITransientData >& av_xTransientData);

    // D-tor
    // We are not going to destroy anything, since we use only smart pointers
    ~CStateMachine();

    /*                       mp_InitCurrentState
    /////////////////////////////////////////////////////////////////////////////
    // This method initialize the components that are necesary for the Current 
    // State to run and creates a hierarchy of states, (if necesary for) that 
    // states that have a 'father' state and initilize the hierarchy. 
    /////////////////////////////////////////////////////////////////////////////
    */
    void mp_InitCurrentState(sf::Event av_Event);

    /*                       mp_ActivateCurrentState
    /////////////////////////////////////////////////////////////////////////////
    // mp_ActivateCurrentState will draw the elements from the Current State on
    // the stage.
    /////////////////////////////////////////////////////////////////////////////
    */
    void mp_ActivateCurrentState(sf::Event av_Event);

  private:

    void mp_ReleseState(std::shared_ptr< Foundation::Interfaces::IState >&);
  };

}