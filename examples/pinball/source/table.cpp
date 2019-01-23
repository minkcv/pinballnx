#include "table.h"

Table::Table(C2DRenderer* renderer, b2World& world) {
    b2Vec2 vs[4];
    vs[0].Set(0, 0);
    vs[1].Set(0, 40);
    vs[2].Set(40, 50);
    vs[3].Set(40, 0);

    b2ChainShape chain;
    chain.CreateChain(vs, 4);

    b2BodyDef bodyDef;
    m_body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    m_body->CreateFixture(&fixtureDef);
}
