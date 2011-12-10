#include <math.h>
#include "Game/Game.h"
#include "Engine/InputHandler.h"
#include "Engine/GlEngine.h"

Game::Game():input(InputHandler::getInputHandler())
{
  this->cameraLookingAt.x = 0;
  this->cameraLookingAt.y = 0;
  this->cameraLookingAt.z = 0;
  
  this->cameraLookingFrom.x = 0;
  this->cameraLookingFrom.y = 10;
  this->cameraLookingFrom.z = 10;
  
  this->updateCameraSets();
}

Game::~Game()
{
  
}

void Game::frameCall(float deltaTime)
{
  if(input->isMouseClicked(InputHandler::MouseRightButton))
  {
    this->changeCamera();
  }
}

void Game::changeCamera()
{
  Mouse2D move = this->input->getLastMouseMotion();
  
  //Data preparation
  float radius = sqrt(pow(this->cameraLookingFrom.x, 2) + pow(this->cameraLookingFrom.z, 2));
  float angle = atan2(this->cameraLookingFrom.x, this->cameraLookingFrom.z);
  if (move.y > 300)
  {
    move.y = 300;
  }
  else if (move.y < -300)
  {
    move.y = -300;
  }
  
  //section for move
  angle += float(move.x) / 2000;
  radius *= float(move.y) / 1000 + 1;
  
  this->cameraLookingFrom.x = radius * sin(angle);
  this->cameraLookingFrom.z = radius * cos(angle);
  
  this->updateCameraSets();
}

void Game::updateCameraSets()
{
  position3D cameraPosition;
  cameraPosition.x = this->cameraLookingAt.x + this->cameraLookingFrom.x;
  cameraPosition.y = this->cameraLookingAt.y + this->cameraLookingFrom.y;
  cameraPosition.z = this->cameraLookingAt.z + this->cameraLookingFrom.z;
    
  GlEngine* engine = GlEngine::getEngine();
  engine->setCamera(cameraPosition.x, cameraPosition.y, cameraPosition.z,
      this->cameraLookingAt.x, this->cameraLookingAt.y, this->cameraLookingAt.z);
}