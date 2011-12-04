
#include "Mesh.h"

Mesh::Mesh(std::string name, const Mesh::meshData* data, Material* material) :
Resource(name),
vertexPosition(data->vertexPosition),
textureCoords(data->textureCoords),
vertexNormals(data->vertexNormals),
vertexIndexes(data->vertexPosition)//,
//material(material)
{
}

Mesh::~Mesh()
{
}

void Mesh::Render()
{

  //enable object properietes
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);

  //filling data
  glNormalPointer(GL_FLOAT, 0, &(this->vertexNormals[0]));
  glVertexPointer(3, GL_FLOAT, 0, &(this->vertexPosition[0]));
  glTexCoordPointer(2, GL_FLOAT, 0, &(this->textureCoords[0]));

  //rendering
  //glDrawArrays(GL_TRIANGLES, 0, 3);
  glDrawElements(GL_TRIANGLES, this->vertexIndexes.size(), GL_UNSIGNED_SHORT,
      &(this->vertexIndexes[0]));

  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays
  glDisableClientState(GL_NORMAL_ARRAY);
}