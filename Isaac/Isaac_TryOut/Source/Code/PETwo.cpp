#include "PETwo.h"
#include <iostream>


PETwo::PETwo(isaac::IProcessingElement::ProcessType ac_enumPEType,
  std::string ac_szSceneName) :
isaac::IProcessingElement(ac_enumPEType, ac_szSceneName)
{
}

void PETwo::mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const isaac::CTransientDataCollection>& ac_xTransientData)
{
  std::cout << "PE two- Init" << std::endl;
}

void PETwo::mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>& ac_xGlobalTriggersColl,
  const std::shared_ptr<isaac::CTriggerCollection>& ac_xLoacalTriggersColl)
{

}

void PETwo::mp_UpdateScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const isaac::CTransientDataCollection>& ac_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{

}

void PETwo::mp_DrawScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const
{

}

void PETwo::mp_Release(std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName)
{

}

PETwo::~PETwo()
{
}
