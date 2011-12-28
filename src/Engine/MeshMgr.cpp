#include <fstream>
#include <sstream>
#include "Engine/MeshMgr.h"
#include "Engine/Mesh.h"
#include "rapidxml/rapidxml.hpp"

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
  //prepering data structure
  Mesh::meshData meshData;
  int vertexNumber;
  //opening file with mesh data
  std::string fileExtenction(".mesh");
  std::string fileName = name + fileExtenction;
  std::ifstream data(fileName.c_str());
   
  //read file to string used as char*
  std::string meshDataPure;
  std::stringstream buffer;
  buffer << data.rdbuf();
  meshDataPure = buffer.str();
  data.close();
  meshDataPure.append("\0");
  
  //Parse to XML tree
  char* meshDataPureChar = &meshDataPure[0];
  rapidxml::xml_document<> doc;
  doc.parse<0>(meshDataPureChar);
  rapidxml::xml_node<>* root = doc.first_node();
  
  //Finding needed vertex connected buffers size
  rapidxml::xml_node<>* vertexRoot = root->first_node("sharedgeometry");
  vertexNumber = atoi(vertexRoot->first_attribute("vertexcount")->value());
  
  meshData.vertexPosition.reserve(vertexNumber*3+1);
  meshData.vertexNormals.reserve(vertexNumber*3+1);
  meshData.textureCoords.reserve(vertexNumber*2+1);
  
  //Filling vertex buffers
  vertexRoot = vertexRoot->first_node(); //bacause XML has such strange construction.
  rapidxml::xml_node<>* vertex = vertexRoot->first_node();

  //for each vertex
  while (vertex != NULL)
  {
    rapidxml::xml_node<>* position = vertex->first_node("position");
    float value = atof(position->first_attribute("x")->value());
    meshData.vertexPosition.push_back(value);
    value = atof(position->first_attribute("y")->value());
    meshData.vertexPosition.push_back(value);
    value = atof(position->first_attribute("z")->value());
    meshData.vertexPosition.push_back(value);
    
    rapidxml::xml_node<>* normal = vertex->first_node("normal");
    value = atof(normal->first_attribute("x")->value());
    meshData.vertexNormals.push_back(value);
    value = atof(normal->first_attribute("y")->value());
    meshData.vertexNormals.push_back(value);
    value = atof(normal->first_attribute("z")->value());
    meshData.vertexNormals.push_back(value);
    
    
    rapidxml::xml_node<>* texcoord = vertex->first_node("texcoord");
    value = atof(texcoord->first_attribute("u")->value());
    meshData.textureCoords.push_back(value);
    value = atof(texcoord->first_attribute("v")->value());
    meshData.textureCoords.push_back(value);
    
    vertex = vertex->next_sibling();
  } //Filling vertex information complite
  
  //Finding needed face connected buffers size
  rapidxml::xml_node<>* faceRoot = root->first_node("submeshes")->first_node("submesh")->
      first_node("faces");
  int faces = atoi(faceRoot->first_attribute("count")->value());
  meshData.vertexIndexes.reserve(faces*3+1);
  
  rapidxml::xml_node<>* face = faceRoot->first_node();
  
  //Filling buffer
  while(face != NULL)
  {
    float value = atoi(face->first_attribute("v1")->value());
    meshData.vertexIndexes.push_back(value);
    value = atoi(face->first_attribute("v2")->value());
    meshData.vertexIndexes.push_back(value);
    value = atoi(face->first_attribute("v3")->value());
    meshData.vertexIndexes.push_back(value);
    
    face = face->next_sibling();
  }

  Mesh* mesh = new Mesh(name, &meshData);
  return mesh;
}
