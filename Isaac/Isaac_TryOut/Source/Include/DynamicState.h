#pragma once

#include <IDynamicState.h>

class DynamicState : public Foundation::Interfaces::IDynamicState
{
public:
  DynamicState(const CString& ac_szStateName);

  void mp_DefineProcess() const;

  ~DynamicState();
};

