#include "..\Include/DynamicAspect.h"
#include <ElementPositionTrigger.h>
#include "..\Include\PEOne.h"
#include "..\Include\PETwo.h"
#include "..\Include\PEThree.h"


DynamicAspect::DynamicAspect()
{
}

void DynamicAspect::mp_Define_States_Transitions() const
{
  const std::shared_ptr<const Foundation::CTransition> tra1 = mf_xDefineTransition(("State1"), ("t1"), ("State3"));
																									   
  const std::shared_ptr<const Foundation::CTransition> tra2 = mf_xDefineTransition(("State2"), ("t2"), ("State1"));
																									   
  const std::shared_ptr<const Foundation::CTransition> tra3 = mf_xDefineTransition(("State3"), ("t3"), ("Dyn"));
																									   
  const std::shared_ptr<const Foundation::CTransition> tra4 = mf_xDefineTransition(("Dyn"),    ("t4"), ("Dyn"));

  mp_AddTransition(("tra1"), tra1);
  mp_AddTransition(("tra2"), tra2);
  mp_AddTransition(("tra3"), tra3);
  mp_AddTransition(("tra4"), tra4);
}

void DynamicAspect::mp_Define_Initial_State() const
{
  mv_pInitialState = mf_xDefineInitialState(("State1"));
}

DynamicAspect::~DynamicAspect()
{
}
