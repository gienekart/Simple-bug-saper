#pragma once

class Mesh;
class Material;

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
  
  void unselect();
  void select();
  
  virtual void Update(float detlatime);
  virtual void Render();
protected:
  Mesh* mesh;
  Material* material;
  float scale;
  float angle;
  float selection;
  float colorMix;

  Object::position pos;
private:
  void registerObject();
};
