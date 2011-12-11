
#include <stdio.h>
#include "Engine/GLHelpers.h"
#include "Engine/ObjectMgr.h"
#include "Engine/ExternLogic.h"

#ifndef GLENGINE_H
#define GLENGINE_H

class GlEngine
{
public:
    static GlEngine* getEngine();
    ~GlEngine();

    void init(int argc, char **argv);
    void changeMode(int );
    void run();
    void setCamera(float posX, float posY, float posZ,
                   float targetX, float targetY, float targetZ);
    void setExternLogic(ExternLogic* logicToCall);
    void setShowMode(GLuint glModeCode);

    static GLuint png_texture(const char *filename);
    static GLuint load_shader(const char *vertexProg, const char *fragmentProg);

    enum GLMode
    {
        FaceMode,
        EdgeMode
    };
private:
    GlEngine();
    static GlEngine* engine;
    static void redraw();
    void initLights();
    static void iddle();
    static char * load_program_string(const char *filename);
    void initBasicMaterial();

    ExternLogic* logicToCall;
    int windowHandle;
    static const int height = 300;
    static const int width = 400;
};
#endif
