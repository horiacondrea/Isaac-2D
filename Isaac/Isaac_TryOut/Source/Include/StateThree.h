#pragma once

#include <IStaticState.h>
#include <ElementPositionTrigger.h>

class StateThree : public Foundation::Interfaces::IStaticState
{

  std::shared_ptr<sf::RenderWindow> mv_xMainWindow;
  std::shared_ptr<sf::CircleShape> mv_pCircle;

public:
  StateThree(std::string ac_szStateName);

  void mp_InitState(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
    std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData);

  void mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl);

  void mp_UpdateState(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
    std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData,
    sf::Event av_eventSFMLEvent,
    bool& av_bReturnedBool_WindowClosed);

  void mp_DrawState(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const;

  void mp_Release(std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData, std::string ac_szTriggerName);

  ~StateThree();
};

