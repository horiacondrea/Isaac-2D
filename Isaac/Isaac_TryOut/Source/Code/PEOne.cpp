#include "..\Include\PEOne.h"


PEOne::PEOne(Foundation::Interfaces::IProcessingElement::ProcessType ac_enumPEType,
  const CString& ac_szStateName) :
  Foundation::Interfaces::IProcessingElement(ac_enumPEType, ac_szStateName)
{
    ;
}

void PEOne::mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData)
{

}

void PEOne::mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl,
  std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xLoacalTriggersColl)
{

}

void PEOne::mp_UpdateState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{

}

void PEOne::mp_DrawState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const
{

}

void PEOne::mp_Release()
{

}

PEOne::~PEOne()
{
}
