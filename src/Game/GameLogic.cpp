#include "Game/GameLogic.h"
#include "Game/Mine.h"
#include "Game/Pool.h"
#include "Game/ladybug.h"
#include "Game/button.h"

int tab [][2] = {{1,1},{3,3},{1,2}};

GameLogic::GameLogic():pool(NULL)
{
  
}

GameLogic::~GameLogic()
{
  
}

void GameLogic::BuildPool(int size, int mines)
{
  // Building pool
  this->pool = new Pool(size);
  
  // Filling with mines
  while (mines > 0)
  {
    mines--;
    //TODO propper random, but for tests now is good
    int col = tab[mines][0];
    int row = tab[mines][1];
    
    if(this->pool->getObject(col, row) == NULL)
    {
      this->pool->putMine(col, row);
    }
  }
  
  // Putting number objects
  this->pool->recalcInfoButtons();
  
  //filling with bugs
  this->pool->fillWithBugs();
}

void GameLogic::ClickLadyBug(int col, int row)
{
  LadyBug* bug = this->pool->getLadyBug(col, row);
  bug->Click();
}