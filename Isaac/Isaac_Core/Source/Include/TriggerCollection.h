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
#include "defines.h"
#include <IMapSmartCollection.h>
#include <ITrigger.h>

namespace isaac
{
  class EXPORT_API CTriggerCollection : public IMapSmartCollection<const ITrigger>
  {
  public:
    CTriggerCollection();

    bool mf_bRemoveTrigger(std::string ac_szTriggerIdentifier);

    const Trigger& mf_xGetTriggerByName(std::string ac_szTriggerIdentifier) const;

    virtual ~CTriggerCollection();

    template<class Type>
    std::shared_ptr<Type> mf_xGetTriggerByNameAndType(std::string ac_szTriggerIdentifier) const
    {
      const auto& it = mv_mapSmartCollection->find(ac_szTriggerIdentifier);
      if (it->second != nullptr)
      {
        if (typeid(it->second) == typeid(Type))
        {
          if (std::is_const<Type>())
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

    void mp_AddTrigger(const Trigger& ac_xTrigger) const;

  };

  typedef std::shared_ptr<isaac::CTriggerCollection> TriggerCollection;
}