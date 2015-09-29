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
Revision | Who      | Date           | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | September 2015 | Created
*/

#pragma once

#include "common/defines.h"
#include <SFML/Graphics.hpp>
#include <memory>

namespace IModel
{
  class EXPORT_API IFrame : public sf::Drawable, public sf::Transformable
  {
  public:
    IFrame(const std::string ac_szPicturePath);
    ~IFrame();

    virtual const float mp_dfGetWidth() const = 0;

    virtual const float mp_dfGetHeight() const = 0;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  protected:
    sf::Texture   mv_Texture;
    sf::Sprite*   mv_Sprite;
    const std::string mc_szPicturePath;

  };

  
}