#include <math.h>
#include "Box2D/Box2D.h"
#include "cross2d/c2d.h"
#include "util.h"
#include "table.h"
#include "infoscreen.h"

using namespace c2d;

int main(int argc, char **argv) {
    // create the main renderer
    auto *renderer = new C2DRenderer({C2D_SCREEN_WIDTH, C2D_SCREEN_HEIGHT});

    // Portrait graphics on desktop:
    //auto *renderer = new C2DRenderer({C2D_SCREEN_HEIGHT, C2D_SCREEN_WIDTH});
    //renderer->setPosition(-265, 640);
    //renderer->setRotation(-45.0);

    // disable key repeat
    renderer->getInput()->setRepeatDelay(0);

    // Gravity to the left
    b2Vec2 gravity(-9.5f, 0.0f);
    b2World world(gravity);

    // See important info in util.h about g_displayFrameRate
    float32 timeStep = 1.0f / g_displayFrameRate;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    Table table(renderer, world);
    InfoScreen infoScreen(renderer);
    // Start paused.
    infoScreen.show();

    // Do 10 ticks so that the physics objects can settle and 
    // the graphics can update positions and rotations to the physics objects.
    table.update(0);
    for (int i = 0; i < 10; i++) {
        table.update(0);
        world.Step(timeStep, velocityIterations, positionIterations);
        renderer->flip(); // Necessary to have graphics transforms work correctly.
    }

    bool paused = true;
    bool pauseReleased = true;
    // main loop
    while (true) {

        unsigned int keys = renderer->getInput()->getKeys();
        // "special" close/quit event send by sdl2 windows (linux platform)
        if (keys & EV_QUIT) {
            break;
        }
        // exit if + is pressed
        if (keys & Input::Key::Start) {
            break;
        }
        if (keys & Input::Key::Fire2) {
            if (table.isGameOver()) {
                table.newGame();
            }
        }
        if (keys & Input::Key::Select) {
            if (pauseReleased) {
                if (paused)
                    infoScreen.hide();
                else
                    infoScreen.show();
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
        table.updateScoreboard(paused);

        renderer->flip();
    }

    table.cleanup();

    // cleanup
    // will delete child's (textures, shapes, text..)
    delete (renderer);
    
    return 0;
}
