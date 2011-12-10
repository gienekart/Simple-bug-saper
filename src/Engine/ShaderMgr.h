#include "ResourceMgr.h"

#ifndef SHADERMGR_H
#define SHADERMGR_H

class ShaderMgr: public ResourceMgr
{
public:
  static ShaderMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  Resource* createShaderPart(const std::string& name, GLuint type);
  static ShaderMgr* mgr;
};

#endif