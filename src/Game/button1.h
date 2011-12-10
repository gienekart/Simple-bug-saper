//#pragma once
#include "Game/button.h"

#ifndef BUTTON1_H
#define BUTTON1_H

class Button_1: public Button
{
public:
  Button_1();
  virtual ~Button_1();
  
  virtual void Update(float deltatime);
private:
  float time;  
};

#endif
