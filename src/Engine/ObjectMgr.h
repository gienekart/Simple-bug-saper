#include "Object.h"
#include "Leaf.h"
#include "button1.h"
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
    
    Leaf* addLeaf();
    Button_1* addButton_1();

    void update();
    void redraw();
private:
    std::list<Object*> loadedObjects;
    static ObjectMgr* mgr;
};

#endif