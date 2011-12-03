#include "ResourceMgr.h"

#ifndef MATERIALMGR_H
#define MATERIALMGR_H

class MaterialMgr: public ResourceMgr
{
private:
  virtual Resource* createResource(const std::string& name);
};

#endif