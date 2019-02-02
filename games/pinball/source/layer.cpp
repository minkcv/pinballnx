#include "layer.h"

Layer::Layer(C2DRenderer* renderer, b2World& world, uint16 categoryFilter, int layerID) {
    m_collisionMask = categoryFilter;
    int numShapes = m_layerData.at(layerID).size();
    for (int i = 0; i < numShapes; i++) {
        loadShape(m_layerData.at(layerID).at(i), renderer, world, categoryFilter);
    }
}

void Layer::loadShape(std::vector<float> points, C2DRenderer* renderer, b2World& world, uint16 categoryFilter) {
    b2Vec2* vs = getVertexArray(points);
    b2ChainShape chain;
    chain.CreateChain(vs, points.size() / 2);
    free(vs);

    b2BodyDef bodyDef;
    b2Body* body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.filter.maskBits = 0xFFFF;
    fixtureDef.filter.categoryBits = categoryFilter;
    body->CreateFixture(&fixtureDef);

    // Debug graphics
    // TODO: Comment this out when the texture graphics are done.
    // The texture loading should be done elsewhere.
    ConvexShape* cshape = new ConvexShape();
    addPointsToShape(cshape, points);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    renderer->add(cshape);
}

uint16 Layer::getCollisionMask() {
    return m_collisionMask;
}