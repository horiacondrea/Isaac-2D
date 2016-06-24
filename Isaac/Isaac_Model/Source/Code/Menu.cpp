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
#include <Menu.h>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{

  Menu::Menu(const Axis ac_enumOrientation, const unsigned& ac_nOffset) : 
    mc_enumOrientation(ac_enumOrientation),
    mc_nOffset(ac_nOffset)
  {
    mv_mapMenu = new std::map<const std::string, isaac::TextButton*>();
  }

  void Menu::mp_AddButton(isaac::TextButton* av_xButton, const std::string ac_szKey)
  {
    const unsigned int lc_nSize = mv_mapMenu->size();
    switch (mc_enumOrientation)
    {
    case Axis::en_X:
    {
      av_xButton->setPosition((float)lc_nSize * mc_nOffset, 0);
    }
    break;

    case Axis::en_Y:
    {
      av_xButton->setPosition(0, (float)lc_nSize * mc_nOffset);
    }
    break;
    case Axis::en_Unknow:
      break;
    default:
      break;
    }
    mv_mapMenu->emplace(std::make_pair(ac_szKey, av_xButton));
  }

  void Menu::mp_SetButtonsCharacterSize(const unsigned& av_nSize)
  {
    for (const auto& button : *mv_mapMenu)
    {
      button.second->mp_SetCharacterSize(av_nSize);
    }
  }

  void Menu::draw(sf::RenderTarget& target, sf::RenderStates States) const
  {
    States.transform *= getTransform();

    for (const auto& button : *mv_mapMenu)
    {
      target.draw(*button.second, States);
    }
  }

  Menu::~Menu()
  {
    for (const auto& button : *mv_mapMenu)
    {
      delete button.second;
    }
    delete mv_mapMenu;
  }
}