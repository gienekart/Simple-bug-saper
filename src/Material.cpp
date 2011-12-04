#include "Material.h"

Material::Material(std::string name, Material::materialData* data) : Resource(name), data(*data)
{
}

Material::~Material()
{

}

void Material::Render()
{
  //load shader
  this->data.shader->Render();

  //enable texture
  glEnable(GL_TEXTURE_2D);

  //load textures to propper slots
  this->data.color->Render(GL_TEXTURE0);
  this->data.color2->Render(GL_TEXTURE1);
  this->data.normal->Render(GL_TEXTURE2);
}
