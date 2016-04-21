#include "DynamicAspect.h"
#include <ElementPositionTrigger.h>
#include "PEOne.h"
#include "PETwo.h"
#include "PEThree.h"


DynamicAspect::DynamicAspect()
{
}

void DynamicAspect::mp_Define_Scenes_Transitions() const
{
  const std::shared_ptr<const Foundation::CTransition> tra1 = mf_xDefineTransition(("Scene1"), ("t1"), ("Scene3"));
																									   
  const std::shared_ptr<const Foundation::CTransition> tra2 = mf_xDefineTransition(("Scene2"), ("t2"), ("Scene1"));
																									   
  const std::shared_ptr<const Foundation::CTransition> tra3 = mf_xDefineTransition(("Scene3"), ("t3"), ("Dyn"));
																									   
  const std::shared_ptr<const Foundation::CTransition> tra4 = mf_xDefineTransition(("Dyn"),    ("t4"), ("Dyn"));

  mp_AddTransition(("tra1"), tra1);
  mp_AddTransition(("tra2"), tra2);
  mp_AddTransition(("tra3"), tra3);
  mp_AddTransition(("tra4"), tra4);
}

void DynamicAspect::mp_Define_Initial_Scene() const
{
  mv_pInitialScene = mf_xDefineInitialScene(("Scene1"));
}

DynamicAspect::~DynamicAspect()
{
}
