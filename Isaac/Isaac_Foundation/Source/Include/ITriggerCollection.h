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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Copyright @ 2014
Author Horatiu Condrea [ horiacondrea.com ]
Revision | Who      | Date       | Comment
---------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | March 2014 | Created
*/

#pragma once

#include "..\Include\ITrigger.h"
#include "..\Include\IMapSmartCollection.h"
#include <memory>
#include <atlstr.h>
#include <map>

namespace Foundation
{
  /*                              Interfaces
  /////////////////////////////////////////////////////////////////////////////
  // In the Interfaces namespace you will find the most important interfaces
  // used in the Framework. You can modify these files if you want, but first
  // make sure you understand how these works.
  /////////////////////////////////////////////////////////////////////////////
  */
  namespace Interfaces
  {
    class __declspec(dllexport) ITriggerCollection : public Interfaces::IMapSmartCollection<const Interfaces::ITrigger>
    {
    public:

      virtual bool mf_bRemoveTrigger(const CString& ac_szTriggerIdentifier) = 0;

      virtual const std::shared_ptr<const Interfaces::ITrigger>& mf_xGetTriggerByName(const CString& ac_szTriggerIdentifier) const = 0;

      virtual void mp_AddTrigger(const std::shared_ptr<const Interfaces::ITrigger>& ac_xTrigger) const = 0;

      template<class Type>
      std::shared_ptr<Type> mf_xGetTriggerByNameAndType(const CString& ac_szTriggerIdentifier) const
      {
        const auto& it = mv_mapSmartCollection->find(ac_szTriggerIdentifier);
        if (it->second != nullptr)
        {
          if (typeid(it->second) == typeid(Type))
          {
            if (std::is_const<Type>)
              return std::const_pointer_cast<Type>(std::static_pointer_cast<Type>(it->second));
            else
              return std::static_pointer_cast<Type>(it->second);
          }
          else
          {
            return nullptr;
          }
        }
        else
        {
          return nullptr;
        }
      }


      virtual ~ITriggerCollection()
      {
      }

    };
  }
}