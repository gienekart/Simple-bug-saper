#include <fstream>
#include <sstream>

#include "Shader.h"
#include "ShaderMgr.h"

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
  std::string fileName = name;
  std::ifstream data(fileName.c_str());
  
  //creation of structure
  Shader::shaderData shaderData;
  
  while (data.good())
  {
    //filling
    std::string type;
    std::string code;
    data>>type>>code;
    
    // Check with type of shader program is defined and read it's source.
    if(type == fragment)
    {
      std::ifstream source(code.c_str());
      std::stringstream buffer;
      buffer << source.rdbuf();
      shaderData.fragmentShader = buffer.str();
      source.close();
    }
    else if (type == vertex)
    {
      std::ifstream source(code.c_str());
      std::stringstream buffer;
      buffer << source.rdbuf();
      shaderData.vertexShader = buffer.str();
      source.close();
    }
  }
  
  data.close();
  
  Shader* shader = new Shader(name, &shaderData);
  return shader;
}