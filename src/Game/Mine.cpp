#include "Game/Mine.h"
#include "Engine/MaterialMgr.h"

Mine::Mine()
{
  this->material = (Material*)MaterialMgr::getMgr()->getResource("mine");
}

Mine::~Mine()
{
  
}