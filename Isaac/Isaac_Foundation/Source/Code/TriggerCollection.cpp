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
1.0      | hc       | March 2014 | Created
*/

#include <TriggerCollection.h>
#include <boost/assert.hpp>
#include <memory>

namespace isaac
{

  CTriggerCollection::CTriggerCollection()
  {
   
  }

  void CTriggerCollection::mp_AddTrigger(const std::shared_ptr<const ITrigger>& ac_xTrigger) const
  {
    BOOST_ASSERT_MSG(ac_xTrigger != nullptr, "Trigger is null");
    if (ac_xTrigger != nullptr)
    {
      mv_mapSmartCollection.insert(std::map<std::string, const std::shared_ptr<const ITrigger>>::value_type(ac_xTrigger->mf_szGetTriggerName(), ac_xTrigger));
    }
  }

  bool CTriggerCollection::mf_bRemoveTrigger(std::string ac_szTriggerIdentifier)
  {
    BOOST_ASSERT_MSG(!ac_szTriggerIdentifier.empty(), "Empty string provided");
    if (!ac_szTriggerIdentifier.empty())
    {
      mv_mapSmartCollection.erase(ac_szTriggerIdentifier);
      return true;
    }
    return false;
  }

  const std::shared_ptr<const ITrigger>& CTriggerCollection::mf_xGetTriggerByName(std::string ac_szTriggerIdentifier) const
  {
    BOOST_ASSERT_MSG(!ac_szTriggerIdentifier.empty(), "Empty string provided");
    if (!ac_szTriggerIdentifier.empty())
    {
      auto it = mv_mapSmartCollection.find(ac_szTriggerIdentifier);
      return it->second;
    }
  }

  CTriggerCollection::~CTriggerCollection()
  {
    
  }
}