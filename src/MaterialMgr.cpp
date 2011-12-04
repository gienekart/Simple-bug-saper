#include "MaterialMgr.h"
#include "Material.h"
#include "ShaderMgr.h"
#include "TextureMgr.h"
#include <fstream>

std::string color0("color0");
std::string color1("color1");
std::string normal("normal");
std::string shader("shader");

MaterialMgr* MaterialMgr::mgr = NULL;

MaterialMgr* MaterialMgr::getMgr()
{
  if (MaterialMgr::mgr == NULL)
  {
    MaterialMgr::mgr = new MaterialMgr();
  }
  
  return MaterialMgr::mgr;
}

Resource* MaterialMgr::createResource(const std::string& name)
{
  //opening file with material data
  std::string fileExtenction(".mat");
  std::string fileName = name + fileExtenction;
  std::ifstream data(fileName.c_str());
  
  Material::materialData materialData;
  materialData.color = NULL;
  materialData.color2 = NULL;
  materialData.normal = NULL;
  materialData.shader = NULL;
  
    
  while (data.good())
  {
    //filling
    std::string slot;
    std::string value;
    data>>slot>>value;
    
    // Check with type of shader program is defined and read it's source.
    if(slot == color0)
    {
      materialData.color = (Texture*)TextureMgr::getMgr()->getResource(value);
    }
    else if (slot == shader)
    {
      materialData.shader = (Shader*)ShaderMgr::getMgr()->getResource(value);
    }
  }
  
  Material* material = new Material(name, &materialData);
  return material;
}