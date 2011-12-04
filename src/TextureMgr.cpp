#include "GlEngine.h"
#include "TextureMgr.h"
#include "Texture.h"

Resource* TextureMgr::createResource(const std::string& name)
{
  //opening file with mesh data
  std::string fileExtenction(".png");
  std::string fileName = name + fileExtenction;
  
  GLuint textureNumber = GlEngine::png_texture(fileName.c_str());
  
  Texture* texture = new Texture(name, textureNumber);
  return texture;
}