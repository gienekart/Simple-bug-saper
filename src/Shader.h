#include "Resource.h"

#ifndef SHADER_H
#define SHADER_H

//TODO all shader

class Shader: public Resource
{
public:  
  Shader(std::string name);
  virtual ~Shader();
  
  virtual void Render();
  
private:
};

#endif