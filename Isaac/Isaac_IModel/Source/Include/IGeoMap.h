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
Revision | Who      | Date           | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | September 2015 | Created
*/
#pragma once

#include <SFML\Graphics.hpp>
#include <list>>
#include <map>>
#include "IFrame.h"

typedef std::map<const char, const IModel::IFrame*> MapItem; // ex: a is red.png, b is blue.png 

namespace IModel
{
  typedef std::vector<std::vector<char>> MatrixMapItemsContainer;

  class __declspec(dllexport) IGeoMap : public sf::Drawable, public sf::Transformable
  {
    
  public:
    IGeoMap(MatrixMapItemsContainer av_Container);
    ~IGeoMap();

    virtual void mp_InitMap(std::list<MapItem> av_listMap) = 0;

  protected:
    std::list<MapItem> mv_listMap;
    MatrixMapItemsContainer mv_Container;

  private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;


  };

}
