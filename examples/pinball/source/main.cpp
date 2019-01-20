
#include <random>
#include "cross2d/c2d.h"

using namespace c2d;


int main(int argc, char **argv) {

    // create the main renderer
    auto *renderer = new C2DRenderer({C2D_SCREEN_WIDTH, C2D_SCREEN_HEIGHT});

    // set key repeat to 1 sec
    renderer->getInput()->setRepeatEnable(true);
    renderer->getInput()->setRepeatDelay(1000);

    // main loop
    while (true) {

        unsigned int keys = renderer->getInput()->getKeys();
        if (keys) {
            // "special" close/quit event send by sdl2 windows (linux platform)
            if (keys & EV_QUIT) {
                break;
            }
            // exit if START or SELECT is pressed (+/- on switch)
            if (keys & Input::Key::Start || keys & Input::Key::Select) {
                break;
            }
        }

        renderer->flip();
    }

    // cleanup
    // will delete child's (textures, shapes, text..)
    delete (renderer);

    return 0;
}
