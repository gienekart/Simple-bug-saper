#pragma once

#include "Engine/ResourceMgr.h"

class ShaderMgr: public ResourceMgr
{
public:
  static ShaderMgr* getMgr();
private:
  virtual Resource* createResource(const std::string& name);
  Resource* createShaderPart(const std::string& name, GLuint type);
  static ShaderMgr* mgr;
};
