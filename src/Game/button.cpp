#include "button.h"
#include "MeshMgr.h"

Button::Button()
{
  this->mesh = (Mesh*)MeshMgr::getMgr()->getResource("button");
}

Button::~Button()
{
  
}