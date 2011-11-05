
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

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

    enum GLMode
    {
        FaceMode,
        EdgeMode
    };
private:
    static void redraw();

    int windowHandle;
    static const int height = 300;
    static const int width = 400;
};

#endif