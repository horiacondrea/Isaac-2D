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
#include <SFML/Graphics.hpp>
#include <Frame.h>
#include "defines.h"
/////////////////////////////////////////////////////////////////////////////

namespace isaac
{
  class EXPORT_API CheckBox : public sf::Drawable, public sf::Transformable
  {
  public:
    CheckBox(const isaac::Frame* ac_Box, isaac::Frame* av_Check, const bool& ac_bCheck);
    CheckBox(const sf::Shape* ac_Box, sf::Shape* av_Check, const bool& ac_bCheck);
    ~CheckBox();

    virtual void mp_Update(std::shared_ptr<sf::RenderWindow>  av_pMainWindow, sf::Event event);

    virtual bool mf_bCheckForTrigger();

    virtual void mp_SetCheckBox(const bool& ac_bCheck);

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates States) const;

    const Frame* mc_Box;
    Frame* mv_Check;

    const sf::Shape* mc_pBox;
    sf::Shape* mv_pCheck;

    bool mv_bChecked;
  
  };

  
}