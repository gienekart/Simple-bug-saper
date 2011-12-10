#include "ObjectMgr.h"
#include "Timer.h"

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

Leaf* ObjectMgr::addLeaf()
{
  Leaf* newObject = new Leaf();
  this->add(newObject);
  return newObject;
}

Button_1* ObjectMgr::addButton_1()
{
  Button_1* newObject = new Button_1();
  this->add(newObject);
  return newObject;
}

void ObjectMgr::remove(Object* objectToRemove)
{
    this->loadedObjects.remove(objectToRemove);
}

void ObjectMgr::update()
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
}

void ObjectMgr::redraw()
{
    list<Object*>::iterator current;
    current = this->loadedObjects.begin();

    list<Object*>::iterator end;
    end = this->loadedObjects.end();

    for(;current != end; current++)
    {
        (*current)->Render();
    }
}