#pragma once

#include <IStaticState.h>
#include <ElementPositionTrigger.h>

class StateOne : public Foundation::Interfaces::IStaticState
{
private:
  sf::RectangleShape* mv_pRect;

public:
  StateOne(const CString& ac_szStateName);

  void mp_InitState(std::shared_ptr<sf::RenderWindow> av_xMainWindow, 
                    std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData);

  void mp_InitTriggers(std::shared_ptr<Foundation::Interfaces::ITriggerCollection>& ac_xGlobalTriggersColl);

  void mp_UpdateState(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
                      std::shared_ptr<const Foundation::Interfaces::ITransientData>& av_xTransientData,
                      sf::Event av_eventSFMLEvent,
                      bool& av_bReturnedBool_WindowClosed);

  void mp_DrawState(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const;

  void mp_Release();

  ~StateOne();
};

