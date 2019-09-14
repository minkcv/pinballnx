#include "conveyor.h"

Conveyor::Conveyor(C2DRenderer* renderer, b2World& world, int conveyorID, int layerID) {
    m_layerID = layerID;
    vector<float> points = m_shapes.at(conveyorID);

    b2Vec2* vs = getVertexArray(points);
    b2PolygonShape poly;
    poly.Set(vs, 4);

    b2BodyDef bodyDef;
    b2Body* body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &poly;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.isSensor = true;
    fixtureDef.filter.maskBits = 1 << layerID;
    fixtureDef.filter.categoryBits = 1 << layerID;
    m_fixture = body->CreateFixture(&fixtureDef);

#if DEBUG
    m_shape = new ConvexShape();
    addPointsToShape(m_shape, points);
    m_shape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    m_shape->setFillColor(Color::Green);
    renderer->add(m_shape);
    m_shape->setLayer(layerID * 2 + 1);
#endif
}

b2Fixture* Conveyor::getFixture() {
    return m_fixture;
}

void Conveyor::setDirection(b2Vec2 vec) {
    m_direction = vec;
}

b2Vec2 Conveyor::getDirection() {
    return m_direction;
}

