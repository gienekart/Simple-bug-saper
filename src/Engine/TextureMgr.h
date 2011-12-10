#include "Engine/ResourceMgr.h"

#ifndef TEXTUREMGR_H
#define TEXTUREMGR_H

class TextureMgr: public ResourceMgr
{
public:
  static TextureMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  static TextureMgr* mgr;
};

#endif
