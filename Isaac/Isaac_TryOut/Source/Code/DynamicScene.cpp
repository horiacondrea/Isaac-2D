#include "DynamicScene.h"
#include "PEOne.h"
#include "PETwo.h"
#include "PEThree.h"
#include <ElementPositionTrigger.h>

#include <iostream>

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
