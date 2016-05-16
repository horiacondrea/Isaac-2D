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
#pragma once
#include "defines.h"
#include <SFML/Graphics.hpp>
#include <memory>
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  class EXPORT_API IButton : public sf::Drawable, public sf::Transformable
  {
  public:
    IButton();
    virtual ~IButton();

  private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates Scenes) const
    {
      Scenes.transform *= getTransform();
      target.draw(*mv_SpriteButton, Scenes);
      target.draw(*mv_LabelText, Scenes);
    }

  public:

    virtual void mp_SetColor(const sf::Color& ac_Color )
    {
      mv_LabelText->setColor(ac_Color);
    }

    virtual const sf::Color mf_GetColor()
    {
      return mv_LabelText->getColor();
    }

    virtual void mp_SetCharacterSize(const unsigned& ac_nSize)
    {
      mv_LabelText->setCharacterSize(ac_nSize);

      const float lv_lfLabelHeight = mv_LabelText->getGlobalBounds().height + mv_LabelText->getGlobalBounds().top;
      const float lv_lfLabelWidth = mv_LabelText->getGlobalBounds().width + +mv_LabelText->getGlobalBounds().left;

      const float lv_xOriginalH = mv_SpriteButton->getGlobalBounds().height;
      const float lv_xOriginalW = mv_SpriteButton->getGlobalBounds().width;

      mv_SpriteButton->setScale(lv_lfLabelWidth / lv_xOriginalW, lv_lfLabelHeight / lv_xOriginalH);
    }


    virtual const bool mf_bCheckForTrigger(std::shared_ptr<sf::RenderWindow>  av_pMainWindow, sf::Event event) const = 0;

    virtual const bool mf_bCheckForMouseRollOverIn(std::shared_ptr<sf::RenderWindow>  av_pMainWindow) const = 0;
   


    std::shared_ptr<sf::Shape>  mv_SpriteButton;
    std::shared_ptr<sf::Font>   mv_LabelFont;
    std::shared_ptr<sf::Text>   mv_LabelText;

  };

}