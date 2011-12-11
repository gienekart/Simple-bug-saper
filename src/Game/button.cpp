#include "Game/button.h"
#include "Engine/MeshMgr.h"
#include "Engine/Mesh.h"

Button::Button()
{
  this->mesh = (Mesh*)MeshMgr::getMgr()->getResource("button");
  this->setScale(0.2);
}

Button::~Button()
{
  
}
