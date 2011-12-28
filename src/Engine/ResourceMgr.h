#pragma once

#include "Engine/Resource.h"
#include <map>

class ResourceMgr
{
public:
  ResourceMgr();
  ~ResourceMgr();
  Resource* getResource(const std::string& name);
  void add(Resource* toAdd);
protected:
  virtual Resource* createResource(const std::string& name)=0;
  std::map<std::string, Resource*> objects;
};
