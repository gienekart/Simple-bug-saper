#pragma once

#include "Engine/ResourceMgr.h"

class TextureMgr: public ResourceMgr
{
public:
  static TextureMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  static TextureMgr* mgr;
};
