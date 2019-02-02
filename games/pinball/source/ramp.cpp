#include "ramp.h"

Ramp::Ramp(C2DRenderer* renderer, b2World& world, int rampID, int layer1ID, int layer2ID) {
    m_layer1ID = layer1ID;
    m_layer2ID = layer2ID;

    vector<vector<float>> shapes = m_rampShapes.at(rampID);

    // Only 2 shapes per ramp
    vector<float> points1 = shapes.at(0);
    b2Vec2* vs = getVertexArray(points1);
    b2ChainShape chain;
    chain.CreateChain(vs, points1.size() / 2);
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
    m_fixture1 = body->CreateFixture(&fixtureDef);

    // Debug graphics
    // TODO: Comment this out when the texture graphics are done.
    // The ramp class is just a sensor. 
    ConvexShape* cshape1 = new ConvexShape();
    addPointsToShape(cshape1, points1);
    cshape1->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    renderer->add(cshape1);

    vector<float> points2 = shapes.at(1);
    vs = getVertexArray(points2);
    b2ChainShape chain2;
    chain2.CreateChain(vs, points2.size() / 2);
    free(vs);

    fixtureDef.shape = &chain2;
    m_fixture2 = body->CreateFixture(&fixtureDef);

    // Debug graphics
    // TODO: Comment this out when the texture graphics are done.
    // The ramp class is just a sensor. 
    ConvexShape* cshape2 = new ConvexShape();
    addPointsToShape(cshape2, points2);
    cshape2->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    renderer->add(cshape2);
}

b2Fixture* Ramp::getFixture1() {
    return m_fixture1;
}
b2Fixture* Ramp::getFixture2() {
    return m_fixture2;
}
int Ramp::getLayer1ID() {
    return m_layer1ID;
}
int Ramp::getLayer2ID() {
    return m_layer2ID;
}