#include "Game/ladybug.h"
#include "Engine/MeshMgr.h"
#include "Engine/MaterialMgr.h"

LadyBug::LadyBug()
{
  this->mesh = (Mesh*)MeshMgr::getMgr()->getResource("ladybug");
  this->material = (Material*)MaterialMgr::getMgr()->getResource("ladybug");
  this->scale = 0.4;
}

LadyBug::~LadyBug()
{
  
}

void LadyBug::Click()
{
  
}