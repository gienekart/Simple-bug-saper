#include "Leaf.h"
#include "MeshMgr.h"
#include "MaterialMgr.h"

Leaf::Leaf()
{
  this->mesh = (Mesh*)MeshMgr::getMgr()->getResource("leaf");
  this->material = (Material*)MaterialMgr::getMgr()->getResource("leaf");
}

Leaf::~Leaf()
{

}