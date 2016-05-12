#pragma once

#include "SceneOne.h"
#include "SceneTwo.h"
#include "SceneThree.h"
#include "DynamicScene.h"
#include <defines.h>

#include <IStaticAspect.h>

class EXPORT_API StaticAspect : public isaac::IStaticAspect
{
public:
  StaticAspect();

  void mp_DefineScenes() const;

  void mp_DefineTriggers() const;

  void mp_DefineTransientData() const;

  ~StaticAspect();
};

