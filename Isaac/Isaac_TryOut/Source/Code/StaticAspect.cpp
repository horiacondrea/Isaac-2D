#include "StaticAspect.h"
#include <ClickOnShape.h>


StaticAspect::StaticAspect()
{
}

void StaticAspect::mp_Define_States() const
{
  const std::shared_ptr<const Foundation::Interfaces::IStaticState> s1 = std::make_shared<StateOne>(("State1"));
  mp_AddState(s1);

  const std::shared_ptr<const Foundation::Interfaces::IStaticState> s2 = std::make_shared<StateTwo>(("State2"));
  mp_AddState(s2);

  const std::shared_ptr<const Foundation::Interfaces::IStaticState> s3 = std::make_shared<StateThree>(("State3"));
  mp_AddState(s3);

  const std::shared_ptr<const Foundation::Interfaces::IDynamicState> s4 = std::make_shared<DynamicState>(("Dyn"));
  mp_AddState(s4);


  //s2->mp_SetFatherState(s3);
  //s1->mp_SetFatherState(s3);
}

void StaticAspect::mp_Define_Triggers() const
{
  const std::shared_ptr<const Foundation::Interfaces::ITrigger> t1 = std::make_shared<Triggers::CElementPositionTrigger>(Triggers::en_GraterThen, ("t1"));
  const std::shared_ptr<const Foundation::Interfaces::ITrigger> t2 = std::make_shared<Triggers::CElementPositionTrigger>(Triggers::en_GraterThen, ("t2"));
  const std::shared_ptr<const Foundation::Interfaces::ITrigger> t3 = std::make_shared<Triggers::CClickOnShape>(("t3"));
  const std::shared_ptr<const Foundation::Interfaces::ITrigger> t4 = std::make_shared<Triggers::CElementPositionTrigger>(Triggers::en_GraterThen, ("t4"));

  mp_AddTrigger(t1);
  mp_AddTrigger(t2);
  mp_AddTrigger(t3);
  mp_AddTrigger(t4);
}

void StaticAspect::mp_Define_Transient_Data() const
{

  const int data1 = 10;
  mp_AddTransientData(data1, "int");

 /* std::shared_ptr<const DataModelI::IInt> data2 = std::make_shared<const DataModelC::CBufferIInt>(5);
  mp_AddTransientData(data2, "smart");

  pint = new int(26);
  mp_AddTransientData(pint, "pint");*/

  std::pair<int, int> pair = std::make_pair<int, int>(0, 0);
  mp_AddTransientData(pair, "pair");
}

StaticAspect::~StaticAspect()
{
}
