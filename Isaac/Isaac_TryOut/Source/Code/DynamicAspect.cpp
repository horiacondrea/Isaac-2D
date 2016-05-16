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
1.0      | hc       | August 2014 | Created
*/

#include "DynamicAspect.h"
#include <ElementPositionTrigger.h>
#include "PEOne.h"
#include "PETwo.h"
#include "PEThree.h"

namespace Test {

  DynamicAspect::DynamicAspect()
  {
  }

  void DynamicAspect::mp_DefineScenesTransitions() const
  {
    const std::shared_ptr<const isaac::CTransition> tra1 = mf_xDefineTransition(("Scene1"), ("t1"), ("Scene3"));

    const std::shared_ptr<const isaac::CTransition> tra2 = mf_xDefineTransition(("Scene2"), ("t2"), ("Scene1"));

    const std::shared_ptr<const isaac::CTransition> tra3 = mf_xDefineTransition(("Scene3"), ("t3"), ("Dyn"));

    const std::shared_ptr<const isaac::CTransition> tra4 = mf_xDefineTransition(("Dyn"), ("t4"), ("Dyn"));

    mp_AddTransition(("tra1"), tra1);
    mp_AddTransition(("tra2"), tra2);
    mp_AddTransition(("tra3"), tra3);
    mp_AddTransition(("tra4"), tra4);
  }

  void DynamicAspect::mp_DefineInitialScene() const
  {
    mv_pInitialScene = mf_xDefineInitialScene(("Scene1"));
  }

  DynamicAspect::~DynamicAspect()
  {
  }
}