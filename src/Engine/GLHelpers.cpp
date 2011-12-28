#include "Engine/GLHelpers.h"

GLuint glHelp::MakePngTexture(const char *filename)
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

GLuint glHelp::MakeShaderProgram(GLuint fragmentNo, GLuint vertexNo)
{
   GLuint   program_object;  // a handler to the GLSL program used to update  
   program_object  = glCreateProgram();    // creating a program object
   
   if (fragmentNo != 0)
   {
       glAttachShader(program_object, fragmentNo);
   }
   if (vertexNo != 0)
   {
     glAttachShader(program_object, vertexNo);
   }

   // Link the shaders into a complete GLSL program.
   glLinkProgram(program_object);
   //printProgramInfoLog(program_object);   // verifies if all this is ok so far

   // some extra code for checking if all this initialization is ok
   GLint prog_link_success;
   glGetObjectParameterivARB(program_object, GL_OBJECT_LINK_STATUS_ARB, &prog_link_success);
   if (!prog_link_success) {
      //fprintf(stderr, "The shaders could not be linked\n");
      exit(1);
   }

   return program_object;   
}

GLuint glHelp::MakeShader(GLuint shaderType, const char* shaderCode)
{
  GLuint shaderHandler;
  
  shaderHandler = glCreateShader(shaderType); // creating a fragment shader object
  if (shaderHandler != 0)
  {
    glShaderSource(shaderHandler, 1, &shaderCode, NULL); // assigning the fragment source
    //printProgramInfoLog(program_object);   // verifies if all this is ok so far

    // compiling and attaching the fragment shader onto program
    glCompileShader(shaderHandler);
  }
  return shaderHandler;
}
