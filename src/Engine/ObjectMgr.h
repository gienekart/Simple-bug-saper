#include "Engine/Object.h"
#include <list>
#include <string>

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

    void update();
    void redraw();
private:
    std::list<Object*> loadedObjects;
    static ObjectMgr* mgr;
};

#endif
