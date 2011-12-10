#pragma once
#include <vector>

struct Mouse2D 
{
  int x;
  int y;
};

class InputHandler
{
public:
  static const char ESC;
  enum MouseKey
  {
    MouseLeftButton,
    MouseRightButton,
    MouseMiddleButton,
    MouseEnumSize //it must be always last
  };
  
  static InputHandler* getInputHandler();
  ~InputHandler();
  
  static void keyUp(unsigned char key, int x, int y);
  static void keyPressed(unsigned char key, int x, int y);
  
  static void keySpecialUp(int key, int x, int y);
  static void keySpecialPressed(int key, int x, int y);
  
  static void MouseButton(int button, int state, int x, int y);
  static void MouseMotion(int x, int y);
  
  bool isPressedKey(unsigned char keyCode);
  bool isPressedSpecial(int keyIndex);
  bool isMouseClicked(MouseKey key);
  
  Mouse2D getLastMousePosition();
  Mouse2D getLastMouseMotion();
  
private:
  InputHandler();
  static InputHandler* handler;
  
  std::vector<bool> pressedKeys;
  std::vector<bool> pressedSpecialKeys;
  std::vector<bool> pressedInMouse;
  Mouse2D lastPosition;
  Mouse2D lastMove;
};