#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLee.h>
#include "GlEngine.h"
#include "load_png.h"

ObjectMgr* GlEngine::p_mgr = 0;
static void (*my_glGenProgramsARB)(GLuint, GLuint *) = NULL;
static void (*my_glBindProgramARB)(GLuint, GLuint) = NULL;
static void (*my_glProgramStringARB)(GLuint, GLuint, GLint, const GLbyte *) = NULL;

static void (*my_glActiveTextureARB)(GLenum) = NULL;
static void (*my_glMultiTexCoord3fARB)(GLenum, GLfloat, GLfloat, GLfloat) = NULL;

GlEngine::GlEngine()
{
    GlEngine::p_mgr = &(this->mgr);
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
    // clear buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glPushMatrix();
    GlEngine::p_mgr->redraw();

    glPopMatrix();

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
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);

     // track material ambient and diffuse from surface color, call it before glEnable(GL_COLOR_MATERIAL)
    //glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    //glEnable(GL_COLOR_MATERIAL);

    glClearColor(0, 0, 0, 0);                   // background color
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

    this->initLights();
}

GLuint GlEngine::png_texture(char *filename)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	GLuint tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	int w, h;
	GLubyte *pixels = (GLubyte *)load_png(filename, &w, &h);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	free(pixels);

	return tex;
}

GLuint GlEngine::load_shader(const char* vertexProg, const char* fragmentProg)
{
   GLuint   program_object;  // a handler to the GLSL program used to update
   GLuint   vertex_shader;   // a handler to vertex shader. This is used internally 
   GLuint   fragment_shader; // a handler to fragment shader. This is used internally too
   
   program_object  = glCreateProgram();    // creating a program object
   vertex_shader   = glCreateShader(GL_VERTEX_SHADER);   // creating a vertex shader object
   fragment_shader = glCreateShader(GL_FRAGMENT_SHADER); // creating a fragment shader object
   //printProgramInfoLog(program_object);

   if (vertexProg != NULL)
   {
     glShaderSource(vertex_shader, 1, &vertexProg, NULL); // assigning the vertex source

     // compiling and attaching the vertex shader onto program
     glCompileShader(vertex_shader);
     glAttachShader(program_object, vertex_shader);
     //printProgramInfoLog(program_object);   // verifies if all this is ok so far
   }

   if (fragmentProg != NULL)
   {
     glShaderSource(fragment_shader, 1, &fragmentProg, NULL); // assigning the fragment source
     //printProgramInfoLog(program_object);   // verifies if all this is ok so far


     // compiling and attaching the fragment shader onto program
     glCompileShader(fragment_shader);
     glAttachShader(program_object, fragment_shader);
     //printProgramInfoLog(program_object);   // verifies if all this is ok so far
   }

   // Link the shaders into a complete GLSL program.
   glLinkProgram(program_object);
   //printProgramInfoLog(program_object);   // verifies if all this is ok so far

   // some extra code for checking if all this initialization is ok
   GLint prog_link_success;
   glGetObjectParameterivARB(program_object, GL_OBJECT_LINK_STATUS_ARB, &prog_link_success);
   if (!prog_link_success) {
      fprintf(stderr, "The shaders could not be linked\n");
      exit(1);
   }

   return program_object;
}

Leaf* GlEngine::addFeaf()
{
    Leaf* leaf = new Leaf();
    mgr.add(leaf);
    return leaf;
}
