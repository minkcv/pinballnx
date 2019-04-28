#include "optwall.h"

OptWall::OptWall(C2DRenderer* renderer, b2World& world, int optWallId, int layerID) {
    m_layerID = layerID;

    vector<float> points = m_WallShapes.at(optWallId);

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
    m_textureEnabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "optwall" + std::to_string(optWallId) + "enabled.png");
    m_textureEnabled->setLayer(layerID * 2 + 1);
    renderer->add(m_textureEnabled);
    m_textureDisabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "optwall" + std::to_string(optWallId) + "disabled.png");
    m_textureDisabled->setLayer(-99);
    renderer->add(m_textureDisabled);
#endif
    // Default state is disabled
    disable();
}

void OptWall::enable() {
    m_isEnabled = true;
    b2Filter filterData = m_fixture->GetFilterData();
    filterData.maskBits = 1 << m_layerID;
    filterData.categoryBits = 1 << m_layerID;
    m_fixture->SetFilterData(filterData);
    m_textureEnabled->setLayer(m_layerID * 2 + 1);
    m_textureDisabled->setLayer(-99);
}

void OptWall::disable() {
    m_isEnabled = false;
    b2Filter filterData = m_fixture->GetFilterData();
    filterData.maskBits = 0;
    filterData.categoryBits = 0;
    m_fixture->SetFilterData(filterData);
    m_textureEnabled->setLayer(-99);
    m_textureDisabled->setLayer(m_layerID * 2 + 1);
}

bool OptWall::isEnabled() {
    return m_isEnabled;
}