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
    void addUsable(Object* objectToAdd);
    void remove(Object* objectToRemove);

    float update();
    void redraw(bool isHitMode);
    
    void selectObiectNumber(int number);
private:
    std::list<Object*> loadedObjects;
    std::list<Object*> usableObjects;
    static ObjectMgr* mgr;
};

#endif
