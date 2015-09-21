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
#include <ITriggerCollection.h>
#include <IState.h>
#include <IStateCollection.h>
#include <ITransitionCollection.h>
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
  /*                             COrchestrator
  /////////////////////////////////////////////////////////////////////////////
  // COrchestrator class analyzes the data the you provide in order to supply
  // StateMachine with consistent information regarding the Active State and
  // the Triggers that are available in the Active State.
  /////////////////////////////////////////////////////////////////////////////
  */
  class COrchestrator
  {
    // Private variables //
    std::shared_ptr< const Foundation::Interfaces::IState > mc_xInitialState;
    std::shared_ptr< const Foundation::Interfaces::IStateCollection > mc_xStateCollection;
    std::shared_ptr< const Foundation::Interfaces::ITransitionCollection > mc_xTransitionCollection;

    std::shared_ptr< const Foundation::Interfaces::IState > mc_xCurrentState;

    mutable bool mv_bIsThisFirstTimeHere;
    mutable std::shared_ptr< Foundation::Interfaces::ITriggerCollection > mv_xTriggersPerState;
    mutable std::map<const CString, const bool> mv_mapDynamicMapMirror;

  public:

    // Constructor
    COrchestrator(std::shared_ptr< const Foundation::Interfaces::IState >& ac_xInitialState,
                  std::shared_ptr< const Foundation::Interfaces::IStateCollection >& ac_xStateCollection,
                  std::shared_ptr< const Foundation::Interfaces::ITransitionCollection >& ac_xTransitionCollection);

    // D-tor
    //// We are not going to destroy anything, since we use only smart pointers.
    ~COrchestrator();

    /*                         mf_pGetStateToBeDisplayed
    /////////////////////////////////////////////////////////////////////////////
    // This method check the triggers that are available in the Active State
    // and determine what state will be next. If the Initial State is the Active
    // State this will be displayed.
    // Also mf_pGetStateToBeDisplayed will return a bool that will allow as to 
    // see if any trigger has been disturbed.
    /////////////////////////////////////////////////////////////////////////////
    */
    const std::shared_ptr< const Foundation::Interfaces::IState >& mf_xGetStateToBeDisplayed(bool& av_bHasAnyTriggerDisturbed, sf::Event av_Event);

    /*                         mf_pGetTriggersPerState
    /////////////////////////////////////////////////////////////////////////////
    // GetTriggersPerState returns the Triggers that are available  for the
    // Active State, in order to init them in the state.
    /////////////////////////////////////////////////////////////////////////////
    */
    std::shared_ptr< Foundation::Interfaces::ITriggerCollection >& mf_xGetTriggersPerState() const;

    const bool mf_bGetDynamicStateStatus(const CString ac_szDynamicStateName) const;

  private:

    void mp_OrganizeDynamicStates() const;

  };

}