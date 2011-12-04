#include <fstream>
#include <sstream>

#include "Shader.h"
#include "ShaderMgr.h"

std::string fragment("fragment");
std::string vertex("vertex");

Resource* ShaderMgr::createResource(const std::string& name)
{
  //opening file with shader data
  std::string fileExtenction(".shad");
  std::string fileName = name + fileExtenction;
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
}