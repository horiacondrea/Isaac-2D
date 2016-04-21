#include "SceneTwo.h"
#include <iostream>


SceneTwo::SceneTwo(std::string ac_szSceneName) :
Foundation::Interfaces::IStaticScene(ac_szSceneName)
{
  ;
}

void SceneTwo::mp_InitScene(std::shared_ptr<sf::RenderWindow> av_xMainWindow,
  std::shared_ptr<const Foundation::CTransientDataCollection>& av_xTransientData)
{
  std::cout << "Scene two - Init" << std::endl;
}

void SceneTwo::mp_InitTriggers(std::shared_ptr<Foundation::CTriggerCollection>& ac_xGlobalTriggersColl)
{

}

void SceneTwo::mp_UpdateScene(std::shared_ptr<sf::RenderWindow> av_pMainWindow,
  std::shared_ptr<const Foundation::CTransientDataCollection>& av_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{

}

void SceneTwo::mp_DrawScene(std::shared_ptr<sf::RenderWindow> av_pMainWindow) const
{

}

void SceneTwo::mp_Release(std::shared_ptr<const Foundation::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName)
{

}

SceneTwo::~SceneTwo()
{
}
