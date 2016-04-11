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
#include "IMapCollection.h"
#include <boost/any.hpp>
#include <boost/assert.hpp>
#include "common/defines.h"

#pragma warning( disable : 4715 ) // not all control paths return (bla bla)

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
    class EXPORT_API ITransientData : public Interfaces::IMapCollection<const boost::any>
    {
    protected:

      virtual void mp_AddTransientData(const boost::any, std::string ac_szPortName) const = 0;

    public:

      template<class Type>
      Type mf_xGetTransientData(std::string ac_szDataIdentifier) const
      {
        const auto& it = mv_mapCollection->find(ac_szDataIdentifier);
        if (!it->second.empty())
        {
          if (it->second.type() == typeid(Type))
            return boost::any_cast<Type>(it->second);
          else
          {
            // Wrong Data Type
            // Assert here
            BOOST_ASSERT_MSG(false, "Wrong data type!");
          }
        }
        else
        {
          // Wrong Data Identifier
          // Assert here
          BOOST_ASSERT_MSG(false, "Data Identifier not found!");
        }
      }

      template<class Type>
      void mp_UpdateTransientData(std::string ac_szDataIdentifier, Type ac_data__Data) const
      {
        for (const auto& dataItem : *mv_mapCollection)
        {
          if (!dataItem.second.empty())
          {
            if (dataItem.first == ac_szDataIdentifier)
            {
              if (dataItem.second.type() == typeid(Type))
              {
                mv_mapCollection->erase(ac_szDataIdentifier);
                mv_mapCollection->emplace(ac_szDataIdentifier, ac_data__Data);
                break;
              }
              else
              {
                // Wrong Data Type
                // Assert here
                BOOST_ASSERT_MSG(false, "Wrong data type!");
              }
            }

          }
        }
      }

      virtual ~ITransientData()
      {
      }
    };
  }
}