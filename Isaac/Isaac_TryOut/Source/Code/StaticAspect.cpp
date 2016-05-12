#include "StaticAspect.h"
#include <ClickOnShape.h>


StaticAspect::StaticAspect()
{
}

void StaticAspect::mp_DefineScenes() const
{
  const std::shared_ptr<const isaac::IStaticScene> s1 = std::make_shared<SceneOne>(("Scene1"));
  mp_AddScene(s1);

  const std::shared_ptr<const isaac::IStaticScene> s2 = std::make_shared<SceneTwo>(("Scene2"));
  mp_AddScene(s2);

  const std::shared_ptr<const isaac::IStaticScene> s3 = std::make_shared<SceneThree>(("Scene3"));
  mp_AddScene(s3);

  const std::shared_ptr<const isaac::IDynamicScene> s4 = std::make_shared<DynamicScene>(("Dyn"));
  mp_AddScene(s4);


  //s2->mp_SetFatherScene(s3);
  //s1->mp_SetFatherScene(s3);
}

void StaticAspect::mp_DefineTriggers() const
{
  const std::shared_ptr<const isaac::ITrigger> t1 = std::make_shared<isaac::CElementPositionTrigger>(isaac::en_GraterThen, ("t1"));
  const std::shared_ptr<const isaac::ITrigger> t2 = std::make_shared<isaac::CElementPositionTrigger>(isaac::en_GraterThen, ("t2"));
  const std::shared_ptr<const isaac::ITrigger> t3 = std::make_shared<isaac::CClickOnShape>(("t3"));
  const std::shared_ptr<const isaac::ITrigger> t4 = std::make_shared<isaac::CElementPositionTrigger>(isaac::en_GraterThen, ("t4"));

  mp_AddTrigger(t1);
  mp_AddTrigger(t2);
  mp_AddTrigger(t3);
  mp_AddTrigger(t4);
}

void StaticAspect::mp_DefineTransientData() const
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
