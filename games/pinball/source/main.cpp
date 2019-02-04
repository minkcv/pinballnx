#include <math.h>
#include "Box2D/Box2D.h"
#include "cross2d/c2d.h"
#include "util.h"
#include "table.h"

using namespace c2d;

int main(int argc, char **argv) {
    // create the main renderer
    auto *renderer = new C2DRenderer({C2D_SCREEN_WIDTH, C2D_SCREEN_HEIGHT});

    // disable key repeat
    renderer->getInput()->setRepeatDelay(0);

    // Gravity to the left
    b2Vec2 gravity(-2.0f, 0.0f);
    b2World world(gravity);

    // You can change the 60.0f to the refresh rate of your monitor.
    // If you have a 120hz monitor and you leave this at 1/60 then 
    // the game runs twice as fast as on the switch.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    Table table(renderer, world);

    // main loop
    bool paused = false;
    bool pauseReleased = true;
    while (true) {

        unsigned int keys = renderer->getInput()->getKeys();
        // "special" close/quit event send by sdl2 windows (linux platform)
        if (keys & EV_QUIT) {
            break;
        }
        // exit if START or SELECT is pressed (+/- on switch)
        if (keys & Input::Key::Start) {
            break;
        }
        if (keys & Input::Key::Select) {
            if (pauseReleased) {
                paused = !paused;
            }
            pauseReleased = false;
        }
        else {
            pauseReleased = true;
        }

        if (!paused) {
            table.update(keys);
            world.Step(timeStep, velocityIterations, positionIterations);
        }

        renderer->flip();
    }

    table.cleanup();

    // cleanup
    // will delete child's (textures, shapes, text..)
    delete (renderer);
    
    return 0;
}
