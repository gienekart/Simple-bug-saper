#include "ResourceMgr.h"

#ifndef MESHMGR_H
#define MESHMGR_H

class MeshMgr: public ResourceMgr
{
private:
  virtual Resource* createResource(const std::string& name);
};

#endif