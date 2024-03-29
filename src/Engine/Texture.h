#pragma once

#include "Engine/Resource.h"
#include <GL/gl.h>

class Texture: public Resource
{
public:
  Texture(std::string name, GLuint textureNumber);
  ~Texture();
  
  virtual void Render();
  
private:
  GLuint textureNumber;
  GLenum lastChosenTextureNumber;  
};
