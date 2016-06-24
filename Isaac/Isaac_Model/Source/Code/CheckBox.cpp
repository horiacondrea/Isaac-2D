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
  CheckBox::CheckBox(const isaac::Frame* ac_Box, isaac::Frame* av_Check, const bool& ac_bCheck) : 
    mc_Box(ac_Box), 
    mv_Check(av_Check), 
    mv_bChecked(ac_bCheck)
  {
    mc_pBox = nullptr;
    mv_pCheck = nullptr;
    mv_Check->setPosition(sf::Vector2f((mc_Box->mf_pGetSprite()->getGlobalBounds().width * 0.5) - (mv_Check->mf_pGetSprite()->getGlobalBounds().width * 0.5),
      (mc_Box->mf_pGetSprite()->getGlobalBounds().height * 0.5) - (mv_Check->mf_pGetSprite()->getGlobalBounds().height * 0.5)));
  }

  CheckBox::CheckBox(const sf::Shape* ac_Box, sf::Shape* av_Check, const bool& ac_bCheck) :
    mc_pBox(ac_Box),
    mv_pCheck(av_Check),
    mv_bChecked(ac_bCheck)
  {
    mc_Box = nullptr;
    mv_Check = nullptr;
    mv_pCheck->setPosition(sf::Vector2f((mc_pBox->getGlobalBounds().width * 0.5) - (mv_pCheck->getGlobalBounds().width * 0.5),
      (mc_pBox->getGlobalBounds().height * 0.5) - (mv_pCheck->getGlobalBounds().height * 0.5)));
  }

  void CheckBox::mp_Update(std::shared_ptr<sf::RenderWindow>  av_pMainWindow, sf::Event event)
  {
    const int mouseX = sf::Mouse::getPosition(*av_pMainWindow).x;
    const int mouseY = sf::Mouse::getPosition(*av_pMainWindow).y;

    float SpriteY2 = this->getPosition().y;
    float SpriteX2 = this->getPosition().x;

    float lv_lfBoxHeight = 0;
    if (nullptr == mc_Box)
      lv_lfBoxHeight = mc_pBox->getGlobalBounds().height;
    else
      lv_lfBoxHeight = mc_Box->mf_pGetSprite()->getGlobalBounds().height;

    if (((mouseX > this->getPosition().x) && (mouseX < this->getPosition().x + lv_lfBoxHeight)) &&
      ((mouseY > this->getPosition().y) && (mouseY < getPosition().y + lv_lfBoxHeight)))
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
    if (nullptr != mc_Box || nullptr != mv_Check) {
      target.draw(*mc_Box, States);

      if (mv_bChecked)
        target.draw(*mv_Check, States);
    }
    else {

      target.draw(*mc_pBox, States);

      if (mv_bChecked)
        target.draw(*mv_pCheck, States);
    }

  }

  CheckBox::~CheckBox()
  {
  }
}