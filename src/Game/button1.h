//#pragma once
#include "Game/button.h"

#pragma once

class InfoButton: public Button
{
public:
  InfoButton(const char* howMany);
  virtual ~InfoButton();
  
  virtual void Update(float detlatime);
  
private:
  static const float changeSpeed;
};
