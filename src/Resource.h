#include <string>

#ifndef RESOURCE_H
#define RESOURCE_H

class Resource
{
public:
  Resource(std::string name):name(name){};
  virtual ~Resource(){};
  
  const std::string getName(){return name;};
  
  virtual void Render()=0;
private:
  std::string name;
};

#endif