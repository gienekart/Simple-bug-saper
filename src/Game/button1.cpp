#include <math.h>
#include <iostream>
#include <string>
#include "Game/button1.h"
#include "Engine/MaterialMgr.h"

InfoButton::InfoButton(const char* howMany)
{
  std::string ending = howMany;
  std::string material = "button";
  material += ending;
  this->material = (Material*)MaterialMgr::getMgr()->getResource(material.c_str());
}

InfoButton::~InfoButton()
{
  
}