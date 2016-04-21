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

#include <SceneCollection.h>

namespace Foundation
{
  CSceneCollection::CSceneCollection()
  {
    ;
  }


  void CSceneCollection::mp_AddScene(const SmartScene& av_xSceneToAdd) const
  {
    BOOST_ASSERT_MSG(av_xSceneToAdd != nullptr, "Scene to add is null");
    if (av_xSceneToAdd != nullptr)
    {
      mv_mapSmartCollection.insert(std::map<std::string, const SmartScene>::value_type(av_xSceneToAdd->mf_szGetSceneName(), av_xSceneToAdd));
    }
  }

  const SmartScene& CSceneCollection::mf_xGetSceneByName(const std::string& av_szSceneName) const
  {
    BOOST_ASSERT_MSG(!av_szSceneName.empty(), "Empty string provided");
    if (!av_szSceneName.empty())
    {
      const auto& it = mv_mapSmartCollection.find(av_szSceneName);
      if (it != mv_mapSmartCollection.end())
        return it->second;
    }
    return nullptr;
  }

  CSceneCollection::~CSceneCollection()
  {
    ;
  }
}
