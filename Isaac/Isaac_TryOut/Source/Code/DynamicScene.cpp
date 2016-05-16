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

#include "DynamicScene.h"
#include "PEOne.h"
#include "PETwo.h"
#include "PEThree.h"
#include <ElementPositionTrigger.h>
#include <iostream>

namespace Test {

  DynamicScene::DynamicScene(std::string ac_szSceneName) :
    isaac::IDynamicScene(ac_szSceneName)
  {
    ;
  }

  void DynamicScene::mp_DefineProcess() const
  {
    std::cout << "Dynamic Scene - defining  processes" << std::endl;

    std::shared_ptr< isaac::IProcessingElement> pe1 = std::make_shared<PEOne>(isaac::IProcessingElement::en_Permanent, "pe1");

    std::shared_ptr< isaac::IProcessingElement> pe2 = std::make_shared<PETwo>(isaac::IProcessingElement::en_Continuous, "pe2");

    std::shared_ptr< isaac::IProcessingElement> pe3 = std::make_shared<PEThree>(isaac::IProcessingElement::en_PermanentWithStop, "pe3");

    std::shared_ptr<const isaac::ITrigger> t1 = std::make_shared<const isaac::CElementPositionTrigger>(isaac::en_GraterThen, ("tpe"));

    std::shared_ptr<const isaac::ITrigger> t2 = std::make_shared<const isaac::CElementPositionTrigger>(isaac::en_GraterThen, ("tpe2"));


    pe2->mp_addStartTrigger(t1);
    pe3->mp_addStopTrigger(t2);

    mp_AddProcessingElement(pe1);
    mp_AddProcessingElement(pe2);
    mp_AddProcessingElement(pe3);

  }

  DynamicScene::~DynamicScene()
  {
  }
}