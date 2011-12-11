#include <time.h>
#include <stdlib.h>
#include "Game/GameLogic.h"
#include "Game/Mine.h"
#include "Game/Pool.h"
#include "Game/ladybug.h"
#include "Game/button.h"
#include "Game.h"

int tab [][2] = {{1,1},{3,3},{1,2}};
int myneightbours[][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};

GameLogic::GameLogic():pool(NULL)
{
  srand((unsigned)time( NULL ));
}

GameLogic::~GameLogic()
{
  
}

void GameLogic::BuildPool(int size, int mines)
{
  // Building pool
  this->pool = new Pool(size, this);
  
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
  this->pool->updateInfoButtons();
  
  //filling with bugs
  this->pool->fillWithBugs();
}

void GameLogic::ClickLadyBug(int col, int row)
{
  LadyBug* bug = this->pool->getLadyBug(col, row);
  bug->Click();
}

void GameLogic::StartedBug(int col, int row)
{
  Button* object = this->pool->getObject(col, row);
  if(object == NULL) // If not standing on any number
  {
    for(int i=0; i < 8; i++)
    {
      int newCol = col + myneightbours[i][0];
      int newRow = row + myneightbours[i][1];
      LadyBug* bug = this->pool->getLadyBug(newCol, newRow);
      if(bug != NULL)
      {
        bug->NeightbourCall();
      }
    }
  }
}

float GameLogic::getRandom()
{
  int randed = rand() % 32767;
  float floatRand = (float)randed;
  return floatRand/32767.0f;
}