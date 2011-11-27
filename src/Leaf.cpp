#include "Leaf.h"
#include "GlEngine.h"
#include <iostream>
#include <GLee.h>

using namespace std;

GLuint Leaf::shaderNum = 0;

GLfloat verticesTable[] = {1,1,1,  -1,1,1,  -1,-1,1,  1,-1,1};
GLfloat normalsTable[] = {0,0,1,  0,0,1,  0,0,1,  0,0,1};
GLfloat colorsTable[] = {1,1,1,  1,1,0,  1,0,0,  1,0,1};
GLfloat coordTable[] = {0,1,  1,1,  1,0, 0,0};
GLushort indexesTable[] = {0,1,2,0,2,3};

// a simple vertex shader source
// this just rotates a quad 45°
static const char *vertex_source = {
"void main(){"
"  float PI = 3.14159265358979323846264;"
"  float angle = 45.0;"
"  float rad_angle = angle*PI/180.0;"
""
"  vec4 a = gl_Vertex;"
"  vec4 b = a;"
""
"  b.x = a.x*cos(rad_angle) - a.y*sin(rad_angle);"
"  b.y = a.y*cos(rad_angle) + a.x*sin(rad_angle);"
"gl_Position = gl_ModelViewProjectionMatrix*b;"
"}"
};

// a simple fragment shader source
// this change the fragment's color by yellow color
static const char *fragment_source = {
"void main(void){"
"   gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);"
"}"
};

Leaf::Leaf()
{
    vector<GLfloat> tmp(verticesTable, verticesTable + sizeof(verticesTable) / sizeof(GLfloat));
    this->vertices = tmp;
    vector<GLfloat> tmp2(normalsTable, normalsTable + sizeof(normalsTable) / sizeof(GLfloat));
    this->normals = tmp2;
    vector<GLushort> tmp3(indexesTable, indexesTable + sizeof(indexesTable) / sizeof(GLushort));
    this->indexes = tmp3;
    vector<GLfloat> tmp5(coordTable, coordTable + sizeof(coordTable) / sizeof(GLfloat));
    this->coords = tmp5;
    this->textureNumber = GlEngine::png_texture("lisc.png");
    if(Leaf::shaderNum == 0)
      Leaf::shaderNum = GlEngine::load_shader(NULL, fragment_source);
}

Leaf::~Leaf()
{

}

void Leaf::draw()
{
    glUseProgram(Leaf::shaderNum);
    glBindTexture(GL_TEXTURE_2D, this->textureNumber);
    //glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    //glNormalPointer(GL_FLOAT, 0, &(normals[0]));
    glVertexPointer(3, GL_FLOAT, 0, &(vertices[0]));
    glTexCoordPointer(2, GL_FLOAT, 0, &(coords[0]));

    glPushMatrix();
    glTranslatef(this->posX, this->posY, this->pozZ); // move to bottom-left

    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, indexes.size(), GL_UNSIGNED_SHORT, &(indexes[0]));

    glPopMatrix();

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    //glDisableClientState(GL_NORMAL_ARRAY);
    glFlush();
}