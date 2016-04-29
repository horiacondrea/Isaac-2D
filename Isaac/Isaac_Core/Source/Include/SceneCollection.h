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
#include <IMapSmartCollection.h>
#include <IScene.h>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  /*!
  This class buffer holds a collection of Scenes
  */
  class EXPORT_API CSceneCollection : public isaac::IMapSmartCollection<const isaac::IScene>
  {

  public:
    /*!
    Empty public constructor
    */
    CSceneCollection();

    /*!
    Return the scene that has the specified name, if the scene is not found
    nullptr will be returned
    */
    const Scene& mf_xGetSceneByName(const std::string& av_szSceneName) const;

    virtual ~CSceneCollection();

  protected:

    /*!
    Use this method to add a scene in the buffer, if the scene is null, it will not be
    added in the buffer and an assert will appear in DEBUG mode.
    */
    void mp_AddScene(const Scene& ac_xSceneToAdd) const;

  };

  typedef std::shared_ptr< const CSceneCollection > SceneCollection;
}

