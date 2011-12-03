#include "GlEngine.h"
#include "Shader.h"

Shader::Shader(std::string name, Shader::shaderData* data):Resource(name)
{
  //TODO make propper shader loading
}

Shader::~Shader()
{
  
}

void Shader::Render()
{
  glUseProgram(this->shaderProgramNumber);
}