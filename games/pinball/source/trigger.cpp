#include "trigger.h"

Trigger::Trigger(C2DRenderer* renderer, b2World& world, int triggerID, int layerID, OptWall* wallToChange) {
    m_layerID = layerID;
    m_isPressed = false;
    m_wallToChange = wallToChange;

    vector<float> points = m_triggerShapes.at(triggerID);

    b2Vec2* vs = getVertexArray(points);
    b2ChainShape chain;
    chain.CreateChain(vs, points.size() / 2);
    free(vs);
    vs = NULL;

    b2BodyDef bodyDef;
    b2Body* body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.isSensor = true;
    fixtureDef.filter.maskBits = 1 << layerID;
    fixtureDef.filter.categoryBits = 1 << layerID;
    m_fixture = body->CreateFixture(&fixtureDef);

#if DEBUG
    // Debug graphics
    ConvexShape* cshape = new ConvexShape();
    addPointsToShape(cshape, points);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    renderer->add(cshape);
#else
    m_textureEnabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/trigger" + std::to_string(triggerID) + "enabled.png");
    m_textureEnabled->setLayer(layerID * 2 + 1);
    renderer->add(m_textureEnabled);
    m_textureDisabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/trigger" + std::to_string(triggerID) + "disabled.png");
    m_textureDisabled->setLayer(-99);
    renderer->add(m_textureDisabled);
#endif
}

b2Fixture* Trigger::getFixture() {
    return m_fixture;
}

void Trigger::update() {
    if (m_hitFrameCurrent < m_hitFrames) {
        m_hitFrameCurrent++;
    }
    else if (m_isPressed) {
        m_isPressed = false;
        // Re enable and change graphics

#if !DEBUG
        m_textureEnabled->setLayer(m_layerID * 2 + 1);
        m_textureDisabled->setLayer(-99);
#endif
    }
}

void Trigger::press() {
    if (m_isPressed)
        return;
    // Start a cooldown before we can be pressed again
    m_hitFrameCurrent = 0;
    m_isPressed = true;

    // Change the thing we trigger;
    if (m_wallToChange->isEnabled())
        m_wallToChange->disable();
    else
        m_wallToChange->enable();
    
#if !DEBUG
    // Change graphics.
    m_textureEnabled->setLayer(-99);
    m_textureDisabled->setLayer(m_layerID * 2 + 1);
#endif
}

void Trigger::reset() {
    m_isPressed = false;
#if !DEBUG
    m_textureEnabled->setLayer(m_layerID * 2 + 1);
    m_textureDisabled->setLayer(-99);
#endif
}
