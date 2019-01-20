#include "Box2D/Box2D.h"
#include <random>
#include "cross2d/c2d.h"

using namespace c2d;


int main(int argc, char **argv) {

    // create the main renderer
    auto *renderer = new C2DRenderer({C2D_SCREEN_WIDTH, C2D_SCREEN_HEIGHT});

    // set key repeat to 1 sec
    renderer->getInput()->setRepeatEnable(true);
    renderer->getInput()->setRepeatDelay(1000);

    // Test box2d
    b2Vec2 gravity(-10.0f, 0.0f);
    b2World world(gravity);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

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

	world.Step(timeStep, velocityIterations, positionIterations);
	b2Vec2 position = body->GetPosition();
	float32 angle = body->GetAngle();
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

        renderer->flip();
    }

    // cleanup
    // will delete child's (textures, shapes, text..)
    delete (renderer);

    return 0;
}
