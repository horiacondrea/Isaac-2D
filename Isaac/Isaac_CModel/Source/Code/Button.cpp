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
Author Horatiu Condrea [ horiacondrea.com ] [ horiacondrea.com ]
Revision | Who      | Date       | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | August 2015 | Created
*/

#include "Button.h"
#include <cassert>


namespace isaac
{

  Button::Button(const std::string ac_szButtonText, const std::string ac_szButtonTextFont)
  {
    assert(!(ac_szButtonText == ""));
    assert(!(ac_szButtonTextFont == ""));

 
    mv_LabelFont = std::make_shared<sf::Font>();
    mv_LabelText = std::make_shared<sf::Text>();

    mv_LabelText->setString(ac_szButtonText);

    if (!mv_LabelFont->loadFromFile(ac_szButtonTextFont))
    {
      assert(false);
    }
    else
    {
      mv_LabelText->setFont(*mv_LabelFont);
    }

    const float lv_lfLabelHeight = mv_LabelText->getGlobalBounds().height + mv_LabelText->getGlobalBounds().top;
    const float lv_lfLabelWidth = mv_LabelText->getGlobalBounds().width + +mv_LabelText->getGlobalBounds().left;

    mv_SpriteButton = std::make_shared<sf::RectangleShape>(sf::Vector2f(lv_lfLabelWidth, lv_lfLabelHeight));

    mv_SpriteButton->setFillColor(sf::Color::Transparent);

  }

  const bool Button::mf_bCheckForTrigger(std::shared_ptr<sf::RenderWindow>  av_pMainWindow, sf::Event event) const
  {
    const int mouseX = sf::Mouse::getPosition(*av_pMainWindow).x;
    const int mouseY = sf::Mouse::getPosition(*av_pMainWindow).y;

    float SpriteY2 = this->getPosition().y;
    float SpriteX2 = this->getPosition().x;

    if (((mouseX > this->getPosition().x) && (mouseX < this->getPosition().x + mv_SpriteButton->getGlobalBounds().width)) &&
      ((mouseY > this->getPosition().y) && (mouseY < getPosition().y + mv_SpriteButton->getGlobalBounds().height)))
    {
      if (event.type == event.MouseButtonReleased && event.type == event.mouseButton.button == sf::Mouse::Left)
      {
        return true;
      }
      return false;
    }

    return false;
  }

  const bool Button::mf_bCheckForMouseRollOverIn(std::shared_ptr<sf::RenderWindow>  av_pMainWindow) const
  {
    const int mouseX = sf::Mouse::getPosition(*av_pMainWindow).x;
    const int mouseY = sf::Mouse::getPosition(*av_pMainWindow).y;

    if (((mouseX > this->getPosition().x) && (mouseX < this->getPosition().x + mv_SpriteButton->getGlobalBounds().width)) &&
      ((mouseY > this->getPosition().y) && (mouseY < getPosition().y + mv_SpriteButton->getGlobalBounds().height)))
    {
      return true;
    }
    return false;
  }

  Button::~Button()
  {
  }
}