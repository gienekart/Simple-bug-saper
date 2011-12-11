#pragma once

#include "Engine/Object.h"

class GameLogic;

class LadyBug : public Object
{
public:
  LadyBug(GameLogic* logicToInform, int col, int row);
  ~LadyBug();
  
  void Click();
  void NeightbourCall();
  
  virtual void Update(float deltaTime);
  
private:
  enum ClickedMeaning
  {
    notClicked,
    ClikkedOnce, //should change colour
    ClickedTwice, //should fly
  };
  
  GameLogic* logicToInform;
  float colorMix;
  ClickedMeaning state;
  float animationTime;
  bool informedAboutFly;
  bool isFlying;
  int col;
  int row;
  
  static const float colorAnimationLenght;
  static const float flyAnimationLenght;
  static const float flyAnimationHeight;
  static const float informationDelay;
};