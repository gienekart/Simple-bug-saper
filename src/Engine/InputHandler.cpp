
#include "Engine/InputHandler.h"

InputHandler* InputHandler::handler = NULL;

InputHandler* InputHandler::getInputHandler()
{
  if (InputHandler::handler == NULL)
  {
    InputHandler::handler = new InputHandler();
  }
  return InputHandler::handler;
}

InputHandler::InputHandler():pressedKeys(256), pressedSpecialKeys(256)
{
  for(int i=0; i<256; i++ )
  {
    pressedKeys[i] = false;
    pressedSpecialKeys[i] = false;
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