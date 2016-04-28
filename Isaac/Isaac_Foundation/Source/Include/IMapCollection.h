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

#pragma once
#include <map>

namespace isaac
{
  /*                             IMapCollection
  /////////////////////////////////////////////////////////////////////////////
  // IMapCollection -> a template interfaces used in order to hold a map of
  // keys (char*) and elemens (Types).
  /////////////////////////////////////////////////////////////////////////////
  */

  template<class Type>
  class IMapCollection
  {
  public:

    const int mp_GetSize() const
    {
      return mv_mapCollection.size();
    }

    std::map<std::string, Type> mf_mapGetRawMap() const
    {
      return mv_mapCollection;
    }

    virtual ~IMapCollection()
    {

    }

  protected:
    mutable std::map<std::string, Type> mv_mapCollection;
  };
}
