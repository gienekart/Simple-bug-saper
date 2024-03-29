#pragma once

#include "Engine/Resource.h"
#include <GL/gl.h>

class Shader: public Resource
{
public:  
  struct shaderData
  {
    GLuint fragmentShader;
    GLuint vertexShader;
  };
  
  //Constructor for Shader program
  Shader(std::string name, Shader::shaderData* data);
  
  //Constructor for fragment/vertex shader
  Shader(std::string name, GLuint type, const char * code);
  virtual ~Shader();
  
  const GLuint getShaderNumber();
  
  virtual void Render();
  
private:
  GLuint shaderProgramNumber;
};
