#include "pinball.h"

Pinball::Pinball(C2DRenderer* renderer, b2World& world) {
    b2CircleShape circle;
    circle.m_radius = 1.0f;
    b2BodyDef circleBodyDef;
    circleBodyDef.type = b2_dynamicBody;
    circleBodyDef.position.Set(18.0f, 1.0f);
    m_body = world.CreateBody(&circleBodyDef);
    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape = &circle;
    circleFixtureDef.density = 1.0f;
    circleFixtureDef.friction = 0.3f;
    m_body->CreateFixture(&circleFixtureDef);

    m_shape = new CircleShape(10);
    renderer->add(m_shape);
}

void Pinball::update() {
    Vector2<float> vTopLeft(-1.0f, -1.0f);
    b2Vec2 position = m_body->GetPosition();
    float32 angle = m_body->GetAngle();
    Vector2<float> transform = rotateVector(vTopLeft, -angle);
    m_shape->setPosition((position.x + transform.x) * 10, (position.y - transform.y) * 10);
    m_shape->setRotation(angle * 180 / M_PI);
}