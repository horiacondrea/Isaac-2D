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
#include <TriggerCollection.h>
#include <TransientDataCollection.h>
#include "ITrigger.h"
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  typedef std::shared_ptr< sf::RenderWindow > RenderWindow;

  class EXPORT_API IProcessingElement
  {
  public:

    /*!                 
    en_Permanent      - actie while the Scene is active
    en_Continuous     - needs a trigger start and stop
    en_OneTimeProcess - when the start triggerd will get disturbed this process
                        will run one time
    */
    enum ProcessType
    {
      en_Permanent,
      en_PermanentWithStop,
      en_Continuous,
      en_OneTimeProcess,
      en_UnknowProcess
    };

    /*!
    In this method you do the initialization of the proces. This method is called
    before the starting of the process
    Return value : void
    Arguments    : SFML Render Window [std::shared_ptr< sf::RenderWindow >]
                 : Transient Data Collection
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
    */
    virtual void mp_InitProcess(RenderWindow av_xMainWindow, TransientDataCollection& av_xTransietData) = 0;

    /*!
    Init all the needed defined triggers. This method is called before the starting of
    the process, right after the init
    Return value : void
    Arguments    : Global Trigger Collection [std::shared_ptr<isaac::CTriggerCollection>]
                   Triggers that are defined in the dynamic aspect
                 : Local Trigger Collection [std::shared_ptr<isaac::CTriggerCollection>]
                   Triggers that are defined in the dynamic scene
    */
    virtual void mp_InitTriggers(TriggerCollection& ac_xGlobalTriggers, const TriggerCollection& ac_xLocalTriggers) = 0;

    /*!
    Do the process logic. This method is called in a loop while the process is active
    Return value : void
    Arguments    : SFML Render Window [std::shared_ptr< sf::RenderWindow >]
                 : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
                 : SFML Event [sf::Event]
                 : reference bool, must be set to true before you decide to close
                   the window. See examples on horiacondrea.com about how to use
                   this parameter in the right way.
    */
    virtual void mp_UpdateScene(RenderWindow av_xMainWindow, TransientDataCollection& av_xTransietData, sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed) = 0;

    /*!
    Draw what ever you need on the stage. This method is called in a loop while the 
    process is active
    Return value : void
    Arguments    : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
    */
    virtual void mp_DrawScene(RenderWindow av_xMainWindow) const = 0;

    /*!
    Release(reset or delete) what ever you need. his method is called right before
    the stoping of the process
    Return value : void
    Arguments    : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
                 : name of the last trigger that was called
    */
    virtual void mp_Release(TransientDataCollection& av_xTransietData, std::string ac_szTriggerName) = 0;

    /*!
    Define a start triger for the process (if it is the case, some processes
    don't need start triggers)
    Return value : void
    Arguments    : The defined start trigger for the process     
    */
    void mp_addStartTrigger(Trigger& ac_xStartTrigger) const
    {
      if (mt_ProcessType != en_Permanent && mt_ProcessType != en_PermanentWithStop)
      {
        mv_xStartTriggers->mp_AddTrigger(ac_xStartTrigger);
      }
      else
      {
        // A permanent process can't have start/stop triggers
        // A permanent with stop process can't have start triggers
      }
    }

    /*!
    Define a stop triger for the process (if it is the case, some processes 
    don't need stop triggers)
    Return value : void
    Arguments    : The defined start trigger for the process     
    */
    void mp_addStopTrigger(Trigger& ac_xStopTrigger) const
    {
      if (mt_ProcessType != en_Permanent)
      {
        mv_xStopTriggers->mp_AddTrigger(ac_xStopTrigger);
      }
      else
      {
        // A permanent process can't have start/stop triggers
      }
    }

    /*!
    Return the defined process type
    Return value : The Process Type [ProcessType]
    Arguments    : none
    */
    virtual ProcessType mf_nGetProcessType() const
    {
      return mt_ProcessType;
    }

    /*!
    Return the name of the process
    Return value : name of the process [std::string]
    Arguments    : none
    */
    virtual std::string mf_szGetPEIdentifier() const
    {
      return mc_szProcessElementIdentifier;
    }

    /*!
    Return value : true if process is running, false otherwise [bool]
    Arguments    : none
    */
    virtual bool mf_bIsActive() const
    {
      return mv_bIsActive;
    }

    /*!
    Return all start triggers avialalble for this process
    Return value : all start triggers [TriggerCollection]
    Arguments    : none
    */
    virtual const TriggerCollection& mf_xGetStartTriggers() const
    {
      return mv_xStartTriggers;
    }

    /*!
    Return all stop triggers avialalble for this process
    Return value : all stop triggers [TriggerCollection]
    Arguments    : none
    */
    virtual const TriggerCollection& mf_xGetStopTriggers() const
    {
      return mv_xStopTriggers;
    }

    /*!
    Return 
    Return value : all stop triggers [TriggerCollection]
    Arguments    : none
    */
    virtual void mp_CheckTriggers(std::string& av_szNewPEActivated, sf::Event event) const
    {
      switch (mt_ProcessType)
      {
      case IProcessingElement::en_Permanent:
      {
        mv_bIsActive = true;
      }
        break;
      case IProcessingElement::en_PermanentWithStop:
      {
        mv_bIsActive = true;
        if (mv_bIsActive)
        {
          for (const auto & item : mv_xStopTriggers->mf_mapGetRawMap())
          {
            if (item.second->mf_bCheckTrigger(event))
            {
              mv_bIsActive = false;
            }
          }
        }
      }
        break;
      case IProcessingElement::en_Continuous:
      {
        if (mv_bIsActive)
        {
          for (const auto & item : mv_xStopTriggers->mf_mapGetRawMap())
          {
            if (item.second->mf_bCheckTrigger(event))
            {
              mv_bIsActive = false;
            }
          }
        }
        else
        {
          for (const auto & item : mv_xStartTriggers->mf_mapGetRawMap())
          {
            if (item.second->mf_bCheckTrigger(event))
            {
              mv_bIsActive = true;
              av_szNewPEActivated = mf_szGetPEIdentifier();
            }
          }
        }
      }
        break;
      case IProcessingElement::en_OneTimeProcess:
      {
      }
        break;
      case IProcessingElement::en_UnknowProcess:
        break;
      default:
        break;
      }
    }

    void mp_ResetProcess() const
    {
      if (mt_ProcessType != ProcessType::en_Permanent &&
        mt_ProcessType != ProcessType::en_PermanentWithStop)
      {
        mv_bIsActive = false;
      }
    }

    virtual ~IProcessingElement()
    {
    }

  protected:
    IProcessingElement(ProcessType at_ProcessType, std::string ac_szProcessElementIdentifier) :
      mt_ProcessType(at_ProcessType),
      mc_szProcessElementIdentifier(ac_szProcessElementIdentifier)
    {
      if (mt_ProcessType == ProcessType::en_Permanent)

      {
        mv_bIsActive = true;
      }
      else if (mt_ProcessType == ProcessType::en_PermanentWithStop)
      {
        mv_bIsActive = true;
        mv_xStopTriggers = std::make_shared<CTriggerCollection>();
      }
      else
      {
        mv_xStartTriggers = std::make_shared<CTriggerCollection>();
        mv_xStopTriggers = std::make_shared<CTriggerCollection>();
        mv_bIsActive = false;
        mv_bHasOneTimeRun = false;
      }
    }

    ProcessType mt_ProcessType;

    std::string mc_szProcessElementIdentifier;

    mutable bool mv_bIsActive;
    bool mv_bHasOneTimeRun;

    mutable TriggerCollection mv_xStartTriggers;
    mutable TriggerCollection mv_xStopTriggers;

  };

  typedef std::shared_ptr< const isaac::IProcessingElement > ProcessingElement;
}