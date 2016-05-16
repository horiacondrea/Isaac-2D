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
#include <ProcElemCollection.h>
#include <boost/assert.hpp>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  CProcElemCollection::CProcElemCollection()
  {
    
  }

  const ProcessingElement& CProcElemCollection::mf_xGetProcElemByName(std::string ac_szPEIdentifier) const
  {
    BOOST_ASSERT_MSG(!ac_szPEIdentifier.empty(), "Empty string provided");
    if (!ac_szPEIdentifier.empty())
    {
      const auto& it = mv_mapSmartCollection.find(ac_szPEIdentifier);
      return it->second;
    }
    return nullptr;
  }

  void CProcElemCollection::mp_AddProcessingElement(const ProcessingElement& ac_xProcessingElement) const
  {
    BOOST_ASSERT_MSG(ac_xProcessingElement != nullptr, "Process to add is null");
    if (ac_xProcessingElement != nullptr)
    {
      mv_mapSmartCollection.insert(std::map<std::string, const std::shared_ptr<const isaac::IProcessingElement>>::value_type(ac_xProcessingElement->mf_szGetPEIdentifier(), ac_xProcessingElement));
    }
  }

  TriggerCollection CProcElemCollection::mf_xGetAllStartTriggers() const
  {
    auto lv_xLocalTriggerCollection = std::make_shared<isaac::CTriggerCollection>();

    if (mv_mapSmartCollection.size())
    {
      for (const auto& item : mv_mapSmartCollection)
      {
        const auto& lv_xItemTriggers = item.second->mf_xGetStartTriggers();
        if (lv_xItemTriggers != nullptr && lv_xItemTriggers->mp_GetSize() > 0)
        {
          for (const auto & item2 : lv_xItemTriggers->mf_mapGetRawMap())
          {
            lv_xLocalTriggerCollection->mp_AddTrigger(item2.second);
          }
        }
      }
    }
    return lv_xLocalTriggerCollection;
  }

  TriggerCollection CProcElemCollection::mf_xGetAllStopTriggers() const
  {
    auto lv_xLocalTriggerCollection = std::make_shared<isaac::CTriggerCollection>();

    if (mv_mapSmartCollection.size() > 0)
    {
      for (const auto& item : mv_mapSmartCollection)
      {
        const auto& lv_xItemTriggers = item.second->mf_xGetStopTriggers();
        if (lv_xItemTriggers != nullptr && lv_xItemTriggers->mp_GetSize() > 0)
        {
          for (const auto & item2 : lv_xItemTriggers->mf_mapGetRawMap())
          {
            lv_xLocalTriggerCollection->mp_AddTrigger(item2.second);
          }
        }
      }
    }
    return lv_xLocalTriggerCollection;
  }

  TriggerCollection CProcElemCollection::mf_xGetAllTriggers() const
  {
    auto lv_xLocalTriggerCollection = std::make_shared<isaac::CTriggerCollection>();

    auto lv_xLocalStartTrigger = mf_xGetAllStartTriggers();
    auto lv_xLocalStopTrigger = mf_xGetAllStopTriggers();

    if (lv_xLocalStartTrigger != nullptr && lv_xLocalStartTrigger->mp_GetSize() > 0)
    {
      for (const auto & item : lv_xLocalStartTrigger->mf_mapGetRawMap())
      {
        lv_xLocalTriggerCollection->mp_AddTrigger(item.second);
      }
    }

    if (lv_xLocalStopTrigger != nullptr && lv_xLocalStopTrigger->mp_GetSize() > 0)
    {
      for (const auto & item : lv_xLocalStopTrigger->mf_mapGetRawMap())
      {
        lv_xLocalTriggerCollection->mp_AddTrigger(item.second);
      }
    }
    return lv_xLocalTriggerCollection;
  }

  CProcElemCollection::~CProcElemCollection()
  {
  }

}