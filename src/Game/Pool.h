#pragma once
#include <map>
#include "Game/ladybug.h"
#include "Game/button.h"
#include "Game/Leaf.h"

struct bugCoordinates
{
  short col;
  short row;
};

class Pool
{
public:
  Pool(int size);
  ~Pool();
  
  void fillWithBugs();
  void putMine(int col, int row);
  void recalcInfoButtons();
  LadyBug* getLadyBug(int col, int row);
  Button* getObject(int col, int row);
  
private:
  void putInfoButton(int col, int row, int howManyMines);
  void putObject(int col, int row, Button* object);
  void putObject(int col, int row, LadyBug* object);
  void recalcCoords(int col, int row, float height, Object* object);
  
  int size;
  std::map<int, LadyBug*> bugs;
  std::map<int, Button*> objects;
  
  Leaf* leaf;
  
  static const float BugSize;
};