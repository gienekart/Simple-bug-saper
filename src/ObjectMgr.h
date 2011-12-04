#include "Object.h"
#include "Leaf.h"
#include <list>

#ifndef OBJECTMGR_H
#define OBJECTMGR_H

class ObjectMgr
{
public:
    ObjectMgr();
    ~ObjectMgr();
    
  static ObjectMgr* getMgr();

    void add(Object* objectToAdd);
    void remove(Object* objectToRemove);

    void redraw();
private:
    std::list<Object*> loadedObjects;
  static ObjectMgr* mgr;
};

#endif