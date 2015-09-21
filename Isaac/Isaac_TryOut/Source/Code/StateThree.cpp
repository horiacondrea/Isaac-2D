#include "..\Include\StateThree.h"


StateThree::StateThree(const CString& ac_szStateName) :
Foundation::Interfaces::IStaticState(ac_szStateName)
{
  ;
}

void StateThree::mp_InitState(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData)
{

}

void StateThree::mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl)
{

}

void StateThree::mp_UpdateState(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{

}

void StateThree::mp_DrawState(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const
{

}

void StateThree::mp_Release()
{

}

StateThree::~StateThree()
{
}
