
#include "Engine/InputHandler.h"
#include <GL/glut.h>

InputHandler* InputHandler::handler = NULL;
const char InputHandler::ESC = 27;

InputHandler* InputHandler::getInputHandler()
{
  if (InputHandler::handler == NULL)
  {
    InputHandler::handler = new InputHandler();
  }
  return InputHandler::handler;
}

InputHandler::InputHandler():pressedKeys(256), pressedSpecialKeys(256), 
    pressedInMouse(MouseEnumSize)
{
  for(int i=0; i<256; i++ )
  {
    pressedKeys[i] = false;
    pressedSpecialKeys[i] = false;
  }
  for(int i=0; i<MouseEnumSize; i++ )
  {
    pressedInMouse[i] = false;
  }
}

InputHandler::~InputHandler()
{
  
}

void InputHandler::keyPressed(unsigned char key, int x, int y)
{
  InputHandler::handler->pressedKeys[key] = true;
}

void InputHandler::keyUp(unsigned char key, int x, int y)
{
  InputHandler::handler->pressedKeys[key] = false;
}

void InputHandler::keySpecialPressed(int key, int x, int y)
{
  InputHandler::handler->pressedSpecialKeys[key] = true;
}

void InputHandler::keySpecialUp(int key, int x, int y)
{
  InputHandler::handler->pressedSpecialKeys[key] = false;
}

bool InputHandler::isPressedKey(unsigned char keyCode)
{
  return this->pressedKeys[keyCode];
}

bool InputHandler::isPressedSpecial(int keyIndex)
{
  return this->pressedSpecialKeys[keyIndex];
}

void InputHandler::MouseButton(int button, int state, int x, int y)
{
  // Respond to mouse button presses.
  // If button1 pressed, mark this state so we know in motion function.
  InputHandler* myhandler = InputHandler::handler;
  if (button == GLUT_LEFT_BUTTON)
  {
    myhandler->pressedInMouse[MouseLeftButton] =
        (state == GLUT_DOWN) ? true : false;
  }
  else if (button == GLUT_RIGHT_BUTTON)
  {
    myhandler->pressedInMouse[MouseRightButton] =
        (state == GLUT_DOWN) ? true : false;
  }
  else if (button == GLUT_MIDDLE_BUTTON)
  {
    myhandler->pressedInMouse[MouseMiddleButton] =
        (state == GLUT_DOWN) ? true : false;
  }
  myhandler->RecalcMouseMove(x, y);
}

void InputHandler::MouseMotion(int x, int y)
{
  // If button1 pressed, zoom in/out if mouse is moved up/down.
  
  InputHandler* myhandler = InputHandler::handler;
  myhandler->RecalcMouseMove(x, y);
}

bool InputHandler::isMouseClicked(MouseKey key)
{
  return this->pressedInMouse[key];
}

Mouse2D InputHandler::getLastMouseMotion()
{
  return this->lastMove;
}

Mouse2D InputHandler::getLastMousePosition()
{
  return this->lastPosition;
}

void InputHandler::RecalcMouseMove(Mouse2D newPosition)
{
  this->lastMove.x = newPosition.x - this->lastPosition.x;
  this->lastMove.y = newPosition.y - this->lastPosition.y;
  this->lastPosition = newPosition;
}

void InputHandler::RecalcMouseMove(int newX, int newY)
{
  this->lastMove.x = newX - this->lastPosition.x;
  this->lastMove.y = newY - this->lastPosition.y;
  this->lastPosition.x = newX;
  this->lastPosition.y = newY;
}