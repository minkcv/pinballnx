#include "bumper.h"

Bumper::Bumper(C2DRenderer* renderer, b2World& world, int layerID, float x, float y) {
    m_layerID = layerID;
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
    m_texture1 = new C2DTexture(renderer->getIo()->getDataReadPath() + "bumper1.png");
    m_texture1->setOrigin(Origin::Center);
    m_texture1->setLayer(layerID * 2);
    m_texture1->setPosition(x * g_graphicsScale, y * g_graphicsScale);
    renderer->add(m_texture1);

    m_texture2 = new C2DTexture(renderer->getIo()->getDataReadPath() + "bumper2.png");
    m_texture2->setOrigin(Origin::Center);
    m_texture2->setLayer(-99);
    m_texture2->setPosition(x * g_graphicsScale, y * g_graphicsScale);
    renderer->add(m_texture2);
#endif
}

b2Fixture* Bumper::getFixture() {
    return m_fixture;
}

void Bumper::setHit(bool hit) {
#if !DEBUG
    // TODO: a better visibility enable/disable
    if (hit) {
        m_texture1->setLayer(-99);
        m_texture2->setLayer(m_layerID * 2);
    }
    else {
        m_texture1->setLayer(m_layerID * 2);
        m_texture2->setLayer(-99);
    }
#endif
}
