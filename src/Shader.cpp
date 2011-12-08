#include "GlEngine.h"
#include "Shader.h"

Shader::Shader(std::string name, Shader::shaderData* data):Resource(name)
{
  this->shaderProgramNumber = glHelp::LoadShader(data->vertexShader.c_str(), 
      data->fragmentShader.c_str()); 
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