#include "ResourceMgr.h"

#ifndef TEXTUREMGR_H
#define TEXTUREMGR_H

class TextureMgr: public ResourceMgr
{
private:
  virtual Resource* createResource(const std::string& name);
};

#endif