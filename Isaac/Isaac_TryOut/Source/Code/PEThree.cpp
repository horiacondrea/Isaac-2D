#include "PEThree.h"
#include <iostream>


PEThree::PEThree(Foundation::Interfaces::IProcessingElement::ProcessType ac_enumPEType,
  std::string ac_szStateName) :
  Foundation::Interfaces::IProcessingElement(ac_enumPEType, ac_szStateName)
{
    ;
}

void PEThree::mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData)
{
  std::cout << "PE three- Init" << std::endl;
}

void PEThree::mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl,
  const std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xLoacalTriggersColl)
{

}

void PEThree::mp_UpdateState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{

}

void PEThree::mp_DrawState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const
{

}

void PEThree::mp_Release(std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData, std::string ac_szTriggerName)
{

}

PEThree::~PEThree()
{
}
