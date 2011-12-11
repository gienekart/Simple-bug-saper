//#pragma once
#include "Game/button.h"

#ifndef BUTTON1_H
#define BUTTON1_H

class InfoButton: public Button
{
public:
  InfoButton(const char* howMany);
  virtual ~InfoButton();
  
  virtual void Update(float detlatime);
  
private:
  static const float changeSpeed;
};

#endif
