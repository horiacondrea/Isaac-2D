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
#include <IScene.h>
#include <SceneCollection.h>
#include <TransitionCollection.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  /*!                            
  COrchestrator class analyzes the data the you provide in order to supply
  SceneMachine with consistent information regarding the Active Scene and
  the Triggers that are available in the Active Scene.
  */
  class COrchestrator
  {
    // Private variables //
    Scene mc_xInitialScene;
    SceneCollection mc_xCSceneCollection;
    TransitionCollection mc_xTransitionCollection;

    Scene mc_xCurrentScene;

    mutable bool mv_bIsThisFirstTimeHere;
    mutable TriggerCollection mv_xTriggersPerScene;
    mutable std::map<std::string, const bool> mv_mapDynamicMapMirror;
    std::string mv_szLastTriggerName;

  public:

    // Public Methods //

    // Constructor
    COrchestrator(Scene & ac_xInitialScene,
                  SceneCollection& ac_xCSceneCollection,
                  TransitionCollection& ac_xTransitionCollection);

    // D-tor
    //// We are not going to destroy anything, since we use only smart pointers.
    ~COrchestrator();

    /*!
    This method check the triggers that are available in the Active Scene
    and determine what Scene will be next. If the Initial Scene is the Active
    Scene this will be displayed.
    Also mf_pGetSceneToBeDisplayed will return a bool that will allow as to 
    see if any trigger has been disturbed.

    Return value : The Scene to be displayed next and the trigger name that was
                   disturbed last [ std::pair< Scene, std::string> ]. If no trigger 
                   was disturbed the string will contain "NoTrigger"

    Arguments    : 
    - Bool that indicates id a trigger was disturbed or not
    - SFML Event [sf::Event]
                   
    */
    std::pair< Scene, std::string> mf_xGetSceneToBeDisplayed(bool& av_bHasAnyTriggerDisturbed, sf::Event av_Event);

    /*!                        
    Returns the Triggers that are available  for the Active Scene, in order to 
    init them in the Scene.

    Return value : Trigger Collection

    Arguments    : none
    */
    std::shared_ptr< CTriggerCollection >& mf_xGetTriggersPerScene() const;

    /*!
    Get Dynamic Scene Status will return true if for a specific Scene name the processes
    are defined and will return false if the processes are not defined

    Return value : bool

    Arguments    : none
    */
    const bool mf_bGetDynamicSceneStatus(std::string ac_szDynamicSceneName) const;

  private:
    // Private Methods //
    /*!
    Organize dynamic Scenes in a map

    Return value : void

    Arguments    : none
    */
    void mp_OrganizeDynamicScenes() const;

  };
  typedef std::shared_ptr< COrchestrator > Orchestrator;
}