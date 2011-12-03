#include "Resource.h"
#include <GL/gl.h>

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture: public Resource
{
public:
  Texture(std::string name);
  ~Texture();
  
  virtual void Render();
  
  void Render(GLenum textureSlotNumber);
  
private:
  GLuint textureNumber;
  GLenum lastChosenTextureNumber;  
};

#endif 