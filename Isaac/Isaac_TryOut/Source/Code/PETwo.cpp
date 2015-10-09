#include "PETwo.h"


PETwo::PETwo(Foundation::Interfaces::IProcessingElement::ProcessType ac_enumPEType,
  const char* ac_szStateName) :
Foundation::Interfaces::IProcessingElement(ac_enumPEType, ac_szStateName)
{
}

void PETwo::mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData)
{

}

void PETwo::mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl,
  const std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xLoacalTriggersColl)
{

}

void PETwo::mp_UpdateState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{

}

void PETwo::mp_DrawState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const
{

}

void PETwo::mp_Release(std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData, const char* ac_szTriggerName)
{

}

PETwo::~PETwo()
{
}
