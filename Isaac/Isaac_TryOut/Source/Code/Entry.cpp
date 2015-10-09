#include "Entry.h"

int CreateGame()
{
  std::shared_ptr< Foundation::Interfaces::IDynamicAspect> lv_xDynAspect = std::make_shared<DynamicAspect>();

  lv_xDynAspect->mp_Insert_Static_Aspect(std::make_shared<StaticAspect>());

  Core::CGame::instance().mp_DefineGameAspect(lv_xDynAspect);

  Core::CGame::instance().mp_Start(("Game"), 800, 600);

  return 0;
}