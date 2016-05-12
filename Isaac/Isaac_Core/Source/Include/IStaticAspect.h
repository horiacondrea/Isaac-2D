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
#include <SceneCollection.h>
#include <TriggerCollection.h>
#include <TransientDataCollection.h>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  class EXPORT_API IStaticAspect : public isaac::CSceneCollection,
    public isaac::CTriggerCollection,
    public isaac::CTransientDataCollection
  {

  public:

    /*!
    In this method you need to define your available scenes
    Return value : void
    Arguments    : none
    */
    virtual void mp_DefineScenes() const = 0;

    /*!
    In this method you can define you available triggers
    Return value : void
    Arguments    : none
    */
    virtual void mp_DefineTriggers() const = 0;

    /*!
    In this method you can define you available transient data
    Return value : void
    Arguments    : none
    */
    virtual void mp_DefineTransientData() const = 0;

  public:

    virtual ~IStaticAspect()
    {
    }

  };

  typedef std::shared_ptr< const isaac::IStaticAspect > StaticAspect;
}