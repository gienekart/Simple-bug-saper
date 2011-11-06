#include "GlEngine.h"

int main( int argc, char* args[] ) 
{
    GlEngine engine;
    engine.init(argc, args);
    engine.setCamera(0, 0, 10, 0, 0, 0);
    engine.addFeaf();
    engine.run();
    return 0;
}
