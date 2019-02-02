#include "table.h"

Table::Table(C2DRenderer* renderer, b2World& world) : 
    m_layers(),
    m_ramps(),
    m_scoreboard(renderer),
    m_leftFlipper(renderer, world, false),
    m_rightFlipper(renderer, world, true),
    m_plunger(renderer, world),
    m_pinball(renderer, world)
{
    m_currentBall = 1;
    m_ballOut = false;
    world.SetContactListener(this);

    Layer layer1(renderer, world, 0x0001, 0);
    m_layers.push_back(layer1);

    Layer layer2(renderer, world, 0x0002, 1);
    m_layers.push_back(layer2);

    Ramp ramp1(renderer, world, 0, 0, 1);
    m_ramps.push_back(ramp1);

    Ramp ramp2(renderer, world, 1, 0, 1);
    m_ramps.push_back(ramp2);

    // Create a box in box2d to detect when the ball falls out.
    // The sensor box is positioned with a gap in between it and 
    // the bottom of the pinball table so that there is a delay before
    // the ball is reset. 
    b2BodyDef bd;
    bd.position.Set(-7, m_width / g_graphicsScale / 2);
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

void Table::update(unsigned int keys) {
    m_pinball.update();
    m_leftFlipper.update(keys);
    m_rightFlipper.update(keys);
    m_plunger.update(keys);
    if (m_ballOut) {
        if (m_currentBall < 5) {
            m_pinball.reset();
            m_ballOut = false;
        }
        m_scoreboard.update(m_currentBall);
    }
}

void Table::BeginContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    if ((fixtureA == m_ballOutSensor && fixtureB == m_pinball.getFixture()) ||
        (fixtureA == m_pinball.getFixture() && fixtureB == m_ballOutSensor)) {
        m_currentBall++;
        m_ballOut = true;
    }

    for (size_t i = 0; i < m_ramps.size(); i++) {
        b2Fixture* rampFixture1 = m_ramps.at(i).getFixture1();
        b2Fixture* rampFixture2 = m_ramps.at(i).getFixture2();
        // Check fixture1
        if ((fixtureA == rampFixture1 && fixtureB == m_pinball.getFixture()) ||
            (fixtureA == m_pinball.getFixture() && fixtureB == rampFixture1)) {
            int layerID =  m_ramps.at(i).getLayer1ID();
            m_pinball.setCollisionMask(m_layers.at(layerID).getCategoryFilter());
        }

        if ((fixtureA == rampFixture2 && fixtureB == m_pinball.getFixture()) ||
            (fixtureA == m_pinball.getFixture() && fixtureB == rampFixture2)) {
            int layerID =  m_ramps.at(i).getLayer2ID();
            m_pinball.setCollisionMask(m_layers.at(layerID).getCategoryFilter());
        }
    }
}

void Table::EndContact(b2Contact* contact) {

}