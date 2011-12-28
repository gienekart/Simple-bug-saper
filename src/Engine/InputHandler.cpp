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
    pressedInMouse(MouseEnumSize), lastPressedKeys(256), lastPressedSpecialKeys(256), 
    lastPressedInMouse(MouseEnumSize)
{
  for(int i=0; i<256; i++ )
  {
    pressedKeys[i] = false;
    pressedSpecialKeys[i] = false;
    lastPressedKeys[i] = false;
    lastPressedSpecialKeys[i] = false;
  }
  for(int i=0; i<MouseEnumSize; i++ )
  {
    pressedInMouse[i] = false;
    lastPressedInMouse[i] = false;
  }
}

InputHandler::~InputHandler()
{
  
}

void InputHandler::frameUpdate()
{
  this->lastPressedKeys = this->pressedKeys;
  this->lastPressedSpecialKeys = this->pressedSpecialKeys;
  this->lastPressedInMouse = this->pressedInMouse;
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


bool InputHandler::isPressedKey(unsigned char keyCode)
{
  return (this->pressedKeys[keyCode] && this->lastPressedKeys[keyCode]);
}

bool InputHandler::isPressedSpecial(int keyIndex)
{
  return (this->pressedSpecialKeys[keyIndex] && this->lastPressedSpecialKeys[keyIndex]);
}

bool InputHandler::isMousePressed(MouseKey key)
{
  return (this->pressedInMouse[key] && this->lastPressedInMouse[key]);
}


bool InputHandler::isUpKey(unsigned char keyCode)
{
  return (!this->pressedKeys[keyCode] && this->lastPressedKeys[keyCode]);
}

bool InputHandler::isUpSpecial(int keyIndex)
{
  return (!this->pressedSpecialKeys[keyIndex] && this->lastPressedSpecialKeys[keyIndex]);
}

bool InputHandler::isMouseUp(MouseKey key)
{
  return (!this->pressedInMouse[key] && this->lastPressedInMouse[key]);
}


bool InputHandler::isDownKey(unsigned char keyCode)
{
  return (this->pressedKeys[keyCode] && !this->lastPressedKeys[keyCode]);
}

bool InputHandler::isDownSpecial(int keyIndex)
{
  return (this->pressedSpecialKeys[keyIndex] && !this->lastPressedSpecialKeys[keyIndex]);
}

bool InputHandler::isMouseDown(MouseKey key)
{
  return (this->pressedInMouse[key] && !this->lastPressedInMouse[key]);
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