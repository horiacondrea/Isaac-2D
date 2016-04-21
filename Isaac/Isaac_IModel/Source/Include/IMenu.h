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


#pragma once
#include "defines.h"
#include "IButton.h"
#include <SFML/Graphics.hpp>

namespace IModel
{

  class EXPORT_API IMenu : public sf::Drawable, public sf::Transformable
  {
  public:
    enum Orientation
    {
      X_Axis,
      Y_Axis
    };

    IMenu(const Orientation ac_enumOrientation, const unsigned& ac_nOffset);
    ~IMenu();

  public:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates States) const
    {
      States.transform *= getTransform();

      for (const auto& button : mv_mapMenu)
      {
        target.draw(*button.second, States);
      }
    }

    virtual void mp_AddButton(std::shared_ptr<IButton> av_xButton, const std::string ac_szKey) = 0;

    virtual void mp_SetButtonsColor(const sf::Color& av_Color) = 0;

    virtual void mp_SetButtonsCharacterSize(const unsigned& av_nSize) = 0;

  protected:

    std::map<const std::string, std::shared_ptr<IModel::IButton>> mv_mapMenu;
    const Orientation mc_enumOrientation;
    const unsigned mc_nOffset;

  };

}