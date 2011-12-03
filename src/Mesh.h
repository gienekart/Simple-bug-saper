#include "Resource.h"
#include <vector>

#ifndef MESH_H
#define MESH_H

class Mesh: public Resource
{
public:  
  Mesh(std::string name, std::vector<float> data, std::vector<int> indexes);
  virtual ~Mesh();
};

#endif 