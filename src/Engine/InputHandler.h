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
  
  void frameUpdate();
  
  bool isPressedKey(unsigned char keyCode);
  bool isPressedSpecial(int keyIndex);
  bool isMousePressed(MouseKey key);
  
  bool isDownKey(unsigned char keyCode);
  bool isDownSpecial(int keyIndex);
  bool isMouseDown(MouseKey key);
  
  bool isUpKey(unsigned char keyCode);
  bool isUpSpecial(int keyIndex);
  bool isMouseUp(MouseKey key);
  
  Mouse2D getLastMousePosition();
  Mouse2D getLastMouseMotion();
  
private:
  InputHandler();
  static InputHandler* handler;
  void RecalcMouseMove(Mouse2D newPosition);
  void RecalcMouseMove(int newX, int newY);
  
  std::vector<bool> pressedKeys;
  std::vector<bool> pressedSpecialKeys;
  std::vector<bool> pressedInMouse;
  std::vector<bool> lastPressedKeys;
  std::vector<bool> lastPressedSpecialKeys;
  std::vector<bool> lastPressedInMouse;
  Mouse2D lastPosition;
  Mouse2D lastMove;
};