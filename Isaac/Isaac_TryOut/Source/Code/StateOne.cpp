#include "..\Include\StateOne.h"
#include <ITrigger.h>


StateOne::StateOne(const char* ac_szStateName) :
Foundation::Interfaces::IStaticState(ac_szStateName)
{
  ;
}

void StateOne::mp_InitState(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData)
{
  mv_pRect = new sf::RectangleShape(sf::Vector2f(40, 40));
}

void StateOne::mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl)
{
  const std::shared_ptr<const Foundation::Interfaces::ITrigger> lv_pTrigger = ac_xGlobalTriggersColl->mf_xGetTriggerByName(("t1"));
  const std::shared_ptr<Triggers::CElementPositionTrigger> lv_pPosition =
    std::const_pointer_cast<Triggers::CElementPositionTrigger>(std::static_pointer_cast<const Triggers::CElementPositionTrigger>(lv_pTrigger));

  //std::shared_ptr<Triggers::CElementPositionTrigger> lv_pPosition = ac_xGlobalTriggersColl->mf_xGetTriggerByNameAndType<Triggers::CElementPositionTrigger>(_T("t1"));

  lv_pPosition->mp_InitTrigger(mv_pRect, 800);
}

void StateOne::mp_UpdateState(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{
  av_bReturnedBool_WindowClosed = false;

  mv_pRect->move(1, 0);
}

void StateOne::mp_DrawState(std::shared_ptr<sf::RenderWindow> av_xMainWindow) const
{
  av_xMainWindow->draw(*mv_pRect);
}

void StateOne::mp_Release(std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData, const char* ac_szTriggerName)
{
  delete mv_pRect;
}

StateOne::~StateOne()
{
}
