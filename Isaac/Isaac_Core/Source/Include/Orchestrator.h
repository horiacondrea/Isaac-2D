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

/*!                          
In the Core namespace you will find the most important components, this
components are directly implicated in the behavior that your game will
have.
*/
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
    std::shared_ptr< const IScene > mc_xInitialScene;
    std::shared_ptr< const CSceneCollection > mc_xCSceneCollection;
    std::shared_ptr< const CTransitionCollection > mc_xTransitionCollection;

    std::shared_ptr< const IScene > mc_xCurrentScene;

    mutable bool mv_bIsThisFirstTimeHere;
    mutable std::shared_ptr< CTriggerCollection > mv_xTriggersPerScene;
    mutable std::map<std::string, const bool> mv_mapDynamicMapMirror;
    std::string mv_szLastTriggerName;

  public:

    // Public Methods //

    // Constructor
    COrchestrator(std::shared_ptr< const IScene >& ac_xInitialScene,
                  std::shared_ptr< const CSceneCollection >& ac_xCSceneCollection,
                  std::shared_ptr< const CTransitionCollection >& ac_xTransitionCollection);

    // D-tor
    //// We are not going to destroy anything, since we use only smart pointers.
    ~COrchestrator();

    /*!                        
    This method check the triggers that are available in the Active Scene
    and determine what Scene will be next. If the Initial Scene is the Active
    Scene this will be displayed.
    Also mf_pGetSceneToBeDisplayed will return a bool that will allow as to 
    see if any trigger has been disturbed.
    */
    std::pair< std::shared_ptr< const IScene >, std::string> mf_xGetSceneToBeDisplayed(bool& av_bHasAnyTriggerDisturbed, sf::Event av_Event);

    /*!                        
    GetTriggersPerScene returns the Triggers that are available  for the
    Active Scene, in order to init them in the Scene.
    */
    std::shared_ptr< CTriggerCollection >& mf_xGetTriggersPerScene() const;

    /*!
    Get Dynamic Scene Status will return true if for a specific Scene name the processes
    are defined and will return false if the processes are not defined
    */
    const bool mf_bGetDynamicSceneStatus(std::string ac_szDynamicSceneName) const;

  private:
    // Private Methods //
    /*!
    Organize dynamic Scenes in a map
    */
    void mp_OrganizeDynamicScenes() const;

  };

}