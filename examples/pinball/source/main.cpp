#include "Box2D/Box2D.h"
#include "cross2d/c2d.h"
#include <math.h>

using namespace c2d;

Vector2<float> rotateVector(Vector2<float> in, double radians) {
    float x = cos(radians) * in.x + sin(radians) * in.y;
    float y = sin(radians) * in.x - cos(radians) * in.y;
    Vector2<float> result(x, y);
    return result;
}

int main(int argc, char **argv) {

    // create the main renderer
    auto *renderer = new C2DRenderer({C2D_SCREEN_WIDTH, C2D_SCREEN_HEIGHT});

    // set key repeat to 1 sec
    renderer->getInput()->setRepeatEnable(true);
    renderer->getInput()->setRepeatDelay(1000);

    // Test box2d
    b2Vec2 gravity(0.0f, 10.0f);
    b2World world(gravity);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(8.0f, 20.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    groundBodyDef.position.Set(18.0f, 40.0f);
    b2Body* groundBody2 = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(5.0f, 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
    groundBody2->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(13.5f, 4.0f);
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

    auto r = FloatRect((8 - 5) * 10, (20 - 1) * 10, 100, 20);
    Shape* shape = new C2DRectangle(r);
    renderer->add(shape);

    auto r3 = FloatRect((18 - 5) * 10, (40 - 1) * 10, 100, 20);
    Shape* shape2 = new C2DRectangle(r3);
    renderer->add(shape2);

    auto r2 = FloatRect((13.1 - 1) * 10, (4 - 1) * 10, 20, 20);
    Shape* box = new C2DRectangle(r2);
    renderer->add(box);

    Vector2<float> vTopLeft(-1.0f, -1.0f);

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
        //printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

        Vector2<float> transform = rotateVector(vTopLeft, -angle);
        //printf("%4.2f %4.2f\n", transform.x, transform.y);
        float boxX = (position.x + transform.x) * 10;
        float boxY = (position.y - transform.y) * 10;
        box->setPosition(boxX, boxY);
        box->setRotation(angle * 180 / M_PI); // cross2d uses degrees.

        renderer->flip();
    }

    // cleanup
    // will delete child's (textures, shapes, text..)
    delete (renderer);

    return 0;
}
