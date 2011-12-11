#include <X11/X.h>

#include "Game/Pool.h"
#include "Game/ladybug.h"
#include "Game/button.h"
#include "Mine.h"

const float Pool::BugSize = 1;

inline int coord(int col, int row, int size)
{
  return row * size + col;
}

Pool::Pool(int size):size(size)
{
  this->leaf = new Leaf();
  this->leaf->setPosition(0.f, -0.05f, 0.f);
  this->leaf->setScale(size+3);
}

Pool::~Pool()
{
  
}

void Pool::fillWithBugs()
{
  for(int col = 0; col < this->size; col++)
    for(int row = 0; row < this->size; row++)
    {
      LadyBug* bug = new LadyBug();
      this->putObject(col, row, bug);
    }
}

LadyBug* Pool::getLadyBug(int col, int row)
{
  return this->bugs[coord(col, row, this->size)];
}

Button* Pool::getObject(int col, int row)
{
  return this->objects[coord(col, row, this->size)];
}

void Pool::putInfoButton(int col, int row, int howManyMines)
{
  
}

void Pool::putMine(int col, int row)
{
  Mine* mine = new Mine();
  this->putObject(col, row, mine);
}

void Pool::putObject(int col, int row, Button* object)
{
  this->objects[coord(col, row, this->size)] = object;
  this->recalcCoords(col, row, -0.1, object);
}

void Pool::putObject(int col, int row, LadyBug* object)
{
  this->bugs[coord(col, row, this->size)] = object;
  this->recalcCoords(col, row, 0.f, object);
}

void Pool::recalcInfoButtons()
{
  
}

void Pool::recalcCoords(int col, int row, float height, Object* object)
{
  float dist = (float)(this->size) * Pool::BugSize;
  float halfdist = dist / 2.0;
  float resolution = Pool::BugSize;
  
  float colPos = -halfdist + col * resolution;
  float rowPos = -halfdist + row * resolution;
  
  object->setPosition(colPos, height, row);
}