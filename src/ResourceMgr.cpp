#include "ResourceMgr.h"

ResourceMgr::ResourceMgr()
{
  
}

ResourceMgr::~ResourceMgr()
{
  
}

void ResourceMgr::add(Resource* toAdd)
{
    this->objects[toAdd->getName()] = toAdd;
}

Resource* ResourceMgr::getResource(const std::string& name)
{
  Resource* res = this->objects[name];
  if(res == NULL)
  {
    res = this->createResource(name);
    this->add(res);
  }
  
  return res;
}