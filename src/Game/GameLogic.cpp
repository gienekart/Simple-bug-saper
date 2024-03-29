#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Game/GameLogic.h"
#include "Game/Pool.h"
#include "Engine/ObjectMgr.h"

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
  this->mines = mines;
  
  // Building pool
  this->pool = new Pool(size, this);
  
  // Filling with mines
  while (mines > 0)
  {
    //TODO propper random, but for tests now is good
    int col = (int)(this->getRandom()*size);
    int row = (int)(this->getRandom()*size);
    
    if(this->pool->getObject(col, row) == NULL)
    {
      mines--;
      this->pool->putMine(col, row);
    }
  }
  
  // Putting number objects
  this->pool->updateInfoButtons();
  
  //filling with bugs
  this->pool->fillWithBugs();
  this->bugs = size*size; // On pool we hawe that many bugs
}

void GameLogic::ClickLadyBug()
{
  LadyBug* bug = (LadyBug*)ObjectMgr::getMgr()->getSelectedObject();
  if(bug != NULL)
  {
    bug->Click();
  }
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
  if (this->pool->getCellValue(col, row) == Pool::MineCode)
  {
    std::cout<<"You lost the game!!\n";
    std::cout <<"And who is the bugmaster? Who? WHO!!!"<<std::endl;
  }
  this->bugs--;
  if(this->bugs == this->mines)
  {
    std::cout<<"NNOOOOOOOooooooo.......\n";
    std::cout<<"Ok, you won this time."<<std::endl;
  }
}

float GameLogic::getRandom()
{
  int randed = rand() % 32767;
  float floatRand = (float)randed;
  return floatRand/32767.0f;
}