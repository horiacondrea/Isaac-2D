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
  class EXPORT_API TextButton : public sf::Drawable, public sf::Transformable
  {
  public:
    TextButton(const std::string& ac_szButtonText, const std::string& ac_szButtonTextFont);
    virtual ~TextButton();

    enum MouseTriggerType
    {
      en_LeftClick,
      en_RightClick,
      en_MidClick,
      en_RollOver,
      en_RollOut,
      en_Unknow
    };

  private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates Scenes) const;

  public:

    virtual void mp_SetCharacterSize(const unsigned& ac_nSize);

    virtual const bool mf_bCheckForTrigger(std::shared_ptr<sf::RenderWindow>  av_pMainWindow, const MouseTriggerType& av_enumType) const;

    virtual std::shared_ptr<sf::Shape> mf_xGetShape() {

      return mv_SpriteButton;
    }

    virtual std::shared_ptr<sf::Font> mf_xGetFont() {

      return mv_LabelFont;
    }

    virtual std::shared_ptr<sf::Text> mf_xGetText() {

      return mv_LabelText;
    }

  private:

    std::shared_ptr<sf::Shape>  mv_SpriteButton;
    std::shared_ptr<sf::Font>   mv_LabelFont;
    std::shared_ptr<sf::Text>   mv_LabelText;
    mutable bool mv_bMouseRollOver;

  };

}