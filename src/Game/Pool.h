#pragma once
#include <map>
#include <vector>
#include "Game/ladybug.h"
#include "Game/button.h"
#include "Game/Leaf.h"

struct bugCoordinates
{
  short col;
  short row;
};

class GameLogic;

class Pool
{
public:
  Pool(int size, GameLogic* parent);
  ~Pool();
  
  void fillWithBugs();
  void putMine(int col, int row);
  void updateInfoButtons();
  LadyBug* getLadyBug(int col, int row);
  Button* getObject(int col, int row);
  int getCellValue(int col, int row);
  
  static const int MineCode;
  
private:
  void putInfoButton(int col, int row, int howManyMines);
  void putObject(int col, int row, Button* object);
  void putObject(int col, int row, LadyBug* object);
  void recalcCoords(int col, int row, float height, Object* object);
  void recalcPoolInfo();
  void increaseNeightbourRisk(int col, int row);
  int coord(int col, int row);
  int findCol(int pos);
  int findRow(int pos);
  GameLogic* parent;
  
  
  int size;
  std::map<int, LadyBug*> bugs;
  std::map<int, Button*> objects;
  std::vector<short> poolInfo;
  
  Leaf* leaf;
  
  static const float BugSize;
};