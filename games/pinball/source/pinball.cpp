#include "pinball.h"

Pinball::Pinball(C2DRenderer* renderer, b2World* world) {
    b2CircleShape circle;
    circle.m_radius = m_radius;
    b2BodyDef circleBodyDef;
    circleBodyDef.type = b2_dynamicBody;
    circleBodyDef.position.Set(m_startX, m_startY);
    circleBodyDef.bullet = true;
    m_body = world->CreateBody(&circleBodyDef);
    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape = &circle;
    circleFixtureDef.density = 1.0f;
    circleFixtureDef.friction = 0.3f;
    circleFixtureDef.restitution = 0.3;
    circleFixtureDef.filter.maskBits = 0x0001;
    circleFixtureDef.filter.categoryBits = 0xFFFF;
    m_fixture = m_body->CreateFixture(&circleFixtureDef);

    m_shape = new CircleShape(m_radius * g_graphicsScale);
    m_shape->setOrigin(Origin::Center);
    renderer->add(m_shape);
}

void Pinball::update(C2DRenderer* renderer, b2World* world) {
    if (m_ballOut == true) {
        // I've been removed from the world but my update function is still called
        // somewhere. Just waste time until we get deleted.
        world->DestroyBody(m_body);
        renderer->remove(m_shape);
        m_body = NULL;
        m_shape = NULL;
        m_removed = true;
        return;
    }
    b2Vec2 position = m_body->GetPosition();
    float32 angle = m_body->GetAngle();
    m_shape->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
    m_shape->setRotation(angle * 180 / M_PI);
}

b2Fixture* Pinball::getFixture() {
    return m_fixture;
}

uint16 Pinball::getCollisionMask() {
    return m_fixture->GetFilterData().maskBits;
}

void Pinball::setCollisionMask(uint16 mask) {
    b2Filter filterData = m_fixture->GetFilterData();
    filterData.maskBits = mask;
    m_fixture->SetFilterData(filterData);
}

void Pinball::removeFromWorld() {
    m_ballOut = true;
}

bool Pinball::cleanupDone() {
    return m_removed;
}