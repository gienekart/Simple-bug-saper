#include "MaterialMgr.h"
#include "Material.h"
#include <fstream>

std::string color0("color0");
std::string color1("color1");
std::string normal("normal");
std::string shader("shader");

Resource* MaterialMgr::createResource(const std::string& name)
{
  //opening file with material data
  std::string fileExtenction(".shad");
  std::string fileName = name + fileExtenction;
  std::ifstream data(fileName.c_str());
  
  Material::materialData materialData;
  
    
  while (data.good())
  {
    //filling
    std::string slot;
    std::string value;
    data>>slot>>value;
    
    // Check with type of shader program is defined and read it's source.
    if(slot == color0)
    {
      
    }
    else if (slot == shader)
    {
      
    }
  }
}