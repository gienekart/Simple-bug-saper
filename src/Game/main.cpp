#include "GlEngine.h"

int main( int argc, char* args[] ) 
{
    GlEngine engine;
    engine.init(argc, args);
    engine.setCamera(0, 0, 10, 0, 0, 0);
    Leaf* l = ObjectMgr::getMgr()->addLeaf();
    l->setPosition(-1, -2, -3);
    ObjectMgr::getMgr()->addButton_1();
    engine.run();
    return 0;
}
