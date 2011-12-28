#include "Engine/GLHelpers.h"
#include "Engine/Object.h"
#include "Engine/ObjectMgr.h"
#include "Engine/Mesh.h"
#include "Engine/Material.h"

Object::Object() : mesh(NULL), material(NULL), scale(1), angle(0), selection(0), 
    colorMix(0)
{
  this->pos.x = 0;
  this->pos.y = 0;
  this->pos.z = 0;
  registerObject();
}

Object::Object(float x, float y, float z) : mesh(NULL), material(NULL), scale(1), 
    angle(0), selection(0), colorMix(0)
{
  this->pos.x = x;
  this->pos.y = y;
  this->pos.z = z;
  registerObject();
}

Object::Object(Object::position pos) : mesh(NULL), material(NULL), pos(pos), scale(1), 
    angle(0), selection(0), colorMix(0)
{
  registerObject();
}

Object::~Object()
{

}

void Object::setPosition(float x, float y, float z)
{
  this->pos.x = x;
  this->pos.y = y;
  this->pos.z = z;
}

void Object::setScale(float scale)
{
  this->scale = scale;
}

float Object::getScale()
{
  return this->scale;
}

void Object::Update(float detlatime)
{
  
}

void Object::Render()
{
  //setting position
  glPushMatrix();
  glTranslatef(this->pos.x, this->pos.y, this->pos.z);

  //setting up material
  this->material->Render();
  
  //Setting object scale
  GLuint shader = this->material->getShaderHandler();
  GLint scaleLocation = glGetUniformLocationARB(shader, "objectScale");
  glUniform1fARB(scaleLocation, this->scale);
  GLint angleLocation = glGetUniformLocationARB(shader, "objectAngle");
  glUniform1fARB(angleLocation, this->angle);
  GLint selectionLocation = glGetUniformLocationARB(shader, "objectSelection");
  glUniform1fARB(selectionLocation, this->selection);
  GLint textureMixLocation = glGetUniformLocationARB(shader, "textureMix");
  glUniform1fARB(textureMixLocation, this->colorMix);

  //render geometry with current material sets
  this->mesh->Render();

  //remove changes
  glPopMatrix();
  glFlush();
}

void Object::registerObject()
{
  ObjectMgr::getMgr()->add(this);
}

void Object::unselect()
{
  this->selection = 0.0;
}

void Object::select()
{
  this->selection = 1.0;
}