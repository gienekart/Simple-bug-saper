#include "GlEngine.h"
#include "Shader.h"

Shader::Shader(std::string name, Shader::shaderData* data):Resource(name)
{
  this->shaderProgramNumber = GlEngine::load_shader(data->vertexShader.c_str(), 
      data->fragmentShader.c_str()); 
}

Shader::~Shader()
{
  
}

void Shader::Render()
{
  glUseProgram(this->shaderProgramNumber);
}