#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Engine/GlEngine.h"
#include "Engine/Timer.h"
#include "Engine/InputHandler.h"

#define SELECT_BUFF_SIZE 4096 //should be more than enough

static void (*my_glGenProgramsARB)(GLuint, GLuint *) = NULL;
static void (*my_glBindProgramARB)(GLuint, GLuint) = NULL;
static void (*my_glProgramStringARB)(GLuint, GLuint, GLint, const GLbyte *) = NULL;

static void (*my_glActiveTextureARB)(GLenum) = NULL;
static void (*my_glMultiTexCoord3fARB)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;

GlEngine* GlEngine::engine = NULL;
GLuint selectBuf[SELECT_BUFF_SIZE]; 

GlEngine* GlEngine::getEngine()
{
  if (GlEngine::engine == NULL)
  {
    GlEngine::engine = new GlEngine();
  }
  return GlEngine::engine;
}

GlEngine::GlEngine()
{
  //Initialize all critical singletons
  InputHandler::getInputHandler();
}

GlEngine::~GlEngine()
{
    
}

void GlEngine::run()
{
    glutMainLoop(); /* Start GLUT event-processing loop */
    return;
}

void GlEngine::setExternLogic(ExternLogic* logicToCall)
{
  this->logicToCall = logicToCall;
}

void GlEngine::setShowMode(GLuint glModeCode)
{
  glPolygonMode(GL_FRONT_AND_BACK, glModeCode);
}

void GlEngine::redraw()
{
    float daltaTime = ObjectMgr::getMgr()->update();
    GlEngine::engine->logicToCall->frameCall(daltaTime);
    
    SelectingScene();
    RenderingScene();
    
    if(InputHandler::getInputHandler()->isPressedKey(InputHandler::ESC)) //if pressed ESC key 
    {
      exit(0);
    }
}

void GlEngine::RenderingScene()
{
    // clear buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glPushMatrix();
    ObjectMgr::getMgr()->redraw(false);

    glPopMatrix();

    glFinish();
    glutSwapBuffers();
}

void GlEngine::SelectingScene()
{
    Mouse2D position = InputHandler::getInputHandler()->getLastMousePosition();
    GLint viewport[4]; 
    glGetIntegerv(GL_VIEWPORT, viewport);
    glSelectBuffer (SELECT_BUFF_SIZE, selectBuf);
    glRenderMode (GL_SELECT);
    
    //Preppering to selection
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                                // Reset The Projection Matrix
    gluPickMatrix(position.x, viewport[3] - position.y, 30, 30, viewport);
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    
    glInitNames();
    glPushName(0);
    
    //"Rendering" goes here
    ObjectMgr::getMgr()->redraw(true);
       
    glPopMatrix();
    glFinish();
     
     
    int hits = glRenderMode(GL_RENDER);
    int a = hits;
    
    // Returning default settigns
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                                // Reset The Projection Matrix
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);        // Calculate The Aspect Ratio Of The Window
    glMatrixMode(GL_MODELVIEW);
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
    //Light0 is an general ambient for all scene
    //Light1 is a point light which will give us directional light
  
    // set up general ambient light 
    GLfloat lightKa[] = {.3f, .3f, .3f, 1.0f};  // ambient light
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
    
    // set up point light colors (diffuse, specular)
    GLfloat lightKd[] = {.65f, .65f, .65f, 1.0f};  // diffuse light
    GLfloat lightKs[] = {1, 1, 1, 1};           // specular light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightKd);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightKs);

    // position the light
    float lightPos[4] = {10, 3, 0, 1}; // positional light
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos);

    glEnable(GL_LIGHT0); 
    glEnable(GL_LIGHT1);                       // MUST enable each light source after configuration
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
    glutKeyboardFunc(&(InputHandler::keyPressed));
    glutKeyboardUpFunc(&(InputHandler::keyUp));
    glutSpecialFunc(&(InputHandler::keySpecialUp));
    glutSpecialUpFunc(&(InputHandler::keySpecialPressed));
    glutMouseFunc(&(InputHandler::MouseButton));
    glutMotionFunc(&(InputHandler::MouseMotion));
    glutPassiveMotionFunc(&(InputHandler::MouseMotion));
    glutIdleFunc(&(GlEngine::iddle));

    // enable /disable features
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_SMOOTH);

     // track material ambient and diffuse from surface color, call it before glEnable(GL_COLOR_MATERIAL)
    //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_COLOR_MATERIAL);

    glClearColor(0, 0, 0, 1);                   // background color
    //glClearStencil(0);                          // clear stencil buffer
    glClearDepth(1.0f);                         // 0 is near, 1 is far
    glDepthFunc(GL_LEQUAL);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                                // Reset The Projection Matrix

    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);        // Calculate The Aspect Ratio Of The Window
    glMatrixMode(GL_MODELVIEW);

    this->initLights();
    this->initBasicMaterial();
    
    //initialize other components
}

void GlEngine::initBasicMaterial()
{
     GLfloat material_Ka[] = {1.f, 1.f, 1.f, 1.0f};
     GLfloat material_Kd[] = {1.f, 1.f, 1.f, 1.0f};
     GLfloat material_Ks[] = {1.f, 1.f, 1.f, 1.0f};
     GLfloat material_Ke[] = {1.f, 1.f, 1.f, 1.0f};
     GLfloat material_Se = 20.0f;

     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_Ka);
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_Kd);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_Ks);
     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_Ke);
     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, material_Se);
}