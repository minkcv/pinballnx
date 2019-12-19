#include "gtarget.h"

GTarget::GTarget(C2DRenderer* renderer, b2World& world, int targetGroupID, int layerID, bool sameSprites) {
    m_layerID = layerID;

    vector<vector<float>> shapes = m_targetGroups.at(targetGroupID);
    for (size_t s = 0; s < shapes.size(); s++) {
        vector<float> points = shapes.at(s);
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
        b2Fixture* fixture = body->CreateFixture(&fixtureDef);
        m_fixtures.push_back(fixture);
        m_isPressed.push_back(false);
    #if DEBUG
        // Debug graphics
        ConvexShape* cshape = new ConvexShape();
        addPointsToShape(cshape, points);
        cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
        renderer->add(cshape);
    #else
        C2DTexture* textureEnabled;
        if (sameSprites)
            textureEnabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/gtarget" + to_string(targetGroupID) + "-0" + "enabled.png");
        else
            textureEnabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/gtarget" + to_string(targetGroupID) + "-" + to_string(s) + "enabled.png");
        textureEnabled->setLayer(layerID * 2);
        textureEnabled->setPosition(m_positions.at(targetGroupID).at(s * 2), m_positions.at(targetGroupID).at(s * 2 + 1));
        renderer->add(textureEnabled);
        m_texturesEnabled.push_back(textureEnabled);
        C2DTexture* textureDisabled;
        if (sameSprites)
            textureDisabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/gtarget" + to_string(targetGroupID) + "-0" + "disabled.png");
        else
            textureDisabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/gtarget" + to_string(targetGroupID) + "-" + to_string(s) + "disabled.png");
        textureDisabled->setLayer(-99);
        textureDisabled->setPosition(m_positions.at(targetGroupID).at(s * 2), m_positions.at(targetGroupID).at(s * 2 + 1));
        m_texturesDisabled.push_back(textureDisabled);
        renderer->add(textureDisabled);
    #endif
    }
}

void GTarget::update() {
    if (m_frameCurrent < m_hitFrames) {
        m_frameCurrent++;
    }
    else if (m_frameCurrent == m_hitFrames) {
        reset();
        m_frameCurrent++;
    }
}

vector<b2Fixture*> GTarget::getFixtures() {
    return m_fixtures;
}

bool GTarget::press(size_t targetID) {
    m_isPressed[targetID] = true;
#if !DEBUG
    m_texturesEnabled.at(targetID)->setLayer(-99);
    m_texturesDisabled.at(targetID)->setLayer(m_layerID * 2);
#endif
    size_t numPressed = 0;
    for (size_t i = 0; i < m_isPressed.size(); i++) {
        if (m_isPressed.at(i))
            numPressed++;
    }
    if (numPressed == m_isPressed.size()) {
        m_frameCurrent = 0;
        return true;
    }
    return false;

}

void GTarget::reset() {
    for (size_t i = 0; i < m_isPressed.size(); i++) {
        m_isPressed[i] = false;
#if !DEBUG
        m_texturesEnabled.at(i)->setLayer(m_layerID * 2);
        m_texturesDisabled.at(i)->setLayer(-99);
#endif
    }
}