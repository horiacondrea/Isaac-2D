#include "Entry.h"

int CreateGame()
{
  std::shared_ptr< isaac::IDynamicAspect> lv_xDynAspect = std::make_shared<DynamicAspect>();

  lv_xDynAspect->mp_Insert_Static_Aspect(std::make_shared<StaticAspect>());

  isaac::CGame::instance().mp_DefineGameAspect(lv_xDynAspect);

  isaac::CGame::instance().mp_Start(("Game"), 800, 600);

  return 0;
}