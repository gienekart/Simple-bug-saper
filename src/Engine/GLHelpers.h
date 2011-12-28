#pragma once

#include "GLee.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Engine/load_png.h"

class glHelp
{
public:
  static GLuint MakePngTexture(const char *filename);
  static GLuint MakeShader(GLuint shaderType, const char* shaderCode);
  static GLuint MakeShaderProgram(GLuint fragmentNo=0, GLuint vertexNo=0);
};
