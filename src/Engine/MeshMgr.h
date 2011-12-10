#include "ResourceMgr.h"

#ifndef MESHMGR_H
#define MESHMGR_H

class MeshMgr: public ResourceMgr
{
public:
  static MeshMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  static MeshMgr* mgr;
};

#endif