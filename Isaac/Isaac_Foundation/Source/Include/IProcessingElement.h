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

#pragma once
#include <SFML\Graphics.hpp>
#include "BufferITriggerCollection.h"
#include "ITransientData.h"
#include "ITrigger.h"

namespace Foundation
{
  /*                               Interfaces
  /////////////////////////////////////////////////////////////////////////////
  // In the Interfaces namespace you will find the most important interfaces
  // used in the Framework. You can modify these files if you want, but first
  // make sure you understand how these works.
  /////////////////////////////////////////////////////////////////////////////
  */
  namespace Interfaces
  {
    class __declspec(dllexport) IProcessingElement
    {
    public:

      /*                               ProcessType
      /////////////////////////////////////////////////////////////////////////////
      // en_Permanent - actie while the state is active
      // en_Continuous - needs a trigger start and stop
      // en_OneTimeProcess - when the start triggerd will get disturbed this process
      //                     will run one time
      /////////////////////////////////////////////////////////////////////////////
      */

      enum ProcessType
      {
        en_Permanent,
        en_PermanentWithStop,
        en_Continuous,
        en_OneTimeProcess,
        en_UnknowProcess
      };

      virtual void mp_InitProcess(std::shared_ptr<sf::RenderWindow>, std::shared_ptr<const Interfaces::ITransientData>&) = 0;

      virtual void mp_InitTriggers(std::shared_ptr<Interfaces::ITriggerCollection>& ac_xGlobalTriggers, std::shared_ptr<Interfaces::ITriggerCollection>& ac_xLocalTriggers) = 0;

      virtual void mp_UpdateState(std::shared_ptr<sf::RenderWindow>, std::shared_ptr<const Interfaces::ITransientData>&,
        sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed) = 0;

      virtual void mp_DrawState(std::shared_ptr<sf::RenderWindow>) const = 0;

      virtual void mp_Release(std::shared_ptr<const Interfaces::ITransientData>&, const char* ac_szTriggerName) = 0;

      void mp_addStartTrigger(std::shared_ptr<const Interfaces::ITrigger>& ac_xStartTrigger) const
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

      void mp_addStopTrigger(std::shared_ptr<const Interfaces::ITrigger>& ac_xStopTrigger) const
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

      virtual ProcessType mf_nGetProcessType() const
      {
        return mt_ProcessType;
      }

      virtual const char* mf_szGetPEIdentifier() const
      {
        return mc_szProcessElementIdentifier;
      }

      virtual bool mf_bIsActive() const
      {
        return mv_bIsActive;
      }

      virtual const std::shared_ptr<const Interfaces::ITriggerCollection>& mf_xGetStartTriggers() const
      {
        return mv_xStartTriggers;
      }

      virtual const std::shared_ptr<const Interfaces::ITriggerCollection>& mf_xGetStopTriggers() const
      {
        return mv_xStopTriggers;
      }

      virtual void mp_CheckTriggers(const char* av_szNewPEActivated, sf::Event event) const
      {
        switch (mt_ProcessType)
        {
        case Interfaces::IProcessingElement::en_Permanent:
        {
                                                           mv_bIsActive = true;
        }
          break;
        case Interfaces::IProcessingElement::en_PermanentWithStop:
        {
                                                                   mv_bIsActive = true;
                                                                   if (mv_bIsActive)
                                                                   {
                                                                     for (const auto & item : *mv_xStopTriggers->mf_mapGetRawMap())
                                                                     {
                                                                       if (item.second->mf_bWas_This_Trigger_Disturbed(event))
                                                                       {
                                                                         mv_bIsActive = false;
                                                                       }
                                                                     }
                                                                   }
        }
          break;
        case Interfaces::IProcessingElement::en_Continuous:
        {
                                                            if (mv_bIsActive)
                                                            {
                                                              for (const auto & item : *mv_xStopTriggers->mf_mapGetRawMap())
                                                              {
                                                                if (item.second->mf_bWas_This_Trigger_Disturbed(event))
                                                                {
                                                                  mv_bIsActive = false;
                                                                }
                                                              }
                                                            }
                                                            else
                                                            {
                                                              for (const auto & item : *mv_xStartTriggers->mf_mapGetRawMap())
                                                              {
                                                                if (item.second->mf_bWas_This_Trigger_Disturbed(event))
                                                                {
                                                                  mv_bIsActive = true;
                                                                  av_szNewPEActivated = mf_szGetPEIdentifier();
                                                                }
                                                              }
                                                            }
        }
          break;
        case Interfaces::IProcessingElement::en_OneTimeProcess:
        {
        }
          break;
        case Interfaces::IProcessingElement::en_UnknowProcess:
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
      IProcessingElement(ProcessType at_ProcessType, const char* ac_szProcessElementIdentifier) :
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
          mv_xStopTriggers = std::make_shared<Foundation::CBufferITriggerCollection>();
        }
        else
        {
          mv_xStartTriggers = std::make_shared<Foundation::CBufferITriggerCollection>();
          mv_xStopTriggers = std::make_shared<Foundation::CBufferITriggerCollection>();
          mv_bIsActive = false;
          mv_bHasOneTimeRun = false;
        }
      }

      ProcessType mt_ProcessType;

      const char* mc_szProcessElementIdentifier;

      mutable bool mv_bIsActive;
      bool mv_bHasOneTimeRun;

      mutable std::shared_ptr<const Interfaces::ITriggerCollection> mv_xStartTriggers;
      mutable std::shared_ptr<const Interfaces::ITriggerCollection> mv_xStopTriggers;

    };
  }
}