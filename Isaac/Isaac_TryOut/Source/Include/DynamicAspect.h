#pragma once
#include <IDynamicAspect.h>
#include <defines.h>
#ifdef DEBUG
#include <vld.h>
#endif

class EXPORT_API DynamicAspect : public isaac::IDynamicAspect
{
public:
  DynamicAspect();

  void mp_DefineScenesTransitions() const;

  void mp_DefineInitialScene() const;

  ~DynamicAspect();
};

