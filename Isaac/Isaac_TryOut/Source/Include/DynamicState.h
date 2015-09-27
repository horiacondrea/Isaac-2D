#pragma once

#include <IDynamicState.h>

class DynamicState : public Foundation::Interfaces::IDynamicState
{
public:
  DynamicState(const char* ac_szStateName);

  void mp_DefineProcess() const;

  ~DynamicState();
};

