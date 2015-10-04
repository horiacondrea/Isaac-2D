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
1.0      | hc       | October        | Created
*/
#pragma once

#include <SFML\Graphics.hpp>
#include "IFrame.h"

namespace IModel
{

  class  __declspec(dllexport) IAnimation : public sf::Drawable, public sf::Transformable
  {
  public:
    IAnimation();
    virtual ~IAnimation();

    virtual void mp_Update() = 0;

    virtual void mp_AddFrame(const IModel::IFrame* ac_pFrame) = 0;

    virtual void mp_SetSpeet(const int& ac_nSpeed) = 0;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

  protected:
    std::map<unsigned, const IModel::IFrame*> mv_mapFrames;
    int mc_nSpeed;
    mutable sf::Clock mv_Clock;
    mutable unsigned mv_nCurrentIndex;
    unsigned mv_nNumberOfFrames;
  };

  
}