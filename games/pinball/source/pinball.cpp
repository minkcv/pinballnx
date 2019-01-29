#include "pinball.h"

Pinball::Pinball(C2DRenderer* renderer, b2World& world) {
    b2CircleShape circle;
    circle.m_radius = m_radius;
    b2BodyDef circleBodyDef;
    circleBodyDef.type = b2_dynamicBody;
    circleBodyDef.position.Set(2.0f, 6.9f);
    circleBodyDef.bullet = true;
    m_body = world.CreateBody(&circleBodyDef);
    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape = &circle;
    circleFixtureDef.density = 1.0f;
    circleFixtureDef.friction = 0.3f;
    circleFixtureDef.restitution = 0.3;
    m_body->CreateFixture(&circleFixtureDef);

    m_shape = new CircleShape(m_radius * g_graphicsScale);
    renderer->add(m_shape);
}

void Pinball::update() {
    Vector2<float> vTopLeft(-m_radius, -m_radius);
    b2Vec2 position = m_body->GetPosition();
    float32 angle = m_body->GetAngle();
    Vector2<float> transform = rotateVector(vTopLeft, -angle);
    m_shape->setPosition((position.x + transform.x) * g_graphicsScale, (position.y - transform.y) * g_graphicsScale);
    m_shape->setRotation(angle * 180 / M_PI);
}
