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
#pragma once
#include "defines.h"
#include <boost/any.hpp>
#include <IMapCollection.h>
#include <IMapSmartCollection.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  /*!
  This class buffer holds a collection of transient data
  */
  class EXPORT_API CTransientDataCollection : public IMapCollection < const boost::any >
  {
  public:
    /*!
    Empty public constructor
    */
    CTransientDataCollection();

    /*!
    Template method for retrieving transient data
    */
    template<class Type>
    Type mf_xGetTransientData(std::string ac_szDataIdentifier) const;

    /*!
    Template method for updating transient data
    */
    template<class Type>
    void mp_UpdateTransientData(std::string ac_szDataIdentifier, Type ac_data__Data) const;

  protected:

    /*!
    Use this method to add a transient data in the buffer, if the transient data is empty or if the
    transient data identifier is empty, data will not be added in the buffer and an assert will
    appear in DEBUG mode.
    */
    void mp_AddTransientData(const boost::any ac_data__Data, std::string ac_szDataIdentifier) const;

    ~CTransientDataCollection();
  };

  typedef std::shared_ptr< const isaac::CTransientDataCollection > TransientDataCollection;

}