#include <math.h>
#include "Game/Game.h"
#include "Engine/GlEngine.h"

const float Game::VerticalSpeed = 3.5;
const float Game::BasicPointSpeed = 4;
const float Game::MaxHeight = 20;
const float Game::MinHeight = 3;
const float Game::MinRadius = 0.6;
const float Game::MaxRadius = 40;

Game::Game():input(InputHandler::getInputHandler())
{
  this->cameraLookingAt.x = 0;
  this->cameraLookingAt.y = 0;
  this->cameraLookingAt.z = 0;
  
  this->cameraLookingFrom.x = 0;
  this->cameraLookingFrom.y = 10;
  this->cameraLookingFrom.z = 10;
  
  this->lookingAngle = 0;
  
  this->updateCameraSets();
  
  this->logic = new GameLogic();
  this->logic->BuildPool(5, 3);
}

Game::~Game()
{
  
}

void Game::frameCall(float deltaTime)
{
  if(this->input->isMousePressed(InputHandler::MouseRightButton))
  {
    this->changeCameraHorisontal(deltaTime);
  }
  
  // Camera height
  if(this->input->isPressedKey('q') == true)
  {
    this->changeCameraVertical(deltaTime, true);
  }
  if(this->input->isPressedKey('z'))
  {
    this->changeCameraVertical(deltaTime, false);
  }
  
  // Base point move
  if(this->input->isPressedKey('w'))
  {
    this->changeBasicPoint(deltaTime, 1, 0);
  }
  if(this->input->isPressedKey('s'))
  {
    this->changeBasicPoint(deltaTime, -1, 0);
  }
  if(this->input->isPressedKey('a'))
  {
    this->changeBasicPoint(deltaTime, 0, 1);
  }
  if(this->input->isPressedKey('d'))
  {
    this->changeBasicPoint(deltaTime, 0, -1);
  }
  
  //Display change
  this->displayAsWireframe(this->input->isPressedKey('x'));
  
  // For managing click on ladyBug
  if(this->input->isMouseUp(InputHandler::MouseLeftButton))
  {
    this->logic->ClickLadyBug();
  }
}

void Game::changeCameraHorisontal(float deltaTime)
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
  angle += float(move.x) / 20 *deltaTime;
  radius *= float(move.y) / 10 *deltaTime + 1;
  
  if (radius < Game::MinRadius)
  {
    radius = Game::MinRadius;
  }
  else if (radius > Game::MaxRadius)
  {
    radius = Game::MaxRadius;
  }
  
  this->cameraLookingFrom.x = radius * sin(angle);
  this->cameraLookingFrom.z = radius * cos(angle);
  
  this->updateCameraSets();
  this->lookingAngle = angle;
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

void Game::changeCameraVertical(float deltaTime, bool goingUp)
{
  float changePosition = Game::VerticalSpeed * deltaTime;
  if (goingUp == true)
  {
    this->cameraLookingFrom.y += changePosition;
    if (this->cameraLookingFrom.y > Game::MaxHeight)
    {
      this->cameraLookingFrom.y = Game::MaxHeight;
    }
  }
  else
  {
    this->cameraLookingFrom.y -= changePosition;
    if (this->cameraLookingFrom.y < Game::MinHeight)
    {
      this->cameraLookingFrom.y = Game::MinHeight;
    }
  }
  
  this->updateCameraSets();
}

void Game::changeBasicPoint(float deltatime, char stright, char side)
{
  //Data preparation
  float strightDir = stright * cos(this->lookingAngle) - side * sin(this->lookingAngle);
  float sideDir = stright * sin(this->lookingAngle) + side * cos(this->lookingAngle);
  this->cameraLookingAt.x += -sideDir * Game::BasicPointSpeed * deltatime;
  this->cameraLookingAt.z += -strightDir * Game::BasicPointSpeed * deltatime;
  
  if (this->cameraLookingAt.x < - Game::MaxRadius)
  {
    this->cameraLookingAt.x = - Game::MaxRadius;
  }
  if (this->cameraLookingAt.x > Game::MaxRadius)
  {
    this->cameraLookingAt.x = Game::MaxRadius;
  }
  
  if (this->cameraLookingAt.z < - Game::MaxRadius)
  {
    this->cameraLookingAt.z = - Game::MaxRadius;
  }
  if (this->cameraLookingAt.z > Game::MaxRadius)
  {
    this->cameraLookingAt.z = Game::MaxRadius;
  }
  
  this->updateCameraSets();
}

void Game::displayAsWireframe(bool active)
{
  GlEngine* engine = GlEngine::getEngine();
  if (active == true)
  {
    engine->setShowMode(GL_LINE);
  }
  else
  {
    engine->setShowMode(GL_FILL);
  }
}