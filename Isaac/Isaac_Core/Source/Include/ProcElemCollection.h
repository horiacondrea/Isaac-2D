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

//                             Headers
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <IMapSmartCollection.h>
#include <IProcessingElement.h>
#include <IMapSmartCollection.h>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  /*!
  This class buffer holds a collection of Process Elements, you can add, replace or
  get any process element that is stored in this buffer
  */
  class  EXPORT_API CProcElemCollection : public IMapSmartCollection<const IProcessingElement>
  {
  public:

    CProcElemCollection();

    /*!
    Return the process element that has the specified name, if process element 
    is not found nullptr will be returned
    */
    const ProcessingElement mf_xGetProcElemByName(std::string ac_szPEIdentifier) const;

    /*!
    Returns all the start triggers that are availalbe for all the Process Elements
    in the buffer, if no start triggers are found a collection with ZERO(0) elements
    will be returned.
    */
    TriggerCollection mf_xGetAllStartTriggers() const;

    /*!
    Returns all the stop triggers that are availalbe for all the Process Elements
    in the buffer, if no stop triggers are found a collection with ZERO(0) elements
    will be returned.
    */
    TriggerCollection mf_xGetAllStopTriggers() const;

    /*!
    Returns all the triggers that are availalbe for all the Process Elements
    in the buffer, if no triggers are found a collection with ZERO(0) elements
    will be returned.
    */
    TriggerCollection mf_xGetAllTriggers() const;

    virtual ~CProcElemCollection();

  protected:

    /*!
    Use this method to add a processing element in the buffer, if the processing element
    is null, it will no be added in the buffer and an assert will appear in DEBUG mode.
    */
    void mp_AddProcessingElement(const ProcessingElement& ac_xProcessingElement) const;

  };

  typedef std::shared_ptr< const isaac::CProcElemCollection > ProcessingElementCollection;

}