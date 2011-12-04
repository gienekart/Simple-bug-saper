#include "GlEngine.h"
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
  GLuint shaderNumber = this->data.shader->getShaderNumber();
  //enable texture
  glEnable(GL_TEXTURE_2D);

  //load textures to propper slots
  if(this->data.color != NULL)
  {
    GLuint texture = glGetUniformLocationARB(shaderNumber, "texture0");
    this->data.color->Render(GL_TEXTURE0);
    glUniform1iARB(texture, 0);
  }
  if(this->data.color2 != NULL)
  {
    //GLuint texture = glGetUniformLocationARB(shaderNumber, "texture0");
    this->data.color2->Render(GL_TEXTURE1);
    //glUniform1iARB(texture, 1);
  }
  if(this->data.normal != NULL)
  {
    //GLuint texture = glGetUniformLocationARB(shaderNumber, "texture0");
    this->data.normal->Render(GL_TEXTURE2);
    //glUniform1iARB(texture, 2);
  }
}
