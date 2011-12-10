#include "Engine/GlEngine.h"
#include "Engine/TextureMgr.h"
#include "Engine/Texture.h"

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
  
  GLuint textureNumber = glHelp::MakePngTexture(fileName.c_str());
  
  Texture* texture = new Texture(name, textureNumber);
  return texture;
}
