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
#include <TextButton.h>
#include <assert.h>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  namespace {
    template <typename T>
    bool IsInBounds(const T& value, const T& low, const T& high) {
      return !(value < low) && !(high < value);
    }
  }

  TextButton::TextButton(const std::string& ac_szButtonText, const std::string& ac_szButtonTextFont)
  {
    assert(!(ac_szButtonText == ""));
    assert(!(ac_szButtonTextFont == ""));


    mv_LabelFont = std::make_shared<sf::Font>();
    mv_LabelText = std::make_shared<sf::Text>();

    mv_LabelText->setString(ac_szButtonText);

/*    if (!mv_LabelFont->loadFromFile(ac_szButtonTextFont))
      assert(false);
    else*/
      mv_LabelText->setFont(*mv_LabelFont);


    const float lc_lfLabelHeight = mv_LabelText->getGlobalBounds().height + mv_LabelText->getGlobalBounds().top;
    const float lc_lfLabelWidth = mv_LabelText->getGlobalBounds().width + +mv_LabelText->getGlobalBounds().left;

    mv_SpriteButton = std::make_shared<sf::RectangleShape>(sf::Vector2f(lc_lfLabelWidth, lc_lfLabelHeight));

    mv_SpriteButton->setFillColor(sf::Color::Transparent);
    mv_bMouseRollOver = false;
  }

  void TextButton::draw(sf::RenderTarget& target, sf::RenderStates Scenes) const
  {
    Scenes.transform *= getTransform();
    target.draw(*mv_SpriteButton, Scenes);
    target.draw(*mv_LabelText, Scenes);
  }

  void TextButton::mp_SetCharacterSize(const unsigned& ac_nSize)
  {
    mv_LabelText->setCharacterSize(ac_nSize);

    const float lc_lfLabelHeight = mv_LabelText->getGlobalBounds().height + mv_LabelText->getGlobalBounds().top;
    const float lc_lfLabelWidth = mv_LabelText->getGlobalBounds().width + +mv_LabelText->getGlobalBounds().left;

    const float lc_lfOriginalH = mv_SpriteButton->getGlobalBounds().height;
    const float lc_lfOriginalW = mv_SpriteButton->getGlobalBounds().width;

    mv_SpriteButton->setScale(lc_lfLabelWidth / lc_lfOriginalW, lc_lfLabelHeight / lc_lfOriginalH);
  }
  

  const bool TextButton::mf_bCheckForTrigger(std::shared_ptr<sf::RenderWindow> av_pMainWindow, const MouseTriggerType& av_enumType) const {

    const int lc_nMouseX = sf::Mouse::getPosition(*av_pMainWindow).x;
    const int lc_nMouseY = sf::Mouse::getPosition(*av_pMainWindow).y;

    const float lc_dfShapeY = mv_SpriteButton->getPosition().y;
    const float lc_dfShapeX = mv_SpriteButton->getPosition().x;

    const float lc_dfShapeWidth = mv_SpriteButton->getGlobalBounds().width;
    const float lc_dfShapeHeight = mv_SpriteButton->getGlobalBounds().height;

    if (IsInBounds<float>(lc_nMouseX, lc_dfShapeX, lc_dfShapeX + lc_dfShapeWidth) &&
      IsInBounds<float>(lc_nMouseY, lc_dfShapeY, lc_dfShapeY + lc_dfShapeHeight)) {

      switch (av_enumType)
      {
      case en_LeftClick:
      {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
          return true;
        return false;
        break;
      }
      case en_RightClick:
      {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
          return true;
        return false;
        break;
      }
      case en_MidClick:
      {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
          return true;
        return false;
        break;
      }
      case en_RollOver:
      {

        return true;
      }
      case en_RollOut:
      {
        mv_bMouseRollOver = true;
        break;
      }
      case en_Unknow:
        return false;
      default:
        break;
      }
    }
    else{
      if (mv_bMouseRollOver && av_enumType == en_RollOut) {
        mv_bMouseRollOver = false;
        return true;
      }
    }

    return false;
  }

  TextButton::~TextButton()
  {

  }
}