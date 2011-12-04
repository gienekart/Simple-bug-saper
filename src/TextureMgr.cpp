#include "GlEngine.h"
#include "TextureMgr.h"
#include "Texture.h"

TextureMgr* TextureMgr::mgr = NULL;

TextureMgr* TextureMgr::getMgr()
{
  if (TextureMgr::mgr == NULL)
  {
    TextureMgr::mgr = new TextureMgr();
  }
  
  return TextureMgr::mgr;
}


Resource* TextureMgr::createResource(const std::string& name)
{
  //opening file with mesh data
  std::string fileExtenction(".png");
  std::string fileName = name + fileExtenction;
  
  GLuint textureNumber = GlEngine::png_texture(fileName.c_str());
  
  Texture* texture = new Texture(name, textureNumber);
  return texture;
}