#include "GlEngine.h"
#include "Object.h"

Object::Object(Mesh* mesh):mesh(mesh)
{
  this->pos.x = 0;
  this->pos.y = 0;
  this->pos.z = 0;
}

Object::Object(Mesh* mesh, float x, float y, float z):mesh(mesh)
{
  this->pos.x = x;
  this->pos.y = y;
  this->pos.z = z;
}

Object::Object(Mesh* mesh, Object::position pos):mesh(mesh), pos(pos)
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
    
    this->mesh->Render();
    
    //remove changes
    glPopMatrix();
}