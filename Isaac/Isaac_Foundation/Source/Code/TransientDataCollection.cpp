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
//  1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software.
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

#include <TransientDataCollection.h>
#include <boost/assert.hpp>

namespace Foundation
{

  CTransientDataCollection::CTransientDataCollection()
  {
    ;
  }

  void CTransientDataCollection::mp_AddTransientData(const boost::any ac_data__Data, std::string ac_szDataIdentifier) const
  {
    BOOST_ASSERT_MSG(!ac_data__Data.empty(), "Empty transient data provided");
    BOOST_ASSERT_MSG(!ac_szDataIdentifier.empty(), "Empty string provided");

    if ((!ac_szDataIdentifier.empty()) && (!ac_data__Data.empty()))
    {
      mv_mapCollection.emplace(ac_szDataIdentifier, ac_data__Data);
    }
  }


  CTransientDataCollection::~CTransientDataCollection()
  {
  }
}