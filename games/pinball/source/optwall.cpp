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
    fixtureDef.filter.maskBits = 0xFFFF;
    fixtureDef.filter.categoryBits = 1 << layerID;
    m_fixture = body->CreateFixture(&fixtureDef);

#if DEBUG
    // Debug graphics
    ConvexShape* cshape = new ConvexShape();
    addPointsToShape(cshape, points);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    renderer->add(cshape);
#endif
}

void OptWall::enable() {
    b2Filter filterData = m_fixture->GetFilterData();
    filterData.maskBits = 1 << m_layerID;
    filterData.categoryBits = 1 << m_layerID;
    m_fixture->SetFilterData(filterData);
}

void OptWall::disable() {
    b2Filter filterData = m_fixture->GetFilterData();
    filterData.maskBits = 0;
    filterData.categoryBits = 0;
    m_fixture->SetFilterData(filterData);
}