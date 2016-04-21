#pragma once

#include <IStaticScene.h>
#include <ElementPositionTrigger.h>

class SceneTwo : public Foundation::Interfaces::IStaticScene
{
public:
  SceneTwo(std::string ac_szSceneName);

  void mp_InitScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
    std::shared_ptr<const Foundation::CTransientDataCollection>& av_xTransientData);

  void mp_InitTriggers(std::shared_ptr<Foundation::CTriggerCollection>& ac_xGlobalTriggersColl);

  void mp_UpdateScene(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
    std::shared_ptr<const Foundation::CTransientDataCollection>& av_xTransientData,
    sf::Event av_eventSFMLEvent,
    bool& av_bReturnedBool_WindowClosed);

  void mp_DrawScene(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const;

  void mp_Release(std::shared_ptr<const Foundation::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName);

  ~SceneTwo();
};

