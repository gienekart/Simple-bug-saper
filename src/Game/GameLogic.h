#pragma once

class Pool;

class GameLogic
{
public:
  GameLogic();
  ~GameLogic();
  
  void BuildPool(int size, int mines);
  void StartedBug(int col, int row);
  void ClickLadyBug(int col, int row);
  
private:
  Pool* pool;
  
};