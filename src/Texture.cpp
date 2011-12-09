#include "Texture.h"

Texture::Texture(std::string name, GLuint textureNumber):Resource(name), 
    textureNumber(textureNumber)
{
}

Texture::~Texture()
{
  
}

void Texture::Render()
{
  glBindTexture(GL_TEXTURE_2D, this->textureNumber);
}