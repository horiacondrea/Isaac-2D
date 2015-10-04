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
Copyright @ 2015
Author Horatiu Condrea [ horiacondrea.com ]
Revision | Who      | Date           | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | October 2015   | Created
*/
#include "../Include/Animation.h"
#define oneSecond 1000

namespace CModel
{
  Animation::Animation()
  {
    mv_nNumberOfFrames = 0;
  }

  void Animation::mp_AddFrame(const IModel::IFrame * ac_pFrame)
  {
    mv_mapFrames.emplace(mv_nNumberOfFrames, ac_pFrame);
    ++mv_nNumberOfFrames;
  }

  void Animation::mp_SetSpeet(const int & ac_nSpeed)
  {
    mc_nSpeed = ac_nSpeed;
  }

  void Animation::draw(sf::RenderTarget & target, sf::RenderStates states) const
  {
    sf::Time lv_Speed = mv_Clock.getElapsedTime();
    states.transform *= getTransform();
    auto& it = mv_mapFrames.find(mv_nCurrentIndex);
    if (lv_Speed.asMilliseconds() > (oneSecond / mc_nSpeed))
    {
      mv_nCurrentIndex++;
      it = mv_mapFrames.find(mv_nCurrentIndex);
      if (it == mv_mapFrames.end())
      {
        it = mv_mapFrames.begin();
        mv_nCurrentIndex = it->first;
      }
      mv_Clock.restart();
    }
    target.draw(*it->second, states);
  }

  void Animation::mp_Update()
  {
  }

  Animation::~Animation()
  {
  }
  
}