#pragma once

#include "Engine/Resource.h"
#include <vector>
#include <GL/gl.h>

class Mesh: public Resource
{
public:  
  struct meshData
  {
    std::vector<GLfloat> vertexPosition;
    std::vector<GLfloat> textureCoords;
    std::vector<GLfloat> vertexNormals;
    std::vector<GLushort> vertexIndexes;
  };
  
  Mesh(std::string name, const Mesh::meshData* data);
  virtual ~Mesh();
  
  virtual void Render();
  
private:
    std::vector<GLfloat> vertexPosition;
    std::vector<GLfloat> textureCoords;
    std::vector<GLfloat> vertexNormals;
    std::vector<GLushort> vertexIndexes;
};
