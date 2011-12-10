#pragma once
#include <vector>

class InputHandler
{
public:
  static InputHandler* getInputHandler();
  ~InputHandler();
  
  static void keyUp(unsigned char key, int x, int y);
  static void keyPressed(unsigned char key, int x, int y);
  
  static void keySpecialUp(int key, int x, int y);
  static void keySpecialPressed(int key, int x, int y);
  
  bool isPressedKey(unsigned char keyCode);
  bool isPressedSpecial(int keyIndex);
  
private:
  InputHandler();
  static InputHandler* handler;
  
  std::vector<bool> pressedKeys;
  std::vector<bool> pressedSpecialKeys;
};