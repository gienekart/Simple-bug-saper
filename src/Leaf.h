#include "Object.h"

#ifndef LEAF_H
#define LEAF_H

class Leaf : public Object
{
public:
    Leaf();
    virtual ~Leaf();

    virtual void Render();
private:

    static GLuint shaderNum;
    Material* material;
};

#endif