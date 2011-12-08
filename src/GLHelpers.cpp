#include "GLHelpers.h"

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


GLuint glHelp::LoadShader(const char* vertexProg, const char* fragmentProg)
{
   GLuint   program_object;  // a handler to the GLSL program used to update
   GLuint   vertex_shader;   // a handler to vertex shader. This is used internally 
   GLuint   fragment_shader; // a handler to fragment shader. This is used internally too
   
   program_object  = glCreateProgram();    // creating a program object
   //printProgramInfoLog(program_object);
   
   if(vertexProg[0] != '\0') //if code is not an empty line
   {
     vertex_shader   = glCreateShader(GL_VERTEX_SHADER);   // creating a vertex shader object
     if (vertexProg != NULL)
     {
       glShaderSource(vertex_shader, 1, &vertexProg, NULL); // assigning the vertex source

       // compiling and attaching the vertex shader onto program
       glCompileShader(vertex_shader);
       glAttachShader(program_object, vertex_shader);
       //printProgramInfoLog(program_object);   // verifies if all this is ok so far
     }
   }
   
   if (fragmentProg[0] != '\0') //if code is not an empty line
   {
     fragment_shader = glCreateShader(GL_FRAGMENT_SHADER); // creating a fragment shader object
     if (fragmentProg != NULL)
     {
       glShaderSource(fragment_shader, 1, &fragmentProg, NULL); // assigning the fragment source
       //printProgramInfoLog(program_object);   // verifies if all this is ok so far


       // compiling and attaching the fragment shader onto program
       glCompileShader(fragment_shader);
       glAttachShader(program_object, fragment_shader);
       //printProgramInfoLog(program_object);   // verifies if all this is ok so far
     }
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