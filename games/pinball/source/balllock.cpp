#include "balllock.h"

BallLock::BallLock(C2DRenderer* renderer, b2World& world, int layerID, int shapeID) {
    m_layerID = layerID;

    vector<float> points = m_points.at(shapeID);
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
    fixtureDef.filter.maskBits = 1 << m_layerID;
    fixtureDef.filter.categoryBits = 1 << m_layerID;
    m_fixture = body->CreateFixture(&fixtureDef);

#if DEBUG
    // Debug graphics
    ConvexShape* cshape = new ConvexShape();
    addPointsToShape(cshape, points);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    cshape->setFillColor(Color::Blue);
    renderer->add(cshape);
#endif
}

b2Fixture* BallLock::getFixture() {
    return m_fixture;
}
