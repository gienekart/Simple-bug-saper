#include "Object.h"

#ifndef LEAF_H
#define LEAF_H

class Leaf : public Object
{
public:
    Leaf();
    virtual ~Leaf();

    virtual void draw();
};

#endif