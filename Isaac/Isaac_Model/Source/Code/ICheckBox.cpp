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

#include "../Include/ICheckBox.h"

namespace isaac
{

  ICheckBox::ICheckBox(const IFrame* ac_Box, IFrame* av_Check, const bool& ac_bCheck) :
    mc_Box(ac_Box),
    mv_Check(av_Check),
    mv_bChecked(ac_bCheck)
  {
    mv_Check->setPosition(sf::Vector2f((mc_Box->mp_dfGetWidth()* 0.5) - (mv_Check->mp_dfGetWidth() * 0.5),
      (mc_Box->mp_dfGetHeight() * 0.5) - (mv_Check->mp_dfGetHeight() * 0.5)));
  }

  void ICheckBox::draw(sf::RenderTarget& target, sf::RenderStates States) const
  {
    States.transform *= getTransform();
    target.draw(*mc_Box, States);

    if (mv_bChecked)
      target.draw(*mv_Check, States);
  }

  ICheckBox::~ICheckBox()
  {
  }
}