#include "Timer.h"

Timer* Timer::timer = NULL;

Timer* Timer::getTimer()
{
  if (Timer::timer == NULL)
  {
    Timer::timer = new Timer();
  }
  return Timer::timer;
}

Timer::Timer()
{
  this->currentTime = clock();
  this->timeDuration = 0;
}

Timer::~Timer()
{
  
}

void Timer::updateTime()
{
  clock_t newTime = clock();
  this->timeDuration = float(newTime - this->currentTime)/CLOCKS_PER_SEC;
  this->currentTime = newTime;
}

float Timer::getTimeFromLastUpdate()
{
  return this->timeDuration;
}

clock_t Timer::getTime()
{
  return clock();
}