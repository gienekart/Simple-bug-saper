#pragma once

#include <time.h>

class Timer
{
public:
  static Timer * getTimer();
  ~Timer();
  
  clock_t getTime();
  float getTimeFromLastUpdate();
  void updateTime();
private:
  Timer();
  clock_t currentTime;
  float timeDuration;
  static Timer* timer;
};