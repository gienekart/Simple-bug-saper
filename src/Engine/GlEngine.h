#pragma once

#include <stdio.h>
#include "Engine/GLHelpers.h"

class ExternLogic;

class GlEngine
{
public:
    static GlEngine* getEngine();
    ~GlEngine();

    void init(int argc, char **argv);
    void run();
    void setCamera(float posX, float posY, float posZ,
                   float targetX, float targetY, float targetZ);
    void setExternLogic(ExternLogic* logicToCall);
    void setShowMode(GLuint glModeCode);
    
    static bool canWork();

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
    void initBasicMaterial();
    static void RenderingScene();
    static void SelectingScene();
    static void CaclulateSelection(int hits);

    ExternLogic* logicToCall;
    int windowHandle;
    static const int height = 600;
    static const int width = 800;
};
