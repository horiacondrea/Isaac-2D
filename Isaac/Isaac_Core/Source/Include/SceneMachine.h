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
#include <list>
/////////////////////////////////////////////////////////////////////////////

/*!                          
In the Core namespace you will find the most important components, this
components are directly implicated in the behavior that your game will
have.
*/
namespace isaac
{
  /*!                           
  CSceneMachine class check the feedback provided by the COrchestrator in
  order to Update and Draw the required Scene. This class creates a hierarchy
  of Scenes, (if necesary for) that Scenes that have a 'father' Scene 
  */
  class CSceneMachine final
  {
    // Private variables //
    RenderWindow mv_xMainWindow;
    Orchestrator mv_xSceneOrchestrator;
    TransientDataCollection mc_xTransientData;
      
    std::shared_ptr< isaac::IScene > mv_xCurrentScene;
    std::shared_ptr< isaac::IScene > mv_xPrevScene;

    bool mv_bHasThisSceneInit;
    std::list< std::pair<std::shared_ptr< isaac::IScene >, bool> > mv_mapHierarchyOfScenes;

    std::string mv_szLastTriggerName;

  public:

    // Constructor
    CSceneMachine( RenderWindow& av_xMainWindow, 
                   Orchestrator& av_xSceneOrchetrator,
                   TransientDataCollection& av_xTransientData);

    // D-tor
    // We are not going to destroy anything, since we use only smart pointers
    ~CSceneMachine();

    /*!                       
    This method initialize the components that are necesary for the Current 
    Scene to run and creates a hierarchy of Scenes, (if necesary for) that 
    Scenes that have a 'father' Scene and initilize the hierarchy. 
    */
    void mp_InitCurrentScene(sf::Event av_Event);

    /*!                       
    mp_ActivateCurrentScene will draw the elements from the Current Scene on
    the stage.
    */
    void mp_ActivateCurrentScene(sf::Event av_Event);

  private:
    
    /*!
    This method will release the sceene from the window, a call to the release method 
    defined in the scene will be done.
    */
    void mp_ReleseScene(std::shared_ptr< isaac::IScene >&);
  };

  typedef std::shared_ptr< CSceneMachine > SceneMachine;
}