#include "GlEngine.h"

int main( int argc, char* args[] ) 
{
    GlEngine engine;
    engine.init(argc, args);
    engine.setCamera(0, 0, 10, 0, 0, 0);
    engine.addFeaf();
    Leaf* l = engine.addFeaf();
    l->setPosition(-1, -2, -3);
    engine.run();
    return 0;
}
