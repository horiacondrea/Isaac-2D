#pragma once
#include <IDynamicAspect.h>
#include "DynamicAspect.h"
#include "StaticAspect.h"
#include <Game.h>

extern "C"
{
  __declspec (dllexport) int CreateGame();

};