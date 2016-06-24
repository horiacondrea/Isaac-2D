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
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#include "Frame.h"
#include <cassert>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  Frame::Frame(const std::string ac_szPicturePath) :
    mc_szPicturePath(ac_szPicturePath)
  {
    mv_Sprite = new sf::Sprite();
    if (!mv_Texture.loadFromFile(mc_szPicturePath))
      assert(false);
    else
      mv_Sprite->setTexture(mv_Texture, true);
  }


  void Frame::draw(sf::RenderTarget& target, sf::RenderStates States) const
  {
    States.transform *= getTransform();

    target.draw(*mv_Sprite, States);
  }

  Frame::~Frame()
  {
    delete mv_Sprite;
  }
}