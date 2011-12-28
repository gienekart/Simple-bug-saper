#include "Engine/GlEngine.h"
#include "Game/Leaf.h"
#include "Game/button1.h"
#include "Game/ladybug.h"
#include "Game/Game.h"
#include <iostream>

int main( int argc, char* args[] ) 
{
    GlEngine* engine = GlEngine::getEngine();
  if(GlEngine::canWork() == false)
  {
    std::cout<<"You have too low version of OGL."<<std::endl;
    return 1;
  }
    engine->init(argc, args);
    Game* game = new Game();
    engine->setExternLogic(game);
    engine->run();
    return 0;
}
