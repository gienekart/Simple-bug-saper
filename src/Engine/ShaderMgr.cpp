#include <fstream>
#include <sstream>

#include "Engine/Shader.h"
#include "Engine/ShaderMgr.h"

std::string fragment("fragment");
std::string vertex("vertex");

ShaderMgr* ShaderMgr::mgr = NULL;

ShaderMgr* ShaderMgr::getMgr()
{
  if (ShaderMgr::mgr == NULL)
  {
    ShaderMgr::mgr = new ShaderMgr();
  }
  
  return ShaderMgr::mgr;
}

Resource* ShaderMgr::createResource(const std::string& name)
{
  //opening file with shader data
  std::string fileExtenction(".shad");
  std::string fileName = name + fileExtenction;
  std::ifstream data(fileName.c_str());
  
  //creation of structure
  Shader::shaderData shaderData;
  shaderData.fragmentShader = 0;
  shaderData.vertexShader = 0;
  
  while (data.good())
  {
    //filling
    std::string type;
    std::string code;
    data>>type>>code;
    
    // Check with type of shader program is defined and read it's source.
    if(type == fragment)
    {
      Shader* fragment = (Shader*)this->createShaderPart(code, GL_FRAGMENT_SHADER_ARB);
      shaderData.fragmentShader = fragment->getShaderNumber();
    }
    else if (type == vertex)
    {
      Shader* vertex = (Shader*)this->createShaderPart(code, GL_VERTEX_SHADER_ARB);
      shaderData.vertexShader = vertex->getShaderNumber();
    }
  }
  
  data.close();
  
  Shader* shader = new Shader(name, &shaderData);
  return shader;
}

Resource* ShaderMgr::createShaderPart(const std::string& name, GLuint type)
{
  std::string ShaderCode;
  
  std::ifstream source(name.c_str());
  std::stringstream buffer;
  buffer << source.rdbuf();
  ShaderCode = buffer.str();
  source.close();
  
  Resource* shaderPart = new Shader(name, type, ShaderCode.c_str());
  this->add(shaderPart);
  return shaderPart;
}
