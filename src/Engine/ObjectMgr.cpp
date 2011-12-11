#include "Engine/ObjectMgr.h"
#include "Engine/Timer.h"

using namespace std;

ObjectMgr* ObjectMgr::mgr = NULL;

ObjectMgr* ObjectMgr::getMgr()
{
  if (ObjectMgr::mgr == NULL)
  {
    ObjectMgr::mgr = new ObjectMgr();
  }
  
  return ObjectMgr::mgr;
}

ObjectMgr::ObjectMgr()
{
  //for propper timer initialisation
  //at the beginning of game
  Timer::getTimer();
}

ObjectMgr::~ObjectMgr()
{

}

void ObjectMgr::add(Object* objectToAdd)
{
    this->loadedObjects.push_back(objectToAdd);
}

void ObjectMgr::remove(Object* objectToRemove)
{
    this->loadedObjects.remove(objectToRemove);
}

float ObjectMgr::update()
{
    Timer::getTimer()->updateTime();
    float deltaTime = Timer::getTimer()->getTimeFromLastUpdate();
    
    list<Object*>::iterator current;
    current = this->loadedObjects.begin();

    list<Object*>::iterator end;
    end = this->loadedObjects.end();

    for(;current != end; current++)
    {
        (*current)->Update(deltaTime);
    } 
    return deltaTime;
}

void ObjectMgr::redraw(bool isHitMode)
{
    int index = 1;
    list<Object*>::iterator current;
    current = this->loadedObjects.begin();

    list<Object*>::iterator end;
    end = this->loadedObjects.end();

    for(;current != end; current++)
    {
      if(isHitMode == true)
      {
        glLoadName(index);
        index++;
      }
        (*current)->Render();
    }
}
