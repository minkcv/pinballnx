#include "layer.h"

Layer::Layer(C2DRenderer* renderer, b2World& world, uint16 categoryFilter) {
    size_t numValues = sizeof(m_leftWall) / sizeof(m_leftWall[0]);
    int numPoints = numValues / 2;
    loadShape(m_leftWall, numPoints, renderer, world);
    numValues = sizeof(m_innerWall) / sizeof(m_innerWall[0]);
    numPoints = numValues / 2;
    loadShape(m_innerWall, numPoints, renderer, world);
    numValues = sizeof(m_upperWall) / sizeof(m_upperWall[0]);
    numPoints = numValues / 2;
    loadShape(m_upperWall, numPoints, renderer, world);
    numValues = sizeof(m_leftSlide) / sizeof(m_leftSlide[0]);
    numPoints = numValues / 2;
    loadShape(m_leftSlide, numPoints, renderer, world);
    numValues = sizeof(m_rightSlide) / sizeof(m_rightSlide[0]);
    numPoints = numValues / 2;
    loadShape(m_rightSlide, numPoints, renderer, world);
    numValues = sizeof(m_leftBumper) / sizeof(m_leftBumper[0]);
    numPoints = numValues / 2;
    loadShape(m_leftBumper, numPoints, renderer, world);
    numValues = sizeof(m_rightBumper) / sizeof(m_rightBumper[0]);
    numPoints = numValues / 2;
    loadShape(m_rightBumper, numPoints, renderer, world);
}

void Layer::loadShape(float* points, int numPoints, C2DRenderer* renderer, b2World& world) {
    b2Vec2* vs = getVertexArray(points, numPoints);
    b2ChainShape chain;
    chain.CreateChain(vs, numPoints);
    free(vs);

    b2BodyDef bodyDef;
    b2Body* body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    ConvexShape* cshape = new ConvexShape();
    addPointsToShape(cshape, points, numPoints);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    renderer->add(cshape);
}