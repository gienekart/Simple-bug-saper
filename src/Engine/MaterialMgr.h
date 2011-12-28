#pragma once

#include "Engine/ResourceMgr.h"

class MaterialMgr: public ResourceMgr
{
public:
  static MaterialMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  static MaterialMgr* mgr;
};
