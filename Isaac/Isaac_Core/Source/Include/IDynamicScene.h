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
#include <ProcElemCollection.h>
#include "IScene.h"
#include <memory>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  class EXPORT_API IDynamicScene : public isaac::IScene,
    public isaac::CProcElemCollection
  {
  public:
    
    /*!
    All the processes are going to be defined inside this method
    Return value : void
    Arguments    : none
    */
    virtual void mp_DefineProcess() const = 0;

    /*!
    Init all the defined processes
    Return value : void
    Arguments    : SFML Render Window [std::shared_ptr< sf::RenderWindow >]
                 : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
    */
    virtual void mp_InitScene(RenderWindow av_xMainWindow, TransientDataCollection &ac_xTransientData)
    {
      BOOST_ASSERT_MSG(av_xMainWindow != nullptr, "Main Window is NULL");
      BOOST_ASSERT_MSG(ac_xTransientData != nullptr, "Transient Data is NULL");
      if (mv_mapSmartCollection.size() > 0)
      {
        for (const auto& item : mv_mapSmartCollection)
        {
          if (item.second->mf_bIsActive())
          {
            const auto & lc_xProcess = std::const_pointer_cast<isaac::IProcessingElement>(item.second);

            BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
            if (lc_xProcess != nullptr)
            {
              lc_xProcess->mp_InitProcess(av_xMainWindow, ac_xTransientData);
            }
          }
        }
      }
    }

    /*!
    Init all the defined triggers
    Return value : void
    Arguments    : Trigger Collection [std::shared_ptr<isaac::CTriggerCollection>]
    */
    virtual void mp_InitTriggers(TriggerCollection& ac_xGlobalTriggers)
    {
      BOOST_ASSERT_MSG(ac_xGlobalTriggers != nullptr, "GlobalTriggers is NULL");

      if (mv_mapSmartCollection.size() > 0)
      {
        for (const auto& item : mv_mapSmartCollection)
        {
          if (item.second->mf_bIsActive())
          {
            const auto & lc_xProcess = std::const_pointer_cast<isaac::IProcessingElement>(item.second);
            if (lc_xProcess != nullptr)
            {
              const auto& lc_xLocalTriggers = std::const_pointer_cast<isaac::CTriggerCollection>(mf_xGetAllTriggers());
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

    /*!
    Update all the defined processes
    Return value : void
    Arguments    : SFML Render Window [std::shared_ptr< sf::RenderWindow >]
                 : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
                 : SFML Event [sf::Event]
                 : reference bool, must be set to true before you decide to close
                   the window. See examples on horiacondrea.com about how to use
                   this parameter in the right way.
    */
    virtual void mp_UpdateScene(RenderWindow av_xMainWindow, TransientDataCollection &ac_xTransientData, sf::Event av_eventSFMLEvent, bool& av_bReturnedBool_WindowClosed)
    {
      BOOST_ASSERT_MSG(av_xMainWindow != nullptr, "Main Window is NULL");
      BOOST_ASSERT_MSG(ac_xTransientData != nullptr, "Transient Data is NULL");
      bool lv_bReturnBool = false;
      if (mv_mapSmartCollection.size() > 0)
      {
        for (const auto& item : mv_mapSmartCollection)
        {
          if (item.second->mf_bIsActive())
          {
            const auto & lc_xProcess = std::const_pointer_cast<isaac::IProcessingElement>(item.second);

            BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
            if (lc_xProcess != nullptr)
            {
              lc_xProcess->mp_UpdateScene(av_xMainWindow, ac_xTransientData, av_eventSFMLEvent, av_bReturnedBool_WindowClosed);
              if (av_bReturnedBool_WindowClosed)
              {
                lv_bReturnBool = true;
              }
            }
          }
        }
      }

      av_bReturnedBool_WindowClosed = lv_bReturnBool;

      ProcessingElement lc_xNewProcElem = mf_bCheckAllProcElem(av_eventSFMLEvent);
      if (lc_xNewProcElem != nullptr)
      {
        const auto & lv_xNewProcess = std::const_pointer_cast<isaac::IProcessingElement>(lc_xNewProcElem);

        BOOST_ASSERT_MSG(lv_xNewProcess != nullptr, "Process is NULL");

        if (lv_xNewProcess != nullptr)
        {
          lv_xNewProcess->mp_InitProcess(av_xMainWindow, ac_xTransientData);
        }
      }
    }

    /*!
    Draw all the defined processes
    Return value : void
    Arguments    : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
    */
    virtual void mp_DrawScene(RenderWindow av_xMainWindow) const
    {
      BOOST_ASSERT_MSG(av_xMainWindow != nullptr, "Main Window is NULL");

      if (mv_mapSmartCollection.size() > 0)
      {
        for (const auto& item : mv_mapSmartCollection)
        {
          if (item.second->mf_bIsActive())
          {
            const auto & lc_xProcess = std::const_pointer_cast<isaac::IProcessingElement>(item.second);

            BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
            if (lc_xProcess != nullptr)
            {
              lc_xProcess->mp_DrawScene(av_xMainWindow);
            }
          }
        }
      }
    }

    /*!
    Release all the defined processes
    Return value : void
    Arguments    : Transient Data Collection 
                   [std::shared_ptr< const isaac::CTransientDataCollection >]
                 : name of the last trigger that was called
    */
    virtual void mp_Release(TransientDataCollection& av_xTransientData, std::string ac_szTriggerName)
    {
      if (mv_mapSmartCollection.size() > 0)
      {
        for (const auto& item : mv_mapSmartCollection)
        {
          if (item.second->mf_bIsActive())
          {
            const auto & lc_xProcess = std::const_pointer_cast<isaac::IProcessingElement>(item.second);

            BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
            if (lc_xProcess != nullptr)
            {
              lc_xProcess->mp_Release(av_xTransientData, ac_szTriggerName);
            }
          }
        }
      }
    }

    /*!
    Return true, because this is a dynamic scene
    Return value : void
    Arguments    : none
    */
    virtual bool mp_bIsDynamicScene() const
    {
      return true;
    }

    /*!
    Resre all the defined processes
    Return value : void
    Arguments    : none
    */
    virtual void mp_ResetProcessingElements() const
    {
      if (mv_mapSmartCollection.size() > 0)
      {
        for (const auto& item : mv_mapSmartCollection)
        {
          if (item.second->mf_bIsActive())
          {
            const auto & lc_xProcess = std::const_pointer_cast<isaac::IProcessingElement>(item.second);

            BOOST_ASSERT_MSG(lc_xProcess != nullptr, "Process is NULL");
            if (lc_xProcess != nullptr)
            {
              lc_xProcess->mp_ResetProcess();
            }
          }
        }
      }
    }

    virtual ~IDynamicScene()
    {
    }

  protected:
    IDynamicScene(std::string ac_szSceneName) : IScene(ac_szSceneName)
    {
      ;
    }

  private:
    /*!
    Check if a new processes has been triggered
    Return value : smart IProcessingElement object if a new process has been triggerd
                   nullptr if no new procees has been triggerd
    */
    ProcessingElement mf_bCheckAllProcElem(sf::Event event) const
    {
      std::string lc_szPEActivated;
      for (const auto& item : mv_mapSmartCollection)
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

  typedef std::shared_ptr< const isaac::IDynamicScene > DynamicScene;
}
