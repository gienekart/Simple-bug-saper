#pragma once

class Pool;

class GameLogic
{
public:
  GameLogic();
  ~GameLogic();
  
  void BuildPool(int size, int mines);
  void StartedBug(int col, int row);
  void ClickLadyBug();
  float getRandom();
  
private:
  Pool* pool;
  
};