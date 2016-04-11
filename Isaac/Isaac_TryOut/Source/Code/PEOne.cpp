#include "PEOne.h"
#include <ElementPositionTrigger.h>

#include <iostream>


PEOne::PEOne(Foundation::Interfaces::IProcessingElement::ProcessType ac_enumPEType,
  std::string ac_szStateName) :
  Foundation::Interfaces::IProcessingElement(ac_enumPEType, ac_szStateName)
{
    ;
}

void PEOne::mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData)
{
  mv_xShape = std::make_shared<sf::ConvexShape>();

  mv_xShape->setPointCount(3);
  mv_xShape->setPoint(0, sf::Vector2f(0, 0));
  mv_xShape->setPoint(1, sf::Vector2f(0, 10));
  mv_xShape->setPoint(2, sf::Vector2f(25, 5));
  mv_xShape->setOutlineColor(sf::Color::Red);
  mv_xShape->setOutlineThickness(5);
  mv_xShape->setPosition(300, 300);

  std::cout << "PE one- Init" << std::endl;
}

void PEOne::mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl,
  const std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xLoacalTriggersColl)
{
  const std::shared_ptr<const Foundation::Interfaces::ITrigger> lv_pTrigger = ac_xLoacalTriggersColl->mf_xGetTriggerByName(("tpe"));
  const std::shared_ptr<Triggers::CElementPositionTrigger> lv_pPosition =
    std::const_pointer_cast<Triggers::CElementPositionTrigger>(std::static_pointer_cast<const Triggers::CElementPositionTrigger>(lv_pTrigger));

  lv_pPosition->mp_InitTrigger(mv_xShape.get(), 500);
}

void PEOne::mp_UpdateState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{
  mv_xShape->move(1, 0);
}

void PEOne::mp_DrawState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const
{
  ac_xMainWindow->draw(*mv_xShape);
}

void PEOne::mp_Release(std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData, std::string ac_szTriggerName)
{

}

PEOne::~PEOne()
{
}
