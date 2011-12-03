
#include <iostream>
#include "GlEngine.h"
#include "Leaf.h"

using namespace std;

GLuint Leaf::shaderNum = 0;

GLfloat verticesTable[] = {1,1,1,  -1,1,1,  -1,-1,1,  1,-1,1};
GLfloat normalsTable[] = {0,0,1,  0,0,1,  0,0,1,  0,0,1};
GLfloat colorsTable[] = {1,1,1,  1,1,0,  1,0,0,  1,0,1};
GLfloat coordTable[] = {0,1,  1,1,  1,0, 0,0};
GLushort indexesTable[] = {0,1,2,0,2,3};

// a simple vertex shader source
static const char *vertex_source = {
"void main(){"
"}"
};

// a simple fragment shader source
// this change the fragment's color by yellow color
static const char *fragment_source = {
"uniform sampler2D texture;"
//"varying vec2 tex_coords;"
"void main(void){"
"   gl_FragColor = texture2D(texture, gl_TexCoord[0].st);"
"}"
};

Leaf::Leaf():Object(NULL)
{
    vector<GLfloat> tmp(verticesTable, verticesTable + sizeof(verticesTable) / sizeof(GLfloat));
    //this->vertices = tmp;
    vector<GLfloat> tmp2(normalsTable, normalsTable + sizeof(normalsTable) / sizeof(GLfloat));
    //this->normals = tmp2;
    vector<GLushort> tmp3(indexesTable, indexesTable + sizeof(indexesTable) / sizeof(GLushort));
    //this->indexes = tmp3;
    vector<GLfloat> tmp5(coordTable, coordTable + sizeof(coordTable) / sizeof(GLfloat));
    //this->coords = tmp5;
    //this->textureNumber = GlEngine::png_texture("lisc.png");
    if(Leaf::shaderNum == 0)
      Leaf::shaderNum = GlEngine::load_shader(NULL, fragment_source);
}

Leaf::~Leaf()
{

}

void Leaf::draw()
{
    //Enable shader
    //TODO put thse 2 lines into shader
    glUseProgram(Leaf::shaderNum);
    GLint loc = glGetUniformLocationARB(Leaf::shaderNum,"texture");
    glActiveTexture(GL_TEXTURE0);
    glUniform1iARB(loc, 0);
    
    //enable texture
    glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE0, this->textureNumber);
    
    //enable object properietes
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    
    //filling data
    //glNormalPointer(GL_FLOAT, 0, &(normals[0]));
    //glVertexPointer(3, GL_FLOAT, 0, &(vertices[0]));
    //glTexCoordPointer(2, GL_FLOAT, 0, &(coords[0]));

    //setting position
    glPushMatrix();
    //glTranslatef(this->posX, this->posY, this->pozZ); // move to bottom-left

    //rendering
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    //glDrawElements(GL_TRIANGLES, indexes.size(), GL_UNSIGNED_SHORT, &(indexes[0]));

    glPopMatrix();

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_NORMAL_ARRAY);
    //glFlush();
}