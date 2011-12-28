#include "Engine/GlEngine.h"
#include "Engine/Shader.h"

Shader::Shader(std::string name, Shader::shaderData* data):Resource(name)
{
  this->shaderProgramNumber = glHelp::MakeShaderProgram(data->fragmentShader, 
      data->vertexShader);
}


Shader::Shader(std::string name, GLuint type, const char * code):Resource(name)
{
  this->shaderProgramNumber = glHelp::MakeShader(type, code);
}

Shader::~Shader()
{
  
}

const GLuint Shader::getShaderNumber()
{
  return this->shaderProgramNumber;
}

void Shader::Render()
{
  glUseProgram(this->shaderProgramNumber);
}
