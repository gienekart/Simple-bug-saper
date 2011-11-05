#include "Leaf.h"

using namespace std;

GLfloat verticesTable[] = {1,1,1,  -1,1,1,  -1,-1,1,  1,-1,1};
GLfloat normalsTable[] = {0,0,1,  0,0,1,  0,0,1,  0,0,1};
GLushort indexesTable[] = {0,1,2,3};

Leaf::Leaf()
{
    vector<GLfloat> tmp(verticesTable, verticesTable + sizeof(verticesTable) / sizeof(GLfloat));
    this->vertices = tmp;
    vector<GLfloat> tmp2(normalsTable, normalsTable + sizeof(normalsTable) / sizeof(GLfloat));
    this->normals = tmp2;
    vector<GLushort> tmp3(verticesTable, verticesTable + sizeof(verticesTable) / sizeof(GLushort));
    this->indexes = tmp3;
}

Leaf::~Leaf()
{

}

void Leaf::draw()
{
    glColor3f(1,1,1);

    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glNormalPointer(GL_FLOAT, 0, &(normals[0]));
    glVertexPointer(3, GL_FLOAT, 0, &(vertices[0]));

    glPushMatrix();
    glTranslatef(this->posX, this->posY, this->pozZ); // move to bottom-left

    glDrawArrays(GL_QUADS, 0, 4);

    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_NORMAL_ARRAY);
}