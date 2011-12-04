#include "ResourceMgr.h"

#ifndef MATERIALMGR_H
#define MATERIALMGR_H

class MaterialMgr: public ResourceMgr
{
public:
  static MaterialMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  static MaterialMgr* mgr;
};

#endif