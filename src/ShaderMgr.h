#include "ResourceMgr.h"

#ifndef SHADERMGR_H
#define SHADERMGR_H

class ShaderMgr: public ResourceMgr
{
private:
  virtual Resource* createResource(const std::string& name);
};

#endif