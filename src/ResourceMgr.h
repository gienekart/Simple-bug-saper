#include "Resource.h"
#include <map>

#ifndef RESOURCEMGR_H
#define RESOURCEMGR_H

class ResourceMgr
{
public:
  ResourceMgr();
  ~ResourceMgr();
  Resource* getResource(const std::string& name);
private:
  virtual Resource* createResource(const std::string& name)=0;
  std::map<std::string, Resource*> objects;
};

#endif