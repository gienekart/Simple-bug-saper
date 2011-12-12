#include "Game/ladybug.h"
#include "Engine/MeshMgr.h"
#include "Engine/MaterialMgr.h"
#include "Game/GameLogic.h"
#include "Engine/ObjectMgr.h"


const float LadyBug::colorAnimationLenght = 1;
const float LadyBug::flyAnimationLenght = 3;
const float LadyBug::flyAnimationHeight = 30;
const float LadyBug::informationDelay = 0.03;

LadyBug::LadyBug(GameLogic* logicToInform, int col, int row):logicToInform(logicToInform),
    col(col),row(row),informedAboutFly(false), isFlying(false)
{
  this->mesh = (Mesh*)MeshMgr::getMgr()->getResource("ladybug");
  this->material = (Material*)MaterialMgr::getMgr()->getResource("ladybug");
  this->setScale(0.4);
  this->angleVelocity = (this->logicToInform->getRandom() - 0.5) * 2;
  ObjectMgr::getMgr()->addUsable(this);
}

LadyBug::~LadyBug()
{
  
}

void LadyBug::Click()
{
  if (this->isFlying == true)
    return;
  
  if(this->state == notClicked)
  {
    this->state = ClikkedOnce;
    this->animationTime = 0;
  }
  else if(this->state == ClikkedOnce)
  {
    this->state = ClickedTwice;
    this->animationTime = 0;
    this->isFlying = true;
  }
}

void LadyBug::Update(float deltaTime)
{
  this->angle += this->angleVelocity * deltaTime;
  
  if(this->state == notClicked)
  {
    return;
  }
  if(this->state == ClikkedOnce)
  {
    this->animationTime += deltaTime;
    this->colorMix = this->animationTime / colorAnimationLenght;
    return;
  }
  if(this->state == ClickedTwice)
  {
    this->animationTime += deltaTime;
    float animationPercent = this->animationTime / flyAnimationHeight;
    this->pos.y = animationPercent * flyAnimationHeight;
    if (this->informedAboutFly == false && animationPercent > informationDelay)
    {
      this->informedAboutFly = true;
      this->logicToInform->StartedBug(this->col, this->row);
    }
  }
}

void LadyBug::NeightbourCall()
{
  if (this->isFlying == true)
    return;
  
  this->state = ClickedTwice;
  this->animationTime = 0;
  this->isFlying = true;
}