#include "Engine/Resource.h"
#include <GL/gl.h>

#ifndef MATERIAL_H
#define MATERIAL_H

class Texture;
class Shader;

class Material: public Resource
{
public:
  struct materialData
  {
    Shader* shader;
    Texture* color;
    Texture* color2;
    Texture* normal;
  };
  
  Material(std::string name, Material::materialData* data);
  virtual ~Material();
  
  GLuint getShaderHandler();
  
  virtual void Render();
  
private:
  Material::materialData data;
};

#endif 
