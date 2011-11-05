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

    void add(Object* objectToAdd);
    void remove(Object* objectToRemove);

    void redraw();
private:
    std::list<Object*> loadedObjects;
};

#endif