#include "ResourceMgr.h"

ResourceMgr::ResourceMgr()
{
  
}

ResourceMgr::~ResourceMgr()
{
  
}

Resource* ResourceMgr::getResource(const std::string& name)
{
  Resource* res = this->objects[name];
  if(res == NULL)
  {
    this->createResource(name);
  }
}