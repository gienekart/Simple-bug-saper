
#include <stdio.h>
#include "Engine/GLHelpers.h"
#include "Engine/ObjectMgr.h"

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

    static GLuint png_texture(const char *filename);
    static GLuint load_shader(const char *vertexProg, const char *fragmentProg);

    enum GLMode
    {
        FaceMode,
        EdgeMode
    };
private:
    static void redraw();
    void initLights();
    static void iddle();
    static char * load_program_string(const char *filename);

    int windowHandle;
    static const int height = 300;
    static const int width = 400;
};
#endif
