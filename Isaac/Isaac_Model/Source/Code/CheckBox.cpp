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
1.0      | hc       | August 2015 | Created
*/
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#include <CheckBox.h>
#include <iostream>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  CheckBox::CheckBox(const isaac::IFrame* ac_Box, isaac::IFrame* av_Check, const bool& ac_bCheck) : 
    isaac::ICheckBox(ac_Box, av_Check, ac_bCheck)
  {
      ;
  }

  void CheckBox::mp_Update(std::shared_ptr<sf::RenderWindow>  av_pMainWindow, sf::Event event)
  {
    const int mouseX = sf::Mouse::getPosition(*av_pMainWindow).x;
    const int mouseY = sf::Mouse::getPosition(*av_pMainWindow).y;

    float SpriteY2 = this->getPosition().y;
    float SpriteX2 = this->getPosition().x;


    if (((mouseX > this->getPosition().x) && (mouseX < this->getPosition().x + mc_Box->mp_dfGetWidth())) &&
      ((mouseY > this->getPosition().y) && (mouseY < getPosition().y + mc_Box->mp_dfGetWidth())))
    {
    
      if (event.type == event.MouseButtonReleased && event.type == event.mouseButton.button == sf::Mouse::Left)
      {
        if (!mv_bChecked)
          mv_bChecked = true;
        else
          mv_bChecked = false;
      }
    }
  }

  void CheckBox::mp_SetCheckBox(const bool& ac_bCheck)
  {
    mv_bChecked = ac_bCheck;
  }

  bool CheckBox::mf_bCheckForTrigger()
  {
    return mv_bChecked;
  }

  void CheckBox::draw(sf::RenderTarget& target, sf::RenderStates States) const
  {
    States.transform *= getTransform();
    target.draw(*mc_Box, States);

    if (mv_bChecked)
      target.draw(*mv_Check, States);
  }

  CheckBox::~CheckBox()
  {
  }
}