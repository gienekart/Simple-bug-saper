#include <math.h>
#include <iostream>
#include <string>
#include "Game/button1.h"
#include "Engine/MaterialMgr.h"

const float InfoButton::changeSpeed = 0.7;

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

void InfoButton::Update(float detlatime)
{
  this->angle += detlatime * changeSpeed;
}