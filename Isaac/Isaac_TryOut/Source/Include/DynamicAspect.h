#pragma once
#include <IDynamicAspect.h>
#include <common/defines.h>
#ifdef DEBUG
#include <vld.h>
#endif

class EXPORT_API DynamicAspect : public Foundation::Interfaces::IDynamicAspect
{
public:
  DynamicAspect();

  void mp_Define_States_Transitions() const;

  void mp_Define_Initial_State() const;

  ~DynamicAspect();
};

