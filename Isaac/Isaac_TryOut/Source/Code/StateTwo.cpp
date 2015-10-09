#include "StateTwo.h"


StateTwo::StateTwo(const char* ac_szStateName) :
Foundation::Interfaces::IStaticState(ac_szStateName)
{
  ;
}

void StateTwo::mp_InitState(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData)
{

}

void StateTwo::mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl)
{

}

void StateTwo::mp_UpdateState(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{

}

void StateTwo::mp_DrawState(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const
{

}

void StateTwo::mp_Release(std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData, const char* ac_szTriggerName)
{

}

StateTwo::~StateTwo()
{
}
