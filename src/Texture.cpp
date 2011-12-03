#include "Texture.h"

Texture::Texture(std::string name, GLuint textureNumber):Resource(name), 
    textureNumber(textureNumber)
{
  //TODO Make some reading texture with given name
}

Texture::~Texture()
{
  
}

void Texture::Render()
{
  glBindTexture(this->lastChosenTextureNumber, this->textureNumber);
}

void Texture::Render(GLenum textureSlotNumber)
{
  this->lastChosenTextureNumber = textureSlotNumber;
  Texture::Render();
}