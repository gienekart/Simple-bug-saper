#include "Engine/GlEngine.h"
#include "Engine/Material.h"

Material::Material(std::string name, Material::materialData* data) : Resource(name), data(*data)
{
}

Material::~Material()
{

}

GLuint Material::getShaderHandler()
{
  return this->data.shader->getShaderNumber();
}

void Material::Render()
{
  //load shader
  this->data.shader->Render();
  GLuint shaderNumber = getShaderHandler();

  //load textures to propper slots
  if(this->data.color != NULL)
  {
    GLint texture = glGetUniformLocationARB(shaderNumber, "texture0");
    //glActiveTextureARB(GL_TEXTURE0_ARB);
    this->data.color->Render();
    glUniform1iARB(texture, 0);
  }
  if(this->data.color2 != NULL)
  {
    //GLuint texture = glGetUniformLocationARB(shaderNumber, "texture0");
    this->data.color2->Render();
    //glUniform1iARB(texture, 1);
  }
  if(this->data.normal != NULL)
  {
    //GLuint texture = glGetUniformLocationARB(shaderNumber, "texture0");
    this->data.normal->Render();
    //glUniform1iARB(texture, 2);
  }
}
