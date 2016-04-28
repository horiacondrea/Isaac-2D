#pragma once

#include <IDynamicScene.h>

class DynamicScene : public isaac::IDynamicScene
{
public:
  DynamicScene(std::string ac_szSceneName);

  void mp_DefineProcess() const;

  ~DynamicScene();
};

