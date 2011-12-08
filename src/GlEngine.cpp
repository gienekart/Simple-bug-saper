#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GlEngine.h"
#include "Timer.h"

static void (*my_glGenProgramsARB)(GLuint, GLuint *) = NULL;
static void (*my_glBindProgramARB)(GLuint, GLuint) = NULL;
static void (*my_glProgramStringARB)(GLuint, GLuint, GLint, const GLbyte *) = NULL;

static void (*my_glActiveTextureARB)(GLenum) = NULL;
static void (*my_glMultiTexCoord3fARB)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;

GlEngine::GlEngine()
{
}

GlEngine::~GlEngine()
{
    
}

void GlEngine::run()
{
    glutMainLoop(); /* Start GLUT event-processing loop */
    return;
}

void GlEngine::redraw()
{
  ObjectMgr::getMgr()->update();
    // clear buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glPushMatrix();
    ObjectMgr::getMgr()->redraw();

    glPopMatrix();

    glFinish();
    glutSwapBuffers();
}

void GlEngine::iddle()
{
    redraw();
}

void GlEngine::setCamera(float posX, float posY, float posZ, float targetX, float targetY, float targetZ)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(posX, posY, posZ, targetX, targetY, targetZ, 0, 1, 0); // eye(x,y,z), focal(x,y,z), up(x,y,z)
}

void GlEngine::initLights()
{
    // set up light colors (ambient, diffuse, specular)
    GLfloat lightKa[] = {.2f, .2f, .2f, 1.0f};  // ambient light
    GLfloat lightKd[] = {.7f, .7f, .7f, 1.0f};  // diffuse light
    GLfloat lightKs[] = {1, 1, 1, 1};           // specular light
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

    // position the light
    float lightPos[4] = {0, 0, 20, 1}; // positional light
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_LIGHT0);                        // MUST enable each light source after configuration
}

void GlEngine::init(int argc, char **argv)
{
    //window creation
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);

    this->windowHandle = glutCreateWindow(argv[0]);
    
    // register GLUT callback functions void (listenerTyp ::*p_func)()
    glutDisplayFunc(&(GlEngine::redraw));
    //glutTimerFunc(100, timerCB, 100);             // redraw only every given millisec
    //glutReshapeFunc(reshapeCB);
    //glutKeyboardFunc(keyboardCB);
    //glutMouseFunc(mouseCB);
    //glutMotionFunc(mouseMotionCB);
    glutIdleFunc(&(GlEngine::iddle));

    // enable /disable features
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);

     // track material ambient and diffuse from surface color, call it before glEnable(GL_COLOR_MATERIAL)
    //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_COLOR_MATERIAL);

    glClearColor(0, 0, 0, 1);                   // background color
    //glClearStencil(0);                          // clear stencil buffer
    glClearDepth(1.0f);                         // 0 is near, 1 is far
    glDepthFunc(GL_LEQUAL);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                                // Reset The Projection Matrix

    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);        // Calculate The Aspect Ratio Of The Window
    glMatrixMode(GL_MODELVIEW);

    //this->initLights();
    
    //initialize other components
}