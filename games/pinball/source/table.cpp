#include "table.h"

Table::Table(C2DRenderer* renderer, b2World& world, Pinball* pinball) {
    m_pinball = pinball;
    m_ballsLeft = 4;
    m_ballOut = false;
    world.SetContactListener(this);
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

    b2BodyDef bd;
    bd.position.Set(-10, m_width / g_graphicsScale / 2);
    bd.type = b2_staticBody;
    m_ballOutArea = world.CreateBody(&bd);

    b2PolygonShape box;
    box.SetAsBox(5, m_width / g_graphicsScale / 2);

    b2FixtureDef fd;
    fd.isSensor = true;
    fd.shape = &box;
    fd.density = 1.0;
    
    m_ballOutSensor = m_ballOutArea->CreateFixture(&fd);
}

void Table::update() {
    if (m_ballOut) {
        m_pinball->reset();
        m_ballOut = false;
    }
}

void Table::BeginContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    if ((fixtureA == m_ballOutSensor && fixtureB == m_pinball->getFixture()) ||
        (fixtureA == m_pinball->getFixture() && fixtureB == m_ballOutSensor))
    {
        m_ballsLeft--;
        m_ballOut = true;
    }
}

void Table::EndContact(b2Contact* contact) {

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
    addPointsToShape(cshape, points, numPoints);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    renderer->add(cshape);
}