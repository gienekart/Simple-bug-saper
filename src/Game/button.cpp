#include "Game/button.h"
#include "Engine/MeshMgr.h"

Button::Button()
{
  this->mesh = (Mesh*)MeshMgr::getMgr()->getResource("button");
}

Button::~Button()
{
  
}
