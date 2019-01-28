#include "table.h"

Table::Table(C2DRenderer* renderer, b2World& world) {
    size_t numValues = sizeof(m_leftWall) / sizeof(m_leftWall[0]);
    int numPoints = numValues / 2;
    b2Vec2* vs = getVertexArray(m_leftWall, numPoints);
    b2ChainShape chain;
    chain.CreateChain(vs, numPoints);

    b2BodyDef bodyDef;
    m_body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.3f;
    m_body->CreateFixture(&fixtureDef);

    ConvexShape* cshape = new ConvexShape();
    cshape->setPointCount(numPoints);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    addPointsToShape(cshape, m_leftWall, numPoints);
    renderer->add(cshape);
}
