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
#include <SFML/Graphics.hpp>
#include "ITriggerCollection.h"
#include "ITransientData.h"
#include "BufferIPECollection.h"
#include "IState.h"
#include <memory>
#include "common/defines.h"

namespace Foundation
{
  /*!                              Interfaces
  * In the Interfaces namespace you will find the most important interfaces
  * used in the Framework. You can modify these files if you want, but first
  * make sure you understand how these works.
  */
  namespace Interfaces
  {
    class EXPORT_API IDynamicState : public Interfaces::IState,
      public Foundation::CBufferIPECollection
    {
    public:

      virtual void mp_DefineProcess() const = 0;

      virtual void mp_InitState(std::shared_ptr<sf::RenderWindow> av_xMainWindow, std::shared_ptr<const Interfaces::ITransientData>& ac_xTransientData)
      {
        BOOST_ASSERT_MSG(av_xMainWindow != nullptr, "Main Window is NULL");
        BOOST_ASSERT_MSG(ac_xTransientData != nullptr, "Transient Data is NULL");
        if (mp_GetSize() > 0)
        {
          for (const auto& item : *mf_mapGetRawMap())
          {
            if (item.second->mf_bIsActive())
            {
              const auto & lc_xProcess = std::const_pointer_cast<Interfaces::IProcessingElement>(item.second);

              BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
              if (lc_xProcess != nullptr)
              {
                lc_xProcess->mp_InitProcess(av_xMainWindow, ac_xTransientData);
              }
            }
          }
        }
      }

      virtual void mp_InitTriggers(std::shared_ptr<Interfaces::ITriggerCollection>& ac_xGlobalTriggers)
      {
        BOOST_ASSERT_MSG(ac_xGlobalTriggers != nullptr, "GlobalTriggers is NULL");

        if (mp_GetSize() > 0)
        {
          for (const auto& item : *mf_mapGetRawMap())
          {
            if (item.second->mf_bIsActive())
            {
              const auto & lc_xProcess = std::const_pointer_cast<Interfaces::IProcessingElement>(item.second);
              if (lc_xProcess != nullptr)
              {
                const auto& lc_xLocalTriggers = std::const_pointer_cast<Interfaces::ITriggerCollection>(mf_xGetAllTriggers());
                BOOST_ASSERT_MSG(lc_xLocalTriggers != nullptr, "LocalTriggers is NULL");
                if (lc_xLocalTriggers != nullptr)
                {
                  lc_xProcess->mp_InitTriggers(ac_xGlobalTriggers, lc_xLocalTriggers);
                }
              }
            }
          }
        }
      }

      virtual void mp_UpdateState(std::shared_ptr<sf::RenderWindow> av_xMainWindow, std::shared_ptr<const Interfaces::ITransientData>& ac_xTransientData,
        sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed)
      {
        BOOST_ASSERT_MSG(av_xMainWindow != nullptr, "Main Window is NULL");
        BOOST_ASSERT_MSG(ac_xTransientData != nullptr, "Transient Data is NULL");
        bool lv_bReturnBool = false;
        if (mp_GetSize() > 0)
        {
          for (const auto& item : *mf_mapGetRawMap())
          {
            if (item.second->mf_bIsActive())
            {
              const auto & lc_xProcess = std::const_pointer_cast<Interfaces::IProcessingElement>(item.second);

              BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
              if (lc_xProcess != nullptr)
              {
                lc_xProcess->mp_UpdateState(av_xMainWindow, ac_xTransientData, av_eventSFMLEvent, av_bReturnedBool_WindowClosed);
                if (av_bReturnedBool_WindowClosed)
                {
                  lv_bReturnBool = true;
                }
              }
            }
          }
        }

        av_bReturnedBool_WindowClosed = lv_bReturnBool;

        std::shared_ptr<const Interfaces::IProcessingElement> lc_xNewPE = mf_bCheckAllPE(av_eventSFMLEvent);
        if (lc_xNewPE != nullptr)
        {
          const auto & lv_xNewProcess = std::const_pointer_cast<Interfaces::IProcessingElement>(lc_xNewPE);

          BOOST_ASSERT_MSG(lv_xNewProcess != nullptr, "Process is NULL");

          if (lv_xNewProcess != nullptr)
          {
            lv_xNewProcess->mp_InitProcess(av_xMainWindow, ac_xTransientData);
          }
        }
      }

      virtual void mp_DrawState(std::shared_ptr<sf::RenderWindow> av_xMainWindow) const
      {
        BOOST_ASSERT_MSG(av_xMainWindow != nullptr, "Main Window is NULL");

        if (mp_GetSize() > 0)
        {
          for (const auto& item : *mf_mapGetRawMap())
          {
            if (item.second->mf_bIsActive())
            {
              const auto & lc_xProcess = std::const_pointer_cast<Interfaces::IProcessingElement>(item.second);

              BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
              if (lc_xProcess != nullptr)
              {
                lc_xProcess->mp_DrawState(av_xMainWindow);
              }
            }
          }
        }
      }

      virtual void mp_Release(std::shared_ptr<const Interfaces::ITransientData>& av_xTransientData, std::string ac_szTriggerName)
      {
        if (mp_GetSize() > 0)
        {
          for (const auto& item : *mf_mapGetRawMap())
          {
            if (item.second->mf_bIsActive())
            {
              const auto & lc_xProcess = std::const_pointer_cast<Interfaces::IProcessingElement>(item.second);

              BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
              if (lc_xProcess != nullptr)
              {
                lc_xProcess->mp_Release(av_xTransientData, ac_szTriggerName);
              }
            }
          }
        }
      }

      virtual bool mp_bIsDynamicState() const
      {
        return true;
      }

      virtual void mp_ResetProcessingElements() const
      {
        if (mp_GetSize() > 0)
        {
          for (const auto& item : *mf_mapGetRawMap())
          {
            if (item.second->mf_bIsActive())
            {
              const auto & lc_xProcess = std::const_pointer_cast<Interfaces::IProcessingElement>(item.second);

              BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
              if (lc_xProcess != nullptr)
              {
                lc_xProcess->mp_ResetProcess();
              }
            }
          }
        }
      }

      virtual ~IDynamicState()
      {
      }

    protected:
      IDynamicState(std::string ac_szStateName) : IState(ac_szStateName)
      {
        ;
      }

    private:
      std::shared_ptr<const Interfaces::IProcessingElement> mf_bCheckAllPE(sf::Event event) const
      {
        std::string lc_szPEActivated;
        for (const auto& item : *mf_mapGetRawMap())
        {
          item.second->mp_CheckTriggers(lc_szPEActivated, event);
          if (!lc_szPEActivated.empty())
          {
            return item.second;
          }
          return nullptr;
        }
      }

    };
  }
}