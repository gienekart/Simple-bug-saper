#include <X11/X.h>

#include "Game/Pool.h"
#include "Game/ladybug.h"
#include "Game/button.h"
#include "Mine.h"

const float Pool::BugSize = 1;
const int Pool::MineCode = -1;

int neightbours[][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};

inline int Pool::coord(int col, int row)
{
  return row * this->size + col;
}
inline int Pool::findCol(int pos)
{
  return pos % this->size;
}
inline int Pool::findRow(int pos)
{
  return pos / this->size;
}

Pool::Pool(int size, GameLogic* parent):size(size), poolInfo(size*size, 0), 
    parent(parent)
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
      LadyBug* bug = new LadyBug(this->parent, col, row);
      this->putObject(col, row, bug);
    }
}

LadyBug* Pool::getLadyBug(int col, int row)
{
  if((0 <= col) && (col < this->size) && (0 <= row) && (row < this->size))
  {
    return this->bugs[coord(col, row)];
  }
  else
  {
    return NULL;
  }
}

Button* Pool::getObject(int col, int row)
{
  return this->objects[coord(col, row)];
}

void Pool::putInfoButton(int col, int row, int howManyMines)
{
  Button* infoButton;
  switch(howManyMines)
  {
    case 1:
      infoButton = new InfoButton("1");
      break;
    case 2:
      infoButton = new InfoButton("2");
      break;
    case 3:
      infoButton = new InfoButton("3");
      break;
    case 4:
      infoButton = new InfoButton("4");
      break;
    case 5:
      infoButton = new InfoButton("5");
      break;
    case 6:
      infoButton = new InfoButton("6");
      break;
    case 7:
      infoButton = new InfoButton("7");
      break;
    case 8:
      infoButton = new InfoButton("8");
      break;
  }
  this->putObject(col, row, infoButton);
}

void Pool::putMine(int col, int row)
{
  Mine* mine = new Mine();
  this->putObject(col, row, mine);
  this->poolInfo[coord(col, row)] = -1;
}

void Pool::putObject(int col, int row, Button* object)
{
  this->objects[coord(col, row)] = object;
  this->recalcCoords(col, row, 0, object);
}

void Pool::putObject(int col, int row, LadyBug* object)
{
  this->bugs[coord(col, row)] = object;
  this->recalcCoords(col, row, 0.f, object);
}

void Pool::updateInfoButtons()
{
  this->recalcPoolInfo();
  
  for(int pos=0; pos < this->poolInfo.size(); pos++)
  {
    if(this->poolInfo[pos] > 0) //if has some trubelsome neightbours
    {
      int col = findCol(pos);
      int row = findRow(pos);
      this->putInfoButton(col, row, this->poolInfo[pos]);
    }
  }
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

void Pool::recalcPoolInfo()
{
  for(int pos = 0; pos <size*size; pos++)
  {
    if(this->poolInfo[pos] == Pool::MineCode)
    {
      int col = findCol(pos);
      int row = findRow(pos);
      this->increaseNeightbourRisk(col, row);
    }
  }
}

void Pool::increaseNeightbourRisk(int col, int row)
{
  for(int i = 0; i < 8; i++)
  {
    int newCol = col + neightbours[i][0];
    int newRow = row + neightbours[i][1];
    
    // if neightbour is in pool
    if((0 <= newCol) && (newCol < this->size) &&
        (0 <= newRow) && (newRow < this->size))
    {
      if(this->poolInfo[coord(newCol, newRow)] != Pool::MineCode)
      {
        this->poolInfo[coord(newCol, newRow)]++;
      }
    }
  }
}