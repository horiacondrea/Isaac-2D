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
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#include <TransitionCollection.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  CTransitionCollection::CTransitionCollection()
  {
    ;
  }

  void CTransitionCollection::mp_AddTransition(std::string ac_szTransitionIdentifier, const std::shared_ptr<const CTransition>& ac_xTransition) const
  {
    BOOST_ASSERT_MSG(!ac_szTransitionIdentifier.empty(), "Empty string provided");
    BOOST_ASSERT_MSG(ac_xTransition != nullptr, "Transition is null");
    if (!ac_szTransitionIdentifier.empty() && ac_xTransition != nullptr)
    {
      mv_mapSmartCollection->insert(std::map<std::string, const std::shared_ptr<const CTransition>>::value_type(ac_szTransitionIdentifier, ac_xTransition));
    }
  }

  bool CTransitionCollection::mf_bRemoveTransition(std::string ac_szTransitionIdentifier) const
  {
    BOOST_ASSERT_MSG(!ac_szTransitionIdentifier.empty(), "Empty string provided");
    if (!ac_szTransitionIdentifier.empty())
    {
      mv_mapSmartCollection->erase(ac_szTransitionIdentifier);
      return true;
    }
    return false;
  }

  const Transition CTransitionCollection::mf_xGetTransitionByName(std::string ac_szTransitionIdentifier)
  {
    BOOST_ASSERT_MSG(!ac_szTransitionIdentifier.empty(), "Empty string provided");
    if (!ac_szTransitionIdentifier.empty())
    {
      const auto& it = mv_mapSmartCollection->find(ac_szTransitionIdentifier);
      if (it != mv_mapSmartCollection->end())
        return it->second;
    }
    return nullptr;
  }

  CTransitionCollection::~CTransitionCollection()
  {
    ;
  }

}