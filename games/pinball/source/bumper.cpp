#include "bumper.h"

Bumper::Bumper(C2DRenderer* renderer, b2World& world, int layerID, float x, float y) {
    b2CircleShape circle;
    circle.m_radius = m_radius;
    b2BodyDef circleBodyDef;
    circleBodyDef.type = b2_staticBody;
    circleBodyDef.position.Set(x, y);
    circleBodyDef.bullet = true;
    b2Body* body = world.CreateBody(&circleBodyDef);
    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape = &circle;
    circleFixtureDef.density = 1.0f;
    circleFixtureDef.friction = 0.3f;
    circleFixtureDef.restitution = 0.9;
    circleFixtureDef.filter.maskBits = 1 << layerID;
    circleFixtureDef.filter.categoryBits = 1 << layerID;
    body->CreateFixture(&circleFixtureDef);

    b2CircleShape sensorCircle;
    sensorCircle.m_radius = m_sensorRadius;
    circleFixtureDef.shape = &sensorCircle;
    circleFixtureDef.isSensor = true;
    m_fixture = body->CreateFixture(&circleFixtureDef);

#if DEBUG
    m_shape = new CircleShape(m_radius * g_graphicsScale);
    m_shape->setOrigin(Origin::Center);
    m_shape->setPosition(x * g_graphicsScale, y * g_graphicsScale);
    renderer->add(m_shape);
#else
    m_texture = new C2DTexture(renderer->getIo()->getDataReadPath() + "bumper.png");
    m_texture->setOrigin(Origin::Center);
    m_texture->setLayer(layerID * 2);
    m_texture->setPosition(x * g_graphicsScale, y * g_graphicsScale);
    renderer->add(m_texture);
#endif
}

b2Fixture* Bumper::getFixture() {
    return m_fixture;
}
