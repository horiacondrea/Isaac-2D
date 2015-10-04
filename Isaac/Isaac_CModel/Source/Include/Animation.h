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
Copyright @ 2015
Author Horatiu Condrea [ horiacondrea.com ]
Revision | Who      | Date           | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | October 2015   | Created
*/
#pragma once
#include <IAnimation.h>

namespace CModel
{
  class  __declspec(dllexport) Animation : public IModel::IAnimation
  {
  public:
    Animation();
    virtual ~Animation();

    virtual void mp_Update();

    virtual void mp_AddFrame(const IModel::IFrame* ac_pFrame);

    virtual void mp_SetSpeet(const int& ac_nSpeed);

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
  };

  
}
