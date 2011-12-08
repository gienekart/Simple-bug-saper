#include "GlEngine.h"

int main( int argc, char* args[] ) 
{
    GlEngine engine;
    engine.init(argc, args);
    engine.setCamera(0, 0, 10, 0, 0, 0);
    ObjectMgr::getMgr()->addButton_1();
    Leaf* l = ObjectMgr::getMgr()->addLeaf();
    l->setPosition(-1, -2, -3);
    engine.run();
    return 0;
}
