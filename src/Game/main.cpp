#include "Engine/GlEngine.h"
#include "Game/Leaf.h"
#include "Game/button1.h"
#include "Game/ladybug.h"
#include "Game/Game.h"

int main( int argc, char* args[] ) 
{
    GlEngine* engine = GlEngine::getEngine();
    engine->init(argc, args);
    Game* game = new Game();
    engine->setExternLogic(game);
    engine->run();
    return 0;
}
