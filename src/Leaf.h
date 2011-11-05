#include "Object.h"

#ifndef LEAF_H
#define LEAF_H

class Leaf
{
public:
    Leaf();
    virtual ~Leaf();

    virtual void setPosition(float x, float y, float z);
    virtual void draw();
};

#endif