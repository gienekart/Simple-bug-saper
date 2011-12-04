#include <fstream>
#include "MeshMgr.h"
#include "Mesh.h"

MeshMgr* MeshMgr::mgr = NULL;

MeshMgr* MeshMgr::getMgr()
{
  if (MeshMgr::mgr == NULL)
  {
    MeshMgr::mgr = new MeshMgr();
  }
  
  return MeshMgr::mgr;
}

Resource* MeshMgr::createResource(const std::string& name)
{
  //opening file with mesh data
  std::string fileExtenction(".mesh");
  std::string fileName = name + fileExtenction;
  std::ifstream data(fileName.c_str());
  
  //reading number of vertexes and faces in mesh
  int vertexes;
  data>>vertexes;
  int faces;
  data>>faces;
  
  //prepering data structure
  Mesh::meshData meshData;
  meshData.vertexPosition.reserve(vertexes*3);
  meshData.vertexNormals.reserve(vertexes*3);
  meshData.textureCoords.reserve(vertexes*2);
  meshData.vertexIndexes.reserve(faces*3);
  
  //filling structure with position's data
  for(int i=0; i<vertexes*3; i++)
  {
    data >> meshData.vertexPosition[i];
  }
  
  //filling structure with normal's data
  for(int i=0; i<vertexes*3; i++)
  {
    data >> meshData.vertexNormals[i];
  }
  
  //filling structure with texture coord's data
  for(int i=0; i<vertexes*2; i++)
  {
    data >> meshData.textureCoords[i];
  }
  
  //filling structure with vertex index's data
  for(int i=0; i<faces*3; i++)
  {
    data >> meshData.vertexIndexes[i];
  }
  
  data.close();
}