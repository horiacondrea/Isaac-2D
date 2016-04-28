#include "SceneOne.h"
#include <ITrigger.h>
#include <iostream>

SceneOne::SceneOne(std::string ac_szSceneName) :
isaac::IStaticScene(ac_szSceneName)
{
  ;
}

void SceneOne::mp_InitScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData)
{
  mv_pRect = new sf::RectangleShape(sf::Vector2f(40, 40));

  std::cout << "Scene one - Init" << std::endl;
}

void SceneOne::mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>& ac_xGlobalTriggersColl)
{
  const std::shared_ptr<const isaac::ITrigger> lv_pTrigger = ac_xGlobalTriggersColl->mf_xGetTriggerByName(("t1"));
  const std::shared_ptr<isaac::CElementPositionTrigger> lv_pPosition =
    std::const_pointer_cast<isaac::CElementPositionTrigger>(std::static_pointer_cast<const isaac::CElementPositionTrigger>(lv_pTrigger));

  //std::shared_ptr<Triggers::CElementPositionTrigger> lv_pPosition = ac_xGlobalTriggersColl->mf_xGetTriggerByNameAndType<Triggers::CElementPositionTrigger>(_T("t1"));

  lv_pPosition->mp_InitTrigger(mv_pRect, 200);
}

void SceneOne::mp_UpdateScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{
  av_bReturnedBool_WindowClosed = false;

  mv_pRect->move(1, 0);
}

void SceneOne::mp_DrawScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow) const
{
  av_xMainWindow->draw(*mv_pRect);
}

void SceneOne::mp_Release(std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName)
{
  delete mv_pRect;
}

SceneOne::~SceneOne()
{
}
