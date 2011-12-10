#include "Game/button1.h"
#include "Engine/MaterialMgr.h"

Button_1::Button_1()
{
  this->material = (Material*)MaterialMgr::getMgr()->getResource("button1");
}

Button_1::~Button_1()
{
  
}
