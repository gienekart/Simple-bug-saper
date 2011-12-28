#pragma once

#include "Engine/ResourceMgr.h"

class MeshMgr: public ResourceMgr
{
public:
  static MeshMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  static MeshMgr* mgr;
};
