#include "Game/Leaf.h"
#include "Engine/MeshMgr.h"
#include "Engine/MaterialMgr.h"

Leaf::Leaf()
{
  this->mesh = (Mesh*)MeshMgr::getMgr()->getResource("leaf");
  this->material = (Material*)MaterialMgr::getMgr()->getResource("leaf");
}

Leaf::~Leaf()
{

}
