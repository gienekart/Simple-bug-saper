#include "ResourceMgr.h"

#ifndef SHADERMGR_H
#define SHADERMGR_H

class ShaderMgr: public ResourceMgr
{
public:
  static ShaderMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  static ShaderMgr* mgr;
};

#endif