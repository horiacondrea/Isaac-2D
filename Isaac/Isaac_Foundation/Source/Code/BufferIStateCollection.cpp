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


#include "../Include/BufferIStateCollection.h"

namespace Foundation
{
  CBufferIStateCollection::CBufferIStateCollection()
  {
    mv_mapSmartCollection = new std::map<std::string, const std::shared_ptr<const Interfaces::IState>>();
  }


  void CBufferIStateCollection::mp_AddState(const std::shared_ptr<const Interfaces::IState>& av_xStateToAdd) const
  {
    BOOST_ASSERT_MSG(av_xStateToAdd != nullptr, "State to add is null");
    if (av_xStateToAdd != nullptr)
    {
      mv_mapSmartCollection->insert(std::map<std::string, const std::shared_ptr<const Interfaces::IState>>::value_type(av_xStateToAdd->mf_szGetStateName(), av_xStateToAdd));
    }
  }

  const std::shared_ptr<const Interfaces::IState>& CBufferIStateCollection::mf_xGetStateByName(std::string av_szStateName) const
  {
    BOOST_ASSERT_MSG(!av_szStateName.empty(), "Empty string provided");
    if (!av_szStateName.empty())
    {
      const auto& it = mv_mapSmartCollection->find(av_szStateName);
      if (it != mv_mapSmartCollection->end())
        return it->second;
    }
  }



  CBufferIStateCollection::~CBufferIStateCollection()
  {
    delete mv_mapSmartCollection;
  }
}
