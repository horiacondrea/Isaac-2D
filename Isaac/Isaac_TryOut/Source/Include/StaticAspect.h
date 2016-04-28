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

  void mp_Define_Scenes() const;

  void mp_Define_Triggers() const;

  void mp_Define_Transient_Data() const;

  ~StaticAspect();
};

