#include "table.h"

Table::Table(C2DRenderer* renderer, b2World& world) {
    size_t numValues = sizeof(m_leftWall) / sizeof(m_leftWall[0]);
    int numPoints = numValues / 2;
    loadShape(m_leftWall, numPoints, renderer, world);
    numValues = sizeof(m_innerWall) / sizeof(m_innerWall[0]);
    numPoints = numValues / 2;
    loadShape(m_innerWall, numPoints, renderer, world);
    numValues = sizeof(m_upperWall) / sizeof(m_upperWall[0]);
    numPoints = numValues / 2;
    loadShape(m_upperWall, numPoints, renderer, world);
}

void Table::loadShape(float* points, int numPoints, C2DRenderer* renderer, b2World& world) {
    b2Vec2* vs = getVertexArray(points, numPoints);
    b2ChainShape chain;
    chain.CreateChain(vs, numPoints);

    b2BodyDef bodyDef;
    b2Body* body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    ConvexShape* cshape = new ConvexShape();
    cshape->setPointCount(numPoints);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    addPointsToShape(cshape, points, numPoints);
    renderer->add(cshape);
}