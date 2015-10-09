#pragma once

#include "StateOne.h"
#include "StateTwo.h"
#include "StateThree.h"
#include "DynamicState.h"
#include <common/defines.h>

#include <IStaticAspect.h>

class EXPORT_API StaticAspect : public Foundation::Interfaces::IStaticAspect
{
public:
  StaticAspect();

  void mp_Define_States() const;

  void mp_Define_Triggers() const;

  void mp_Define_Transient_Data() const;

  ~StaticAspect();
};

