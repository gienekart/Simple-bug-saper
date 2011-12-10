#include <vector>
#include <GL/gl.h>
#include "Engine/Mesh.h"

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
  
  void setScale(float scale);
  float getScale();
  
  virtual void Update(float detlatime);
  virtual void Render();
protected:
  Mesh* mesh;
  Material* material;
  float scale;

  Object::position pos;
};

#endif