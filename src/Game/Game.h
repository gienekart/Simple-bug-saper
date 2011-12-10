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
  void changeCameraHorisontal();
  void changeCameraVertical(float deltaTime, bool goingUp);
  void updateCameraSets();
  InputHandler* input;
  static const float VerticalSpeed;
  static const float MinHeight;
  static const float MaxHeight;
  static const float MinRadius;
  static const float MaxRadius;
};