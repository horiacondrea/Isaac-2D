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

  void mp_Define_Scenes_Transitions() const;

  void mp_Define_Initial_Scene() const;

  ~DynamicAspect();
};

