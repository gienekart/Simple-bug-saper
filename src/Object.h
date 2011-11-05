#include <vector>
#include <GL/glut.h>

#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    Object();
    virtual ~Object();

    void setPosition(float x, float y, float z);
    virtual void draw();
protected:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normals;
    std::vector<GLushort> indexes;

    float posX;
    float posY;
    float pozZ;
};

#endif