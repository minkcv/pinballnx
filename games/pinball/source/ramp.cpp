#include "ramp.h"

Ramp::Ramp(C2DRenderer* renderer, b2World& world, int rampID, int layerID) {
    m_layerID = layerID;

    vector<float> points = m_rampShapes.at(rampID);

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
    fixtureDef.filter.maskBits = 0xFFFF;
    fixtureDef.filter.categoryBits = 0xFFFF;
    m_fixture = body->CreateFixture(&fixtureDef);

#if DEBUG
    // Debug graphics
    // The ramp class is just a sensor. 
    ConvexShape* cshape = new ConvexShape();
    addPointsToShape(cshape, points);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    if (layerID == 1)
        cshape->setFillColor(Color::Red);
    else if (layerID == 2)
        cshape->setFillColor(Color::Green);
    renderer->add(cshape);
#endif
}

b2Fixture* Ramp::getFixture() {
    return m_fixture;
}

int Ramp::getLayerID() {
    return m_layerID;
}