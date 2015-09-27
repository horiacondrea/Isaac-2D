#include "..\Include\DynamicState.h"
#include "..\Include\PEOne.h"
#include "..\Include\PETwo.h"
#include "..\Include\PEThree.h"
#include <ElementPositionTrigger.h>


DynamicState::DynamicState(const char* ac_szStateName) :
Foundation::Interfaces::IDynamicState(ac_szStateName)
{
  ;
}

void DynamicState::mp_DefineProcess() const
{
  std::shared_ptr< Foundation::Interfaces::IProcessingElement> pe1 = std::make_shared<PEOne>(Foundation::Interfaces::IProcessingElement::en_Permanent, "pe1");

  std::shared_ptr< Foundation::Interfaces::IProcessingElement> pe2 = std::make_shared< PETwo>(Foundation::Interfaces::IProcessingElement::en_Continuous, "pe2");

  std::shared_ptr< Foundation::Interfaces::IProcessingElement> pe3 = std::make_shared< PEThree>(Foundation::Interfaces::IProcessingElement::en_PermanentWithStop, "pe3");

  std::shared_ptr<const Foundation::Interfaces::ITrigger> t1 = std::make_shared<const Triggers::CElementPositionTrigger>(Triggers::en_GraterThen, ("tpe"));

  std::shared_ptr<const Foundation::Interfaces::ITrigger> t2 = std::make_shared<const Triggers::CElementPositionTrigger>(Triggers::en_GraterThen, ("tpe2"));


  pe2->mp_addStartTrigger(t1);
  pe3->mp_addStopTrigger(t2);

  mp_AddProcessingElement(pe1);
  mp_AddProcessingElement(pe2);
  mp_AddProcessingElement(pe3);

}

DynamicState::~DynamicState()
{
}
