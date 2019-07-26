#include "balllock.h"

BallLock::BallLock(C2DRenderer* renderer, b2World& world, int layerID) {
    m_layerID = layerID;

    vector<float> points;
    if (layerID == 2)
        points = {843.5, 532.5, 835.8, 540.9, 834.4, 543.6, 833.0, 546.2, 833.0, 548.1, 833.0, 549.9, 850.2, 564.0, 867.4, 578.0, 869.5, 578.0, 871.5, 578.0, 881.8, 567.7, 892.0, 557.5, 892.0, 555.2, 892.0, 553.0, 873.8, 538.5, 855.5, 524.0, 853.3, 524.0, 851.2, 524.0, 843.5, 532.5};
    else if (layerID == 0)
        points = {214.0, 336.0, 214.0, 355.0, 225.5, 355.0, 237.0, 355.0, 237.0, 336.0, 237.0, 317.0, 225.5, 317.0, 214.0, 317.0, 214.0, 336.0};

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
