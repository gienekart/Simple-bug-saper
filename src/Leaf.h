#include "Object.h"

#ifndef LEAF_H
#define LEAF_H

class Leaf : public Object
{
public:
    Leaf();
    virtual ~Leaf();

    virtual void draw();
private:

    static GLuint shaderNum;
    Mesh* mesh;
};

#endif