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

#include "BufferIPECollection.h"
#include <boost/assert.hpp>

namespace Foundation
{

  CBufferIPECollection::CBufferIPECollection()
  {
    mv_mapSmartCollection = new std::map<const char*, const std::shared_ptr<const Interfaces::IProcessingElement>>();
  }

  const std::shared_ptr<const Interfaces::IProcessingElement>& CBufferIPECollection::mf_xGetPEByName(const char* ac_szPEIdentifier) const
  {
    BOOST_ASSERT_MSG(ac_szPEIdentifier != nullptr, "Empty string provided");
    if (ac_szPEIdentifier != nullptr)
    {
      const auto& it = mv_mapSmartCollection->find(ac_szPEIdentifier);
      return it->second;
    }
  }

  void CBufferIPECollection::mp_AddProcessingElement(const std::shared_ptr<const Interfaces::IProcessingElement>& ac_xProcessingElement) const
  {
    BOOST_ASSERT_MSG(ac_xProcessingElement != nullptr, "Process to add is null");
    if (ac_xProcessingElement != nullptr)
    {
      mv_mapSmartCollection->insert(std::map<const char*, const std::shared_ptr<const Interfaces::IProcessingElement>>::value_type(ac_xProcessingElement->mf_szGetPEIdentifier(), ac_xProcessingElement));
    }
  }

  std::shared_ptr<const Interfaces::ITriggerCollection> CBufferIPECollection::mf_xGetAllStartTriggers() const
  {
    std::shared_ptr<const Interfaces::ITriggerCollection> lv_xLocalTriggerCollection = std::make_shared<Foundation::CBufferITriggerCollection>();

    if (mp_GetSize() > 0)
    {
      for (const auto& item : *mf_mapGetRawMap())
      {
        const std::shared_ptr<const Interfaces::ITriggerCollection> lv_xItemTriggers = item.second->mf_xGetStartTriggers();
        if (lv_xItemTriggers != nullptr && lv_xItemTriggers->mp_GetSize() > 0)
        {
          for (const auto & item2 : *lv_xItemTriggers->mf_mapGetRawMap())
          {
            lv_xLocalTriggerCollection->mp_AddTrigger(item2.second);
          }
        }
      }
    }
    return lv_xLocalTriggerCollection;
  }

  std::shared_ptr<const Interfaces::ITriggerCollection> CBufferIPECollection::mf_xGetAllStopTriggers() const
  {
    std::shared_ptr<const Interfaces::ITriggerCollection> lv_xLocalTriggerCollection = std::make_shared<Foundation::CBufferITriggerCollection>();

    if (mp_GetSize() > 0)
    {
      for (const auto& item : *mf_mapGetRawMap())
      {
        const std::shared_ptr<const Interfaces::ITriggerCollection> lv_xItemTriggers = item.second->mf_xGetStopTriggers();
        if (lv_xItemTriggers != nullptr && lv_xItemTriggers->mp_GetSize() > 0)
        {
          for (const auto & item2 : *lv_xItemTriggers->mf_mapGetRawMap())
          {
            lv_xLocalTriggerCollection->mp_AddTrigger(item2.second);
          }
        }
      }
    }
    return lv_xLocalTriggerCollection;
  }

  std::shared_ptr<const Interfaces::ITriggerCollection> CBufferIPECollection::mf_xGetAllTriggers() const
  {
    std::shared_ptr<const Interfaces::ITriggerCollection> lv_xLocalTriggerCollection = std::make_shared<Foundation::CBufferITriggerCollection>();

    std::shared_ptr<const Interfaces::ITriggerCollection> lv_xLocalStartTrigger = mf_xGetAllStartTriggers();
    std::shared_ptr<const Interfaces::ITriggerCollection> lv_xLocalStopTrigger = mf_xGetAllStopTriggers();

    if (lv_xLocalStartTrigger != nullptr && lv_xLocalStartTrigger->mp_GetSize() > 0)
    {
      for (const auto & item : *lv_xLocalStartTrigger->mf_mapGetRawMap())
      {
        lv_xLocalTriggerCollection->mp_AddTrigger(item.second);
      }
    }

    if (lv_xLocalStopTrigger != nullptr && lv_xLocalStopTrigger->mp_GetSize() > 0)
    {
      for (const auto & item : *lv_xLocalStopTrigger->mf_mapGetRawMap())
      {
        lv_xLocalTriggerCollection->mp_AddTrigger(item.second);
      }
    }
    return lv_xLocalTriggerCollection;
  }

  CBufferIPECollection::~CBufferIPECollection()
  {
    delete mv_mapSmartCollection;
  }

}