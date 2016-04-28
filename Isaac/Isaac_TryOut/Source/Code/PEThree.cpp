#include "PEThree.h"
#include <iostream>


PEThree::PEThree(isaac::IProcessingElement::ProcessType ac_enumPEType,
  std::string ac_szSceneName) :
  isaac::IProcessingElement(ac_enumPEType, ac_szSceneName)
{
    ;
}

void PEThree::mp_InitProcess(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const isaac::CTransientDataCollection>& ac_xTransientData)
{
  std::cout << "PE three- Init" << std::endl;
}

void PEThree::mp_InitTriggers(std::shared_ptr<isaac::CTriggerCollection>& ac_xGlobalTriggersColl,
  const std::shared_ptr<isaac::CTriggerCollection>& ac_xLoacalTriggersColl)
{

}

void PEThree::mp_UpdateScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow,
  std::shared_ptr<const isaac::CTransientDataCollection>& ac_xTransientData,
  sf::Event av_eventSFMLEvent,
  bool& av_bReturnedBool_WindowClosed)
{

}

void PEThree::mp_DrawScene(std::shared_ptr<sf::RenderWindow> ac_xMainWindow) const
{

}

void PEThree::mp_Release(std::shared_ptr<const isaac::CTransientDataCollection>& av_xTransientData, std::string ac_szTriggerName)
{

}

PEThree::~PEThree()
{
}
