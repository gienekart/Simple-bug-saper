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
  
  Object(Mesh* mesh);
  Object(Mesh* mesh, float x, float y, float z);
  Object(Mesh* mesh, Object::position pos);
  virtual ~Object();

  void setPosition(float x, float y, float z);
  Object::position getPosition();
  virtual void Render();
protected:
  Mesh* mesh;

  Object::position pos;
};

#endif