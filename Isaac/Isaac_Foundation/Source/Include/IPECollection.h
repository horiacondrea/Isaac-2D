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

#pragma once
#include "IProcessingElement.h"
#include "IMapSmartCollection.h"
#include "common/defines.h"

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
    class EXPORT_API IPECollection : public Interfaces::IMapSmartCollection<const Interfaces::IProcessingElement>
    {
    public:

      virtual const std::shared_ptr<const Interfaces::IProcessingElement>& mf_xGetPEByName(std::string) const = 0;

      virtual std::shared_ptr<const Interfaces::ITriggerCollection> mf_xGetAllStartTriggers() const = 0;

      virtual std::shared_ptr<const Interfaces::ITriggerCollection> mf_xGetAllStopTriggers() const = 0;

      virtual std::shared_ptr<const Interfaces::ITriggerCollection> mf_xGetAllTriggers() const = 0;

      virtual ~IPECollection()
      {

      }

    protected:

      virtual void mp_AddProcessingElement(const std::shared_ptr<const Interfaces::IProcessingElement>&) const = 0;

    };
  }
}