#include "GlEngine.h"
#include "Object.h"

Object::Object() : mesh(NULL), material(NULL)
{
  this->pos.x = 0;
  this->pos.y = 0;
  this->pos.z = 0;
}

Object::Object(float x, float y, float z) : mesh(NULL), material(NULL)
{
  this->pos.x = x;
  this->pos.y = y;
  this->pos.z = z;
}

Object::Object(Object::position pos) : mesh(NULL), material(NULL), pos(pos)
{

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

void Object::Render()
{
  //setting position
  glPushMatrix();
  glTranslatef(this->pos.x, this->pos.y, this->pos.z);

  //setting up material
  this->material->Render();

  //render geometry with current material sets
  this->mesh->Render();

  //remove changes
  glPopMatrix();
  glFlush();
}