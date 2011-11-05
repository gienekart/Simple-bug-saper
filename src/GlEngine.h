
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class GlEngine
{
public:
    GlEngine();
    ~GlEngine();

    void init(int argc, char **argv);
    void changeMode(int );
    void run();

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
