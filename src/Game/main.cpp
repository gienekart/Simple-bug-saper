#include "Engine/GlEngine.h"
#include "Game/Leaf.h"
#include "Game/button1.h"
#include "Game/ladybug.h"

int main( int argc, char* args[] ) 
{
    GlEngine engine;
    engine.init(argc, args);
    engine.setCamera(0, 0, 10, 0, 0, 0);
    Leaf* l = new Leaf();
    ObjectMgr::getMgr()->add(l);
    l->setPosition(-1, -2, -3);
    Button_1* b = new Button_1();
    //LadyBug* b = new LadyBug();
    ObjectMgr::getMgr()->add(b);
    engine.run();
    return 0;
}
