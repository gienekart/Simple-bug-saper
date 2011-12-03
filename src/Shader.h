#include "Resource.h"
#include <GL/gl.h>

#ifndef SHADER_H
#define SHADER_H

//TODO all shader

class Shader: public Resource
{
public:  
  struct shaderData
  {
    std::string fragmentShader;
    std::string vertexShader;
  };
  
  Shader(std::string name, Shader::shaderData* data);
  virtual ~Shader();
  
  virtual void Render();
  
private:
  GLuint shaderProgramNumber;
};

#endif