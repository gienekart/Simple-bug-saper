
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "ObjectMgr.h"

#ifndef GLENGINE_H
#define GLENGINE_H

class GlEngine
{
public:
    GlEngine();
    ~GlEngine();

    void init(int argc, char **argv);
    void changeMode(int );
    void run();
    void setCamera(float posX, float posY, float posZ,
                   float targetX, float targetY, float targetZ);

    Leaf* addFeaf();
    static GLuint png_texture(char *filename);
    static GLuint load_shader(const char *vertexProg, const char *fragmentProg);

    enum GLMode
    {
        FaceMode,
        EdgeMode
    };
private:
    static ObjectMgr* p_mgr;
    static void redraw();
    void initLights();
    static void iddle();
    static char * load_program_string(const char *filename);

    ObjectMgr mgr;

    int windowHandle;
    static const int height = 300;
    static const int width = 400;
};
#endif