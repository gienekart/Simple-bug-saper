
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

    enum GLMode
    {
        FaceMode,
        EdgeMode
    };
private:
    static ObjectMgr* p_mgr;
    static void redraw();
    void initLights();

    ObjectMgr mgr;

    int windowHandle;
    static const int height = 300;
    static const int width = 400;
};
#endif