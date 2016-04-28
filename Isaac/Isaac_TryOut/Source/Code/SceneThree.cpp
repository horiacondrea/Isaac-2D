#include "SceneThree.h"
#include <ClickOnShape.h>
#include <iostream>


SceneThree::SceneThree(std::string ac_szSceneName) :
isaac::IStaticScene(ac_szSceneName)
{
  ;
}

void SceneThree::mp_InitScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData)
{
  mv_xMainWindow = av_xMainWindow;
  mv_pCircle = std::make_shared<sf::CircleShape>(30);
  mv_pCircle->setPosition(300, 300);

  std::cout << "Scene three - Init" << std::endl;
}

void SceneThree::mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>& ac_xGlobalTriggersColl)
{
  const std::shared_ptr<const isaac::ITrigger> lv_pTrigger = ac_xGlobalTriggersColl->mf_xGetTriggerByName(("t3"));
  const std::shared_ptr<isaac::CClickOnShape> lv_pClickTrigger =
    std::const_pointer_cast<isaac::CClickOnShape>(std::static_pointer_cast<const isaac::CClickOnShape>(lv_pTrigger));

  lv_pClickTrigger->InitTrigger(mv_pCircle, mv_xMainWindow);
}

void SceneThree::mp_UpdateScene(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
  std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{
  av_pMainWindow->draw(*mv_pCircle);
}

void SceneThree::mp_DrawScene(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const
{

}

void SceneThree::mp_Release(std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName)
{

}

SceneThree::~SceneThree()
{
}
