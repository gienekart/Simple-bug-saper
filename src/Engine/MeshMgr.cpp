#include <fstream>
#include "Engine/MeshMgr.h"
#include "Engine/Mesh.h"

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
  float value;
  
  //prepering data structure
  Mesh::meshData meshData;
  meshData.vertexPosition.reserve(vertexes*3+1);
  meshData.vertexNormals.reserve(vertexes*3+1);
  meshData.textureCoords.reserve(vertexes*2+1);
  meshData.vertexIndexes.reserve(faces*3+1);
  
  //filling structure with position's data
  for(int i=0; i<vertexes*3; i++)
  {
    data >> value;
    meshData.vertexPosition.push_back(value);
  }
  
  //filling structure with normal's data
  for(int i=0; i<vertexes*3; i++)
  {
    data >> value;
    meshData.vertexNormals.push_back(value);
  }
  
  //filling structure with texture coord's data
  for(int i=0; i<vertexes*2; i++)
  {
    data >> value;
    meshData.textureCoords.push_back(value);
  }
  
  //filling structure with vertex index's data
  for(int i=0; i<faces*3; i++)
  {
    data >> value;
    meshData.vertexIndexes.push_back(value);
  }
  
  data.close();
  
  Mesh* mesh = new Mesh(name, &meshData);
  return mesh;
}
