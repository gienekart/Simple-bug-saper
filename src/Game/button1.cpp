#include <math.h>
#include "Game/button1.h"
#include "Engine/MaterialMgr.h"

Button_1::Button_1():time(0)
{
  this->material = (Material*)MaterialMgr::getMgr()->getResource("button1");
}

Button_1::~Button_1()
{
  
}

void Button_1::Update(float deltatime)
{
  this->time += deltatime;
  this->scale = 1 + sin(this->time) * 0.5;
  this->angle = this->time * 0.4;
}