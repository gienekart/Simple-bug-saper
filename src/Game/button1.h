//#pragma once
#include "Game/button.h"

#ifndef BUTTON1_H
#define BUTTON1_H

class InfoButton: public Button
{
public:
  InfoButton(const char* howMany);
  virtual ~InfoButton();
};

#endif
