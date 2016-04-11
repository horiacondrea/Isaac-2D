#pragma once

#include <IProcessingElement.h>

class PETwo : public Foundation::Interfaces::IProcessingElement
{
public:
  PETwo(Foundation::Interfaces::IProcessingElement::ProcessType ac_enumPEType,
    std::string ac_szStateName);

  void mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
    std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData);

  void mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl,
    const std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xLoacalTriggersColl);

  void mp_UpdateState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
    std::shared_ptr<const Foundation::Interfaces::ITransientData>& ac_xTransientData,
    sf::Event av_eventSFMLEvent,
    bool& av_bReturnedBool_WindowClosed);

  void mp_DrawState(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const;

  void mp_Release(std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData, std::string ac_szTriggerName);

  ~PETwo();
};

