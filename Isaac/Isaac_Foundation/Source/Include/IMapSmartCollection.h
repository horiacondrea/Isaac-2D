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
#include <memory>

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
    /*                          IMapSmartCollection
    /////////////////////////////////////////////////////////////////////////////
    // IMapCollection -> a smart template interfaces used in order to hold a map of
    // keys (char*) and elemens (shared_ptr<Types>).
    /////////////////////////////////////////////////////////////////////////////
    */
    template<class Type>
    class IMapSmartCollection
    {
    public:

      const unsigned int mp_GetSize() const
      {
        return mv_mapSmartCollection->size();
      }

      std::map<std::string, const std::shared_ptr<Type>>* mf_mapGetRawMap() const
      {
        return mv_mapSmartCollection;
      }

      virtual ~IMapSmartCollection()
      {

      }

    protected:
      mutable std::map<std::string, const std::shared_ptr<Type>>* mv_mapSmartCollection;
    };
  }
}