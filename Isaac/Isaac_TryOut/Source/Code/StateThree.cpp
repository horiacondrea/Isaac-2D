#include "StateThree.h"
#include <ClickOnShape.h>
#include <iostream>


StateThree::StateThree(std::string ac_szStateName) :
Foundation::Interfaces::IStaticState(ac_szStateName)
{
  ;
}

void StateThree::mp_InitState(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData)
{
  mv_xMainWindow = av_xMainWindow;
  mv_pCircle = std::make_shared<sf::CircleShape>(30);
  mv_pCircle->setPosition(300, 300);

  std::cout << "State three - Init" << std::endl;
}

void StateThree::mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl)
{
  const std::shared_ptr<const Foundation::Interfaces::ITrigger> lv_pTrigger = ac_xGlobalTriggersColl->mf_xGetTriggerByName(("t3"));
  const std::shared_ptr<Triggers::CClickOnShape> lv_pClickTrigger =
    std::const_pointer_cast<Triggers::CClickOnShape>(std::static_pointer_cast<const Triggers::CClickOnShape>(lv_pTrigger));

  lv_pClickTrigger->InitTrigger(mv_pCircle, mv_xMainWindow);
}

void StateThree::mp_UpdateState(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{
  av_pMainWindow->draw(*mv_pCircle);
}

void StateThree::mp_DrawState(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const
{

}

void StateThree::mp_Release(std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData, std::string ac_szTriggerName)
{

}

StateThree::~StateThree()
{
}
