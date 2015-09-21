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
  const std::shared_ptr<const Foundation::CTransition> tra1 = mf_xDefineTransition(_T("State1"), _T("t1"), _T("State3"));

  const std::shared_ptr<const Foundation::CTransition> tra2 = mf_xDefineTransition(_T("State2"), _T("t2"), _T("State1"));

  const std::shared_ptr<const Foundation::CTransition> tra3 = mf_xDefineTransition(_T("State3"), _T("t3"), _T("Dyn"));

  const std::shared_ptr<const Foundation::CTransition> tra4 = mf_xDefineTransition(_T("Dyn"), _T("t4"), _T("Dyn"));

  mp_AddTransition(_T("tra1"), tra1);
  mp_AddTransition(_T("tra2"), tra2);
  mp_AddTransition(_T("tra3"), tra3);
  mp_AddTransition(_T("tra4"), tra4);
}

void DynamicAspect::mp_Define_Initial_State() const
{
  mv_pInitialState = mf_xDefineInitialState(_T("State1"));
}

DynamicAspect::~DynamicAspect()
{
}
