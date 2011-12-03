#include "ObjectMgr.h"

using namespace std;

ObjectMgr::ObjectMgr()
{

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