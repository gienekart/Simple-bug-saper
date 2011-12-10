#include "Engine/Resource.h"
#include "Engine/Texture.h"
#include "Engine/Shader.h"
#include <GL/gl.h>

#ifndef MATERIAL_H
#define MATERIAL_H

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
  
  virtual void Render();
  
private:
  Material::materialData data;
};

#endif 
