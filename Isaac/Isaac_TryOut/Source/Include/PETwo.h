#pragma once

#include <IProcessingElement.h>

class PETwo : public Foundation::Interfaces::IProcessingElement
{
public:
  PETwo(Foundation::Interfaces::IProcessingElement::ProcessType ac_enumPEType,
    std::string ac_szSceneName);

  void mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
    std::shared_ptr<const Foundation::CTransientDataCollection>& ac_xTransientData);

  void mp_InitTriggers(std::shared_ptr<Foundation::CTriggerCollection>& ac_xGlobalTriggersColl,
    const std::shared_ptr<Foundation::CTriggerCollection>& ac_xLoacalTriggersColl);

  void mp_UpdateScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
    std::shared_ptr<const Foundation::CTransientDataCollection>& ac_xTransientData,
    sf::Event av_eventSFMLEvent,
    bool& av_bReturnedBool_WindowClosed);

  void mp_DrawScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const;

  void mp_Release(std::shared_ptr<const Foundation::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName);

  ~PETwo();
};

