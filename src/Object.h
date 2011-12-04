#include <vector>
#include <GL/gl.h>
#include "Mesh.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
  struct position
  {
    float x;
    float y;
    float z;
  };
  
  Object();
  Object(float x, float y, float z);
  Object(Object::position pos);
  virtual ~Object();

  void setPosition(float x, float y, float z);
  Object::position getPosition();
  virtual void Render();
protected:
  Mesh* mesh;
  Material* material;

  Object::position pos;
};

#endif