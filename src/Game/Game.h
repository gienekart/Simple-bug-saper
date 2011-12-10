#pragma once

#include "Engine/ExternLogic.h"
#include "Engine/InputHandler.h"

class Game : public ExternLogic
{
public:
  Game();
  ~Game();
  
  virtual void frameCall(float deltaTime);
  
private:
  struct position3D
  {
    float x;
    float y;
    float z;
  } cameraLookingFrom, cameraLookingAt;
  void changeCamera();
  void updateCameraSets();
  InputHandler* input;
};