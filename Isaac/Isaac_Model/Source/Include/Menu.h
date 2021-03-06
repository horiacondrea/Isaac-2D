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
#include <TextButton.h>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  class EXPORT_API Menu: public sf::Shape
  {
  public:
    enum Axis
    {
      en_X,
      en_Y,
      en_Unknow
    };

    Menu(const Axis ac_enumOrientation, const unsigned& ac_nOffset);

    virtual void mp_AddButton(isaac::TextButton* av_xButton, const std::string ac_szKey);

    virtual void mp_SetButtonsCharacterSize(const unsigned& av_nSize);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates States) const;

    ~Menu();

  private:
    std::map<const std::string, isaac::TextButton*>* mv_mapMenu;
    const Axis mc_enumOrientation;
    const unsigned mc_nOffset;
  };

}