#include "pinball.h"

Pinball::Pinball(C2DRenderer* renderer, b2World* world, int iStartPos) {
    b2CircleShape circle;
    circle.m_radius = m_radius;
    b2BodyDef circleBodyDef;
    circleBodyDef.type = b2_dynamicBody;
    if (iStartPos > 0) {
        m_currentLayerID = 2;
    }

    float startX = m_startPositions.at(iStartPos * 2);
    float startY = m_startPositions.at(iStartPos * 2 + 1);
    circleBodyDef.position.Set(startX, startY);
    circleBodyDef.bullet = true;
    m_body = world->CreateBody(&circleBodyDef);
    b2FixtureDef circleFixtureDef;
    circleFixtureDef.shape = &circle;
    circleFixtureDef.density = 1.0f;
    circleFixtureDef.friction = 0.0f;
    circleFixtureDef.restitution = 0.3;
    circleFixtureDef.filter.maskBits = 1 << m_currentLayerID;
    circleFixtureDef.filter.categoryBits = 0xFFFF;
    m_fixture = m_body->CreateFixture(&circleFixtureDef);

#if DEBUG
    m_shape = new CircleShape(m_radius * g_graphicsScale);
    m_shape->setOrigin(Origin::Center);
    m_shape->setFillColor(Color::Green);
    renderer->add(m_shape);
#else
    m_texture = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/pinball.png");
    m_texture->setOrigin(Origin::Center);
    m_texture->setLayer(m_currentLayerID * 2);
    renderer->add(m_texture);
#endif
}

void Pinball::update(C2DRenderer* renderer, b2World* world) {
    if (m_ballOut == true) {
        // The ball can't be removed in the box2d contact event handler,
        // so m_ballOut is set to true and now we remove the body and graphics,
        // outside of the box2d physics code.
        world->DestroyBody(m_body);
#if DEBUG
        renderer->remove(m_shape);
#else
        renderer->remove(m_texture);
#endif
        m_body = NULL;
        m_shape = NULL;
        m_removed = true;
        return;
    }
    b2Vec2 position = m_body->GetPosition();
#if DEBUG
    m_shape->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
#else
    m_texture->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
#endif
    if (m_bumpX != 0 && m_bumpY != 0) {
        b2Vec2 vec(m_bumpX, m_bumpY);
        m_body->ApplyForce(vec, m_body->GetWorldVector(b2Vec2(0, 0)), true);
        m_bumpX = 0;
        m_bumpY = 0;
    }
}

b2Fixture* Pinball::getFixture() {
    return m_fixture;
}

b2Body* Pinball::getBody() {
    return m_body;
}

int Pinball::getLayerID() {
    return m_currentLayerID;
}

void Pinball::setLayerID(int layerID) {
    m_currentLayerID = layerID;
#if DEBUG
    if (layerID == 0)
        m_shape->setFillColor(Color::Cyan);
    if (layerID == 1)
        m_shape->setFillColor(Color::Green);
    if (layerID == 2)
        m_shape->setFillColor(Color::White);
    if (layerID == 3)
        m_shape->setFillColor(Color::Red);
#else
    // Multiply by 2 because rendering layers have a gap so the pinball
    // can be rendered above the layer it is on.
    m_texture->setLayer(m_currentLayerID * 2 + 1);
#endif
    b2Filter filterData = m_fixture->GetFilterData();
    filterData.maskBits = 1 << layerID;
    filterData.categoryBits = 1 << layerID;
    m_fixture->SetFilterData(filterData);
}

void Pinball::removeFromWorld() {
    m_ballOut = true;
}

void Pinball::setBumpVelocity(float x, float y) {
    m_bumpX = x;
    m_bumpY = y;
}

bool Pinball::cleanupDone() {
    return m_removed;
}

bool Pinball::isOut() {
    return m_ballOut;
}
