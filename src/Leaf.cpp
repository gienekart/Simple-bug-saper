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
  
}