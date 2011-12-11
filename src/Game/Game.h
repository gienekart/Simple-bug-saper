#pragma once

#include "Engine/ExternLogic.h"
#include "Engine/InputHandler.h"
#include "Game/GameLogic.h"

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
  void changeBasicPoint(float deltatime, char stright, char side);
  void updateCameraSets();
  void displayAsWireframe(bool active);
  
  float lookingAngle;
  InputHandler* input;
  GameLogic* logic;
  
  static const float VerticalSpeed;
  static const float BasicPointSpeed;
  static const float MinHeight;
  static const float MaxHeight;
  static const float MinRadius;
  static const float MaxRadius;
};