#include "Engine/GlEngine.h"
#include "Game/Leaf.h"
#include "Game/button1.h"
#include "Game/ladybug.h"

int main( int argc, char* args[] ) 
{
    GlEngine engine;
    engine.init(argc, args);
    engine.setCamera(0, 10, 10, 0, 0, 0);
    Leaf* l = new Leaf();
    ObjectMgr::getMgr()->add(l);
    l->setScale(6);
    //l->setPosition(-1, -3, -2);
    //Button_1* b = new Button_1();
    LadyBug* b = new LadyBug();
    b->setPosition(1,2,2);
    ObjectMgr::getMgr()->add(b);
    engine.run();
    return 0;
}
