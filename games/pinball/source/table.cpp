#include "table.h"

Table::Table(C2DRenderer* renderer, b2World& world) : 
    m_layers(),
    m_ramps(),
    m_pinballs(),
    m_scoreboard(renderer),
    m_leftFlipper(renderer, world, false),
    m_rightFlipper(renderer, world, true),
    m_plunger(renderer, world)
{
    m_b2world = &world;
    m_renderer = renderer;
    m_currentBall = 1;
    world.SetContactListener(this);

    Layer launchTubeLayer(renderer, world, 0);
    m_layers.push_back(launchTubeLayer);

    Ramp tubeExit(renderer, world, 0, 1);
    m_ramps.push_back(tubeExit);

    Layer mainTableLayer(renderer, world, 1);
    m_layers.push_back(mainTableLayer);

    // Rails
    Layer layer2(renderer, world, 2);
    m_layers.push_back(layer2);

    Ramp ramp1(renderer, world, 1, 2);
    m_ramps.push_back(ramp1);

    Ramp ramp1Down(renderer, world, 2, 1);
    m_ramps.push_back(ramp1Down);

    Ramp hole1(renderer, world, 3, 1);
    m_ramps.push_back(hole1);

    Ramp hole2(renderer, world, 6, 1);
    m_ramps.push_back(hole2);

    Ramp rightRamp(renderer, world, 4, 2);
    m_ramps.push_back(rightRamp);

    Ramp rightRampDown(renderer, world, 5, 1);
    m_ramps.push_back(rightRampDown);

    Bumper bumper1(renderer, world, 1, 9, 1.3);
    m_bumpers.push_back(bumper1);

    Bumper bumper2(renderer, world, 1, 10, 2);
    m_bumpers.push_back(bumper2);

    Bumper bumper3(renderer, world, 1, 9, 2.7);
    m_bumpers.push_back(bumper3);

    Pinball* firstPinball = new Pinball(renderer, &world);
    m_pinballs.push_back(firstPinball);

    // Create a box in box2d to detect when the ball falls out.
    // The sensor box is positioned with a gap in between it and 
    // the bottom of the pinball table so that there is a delay before
    // the ball is reset. The sensor box is very tall to avoid missing balls.
    b2BodyDef bd;
    bd.position.Set(-7, m_width / g_graphicsScale);
    bd.type = b2_staticBody;
    m_ballOutArea = world.CreateBody(&bd);

    b2PolygonShape box;
    box.SetAsBox(5, m_width / g_graphicsScale);

    b2FixtureDef fd;
    fd.isSensor = true;
    fd.shape = &box;
    fd.density = 1.0;
    fd.filter.maskBits = 0xFFFF;
    fd.filter.categoryBits = 0xFFFF;

    m_ballOutSensor = m_ballOutArea->CreateFixture(&fd);
}

void Table::update(unsigned int keys) {
    // Some useful debug code:
    //b2Body* body = m_b2world->GetBodyList();
    //int numBodies = 0;
    //while (body != NULL) {
    //    numBodies++;
    //    body = body->GetNext();
    //}
    //printf("# of bodies %d\n", numBodies);
    
    for (size_t i = 0; i < m_pinballs.size(); i++) {
        Pinball* pinball = m_pinballs.at(i);
        if (pinball != NULL)
            pinball->update(m_renderer, m_b2world);

        if (pinball->cleanupDone()) {
            // Remove this ball from the list.
            m_pinballs.erase(m_pinballs.begin()+i);
            // Free the memory.
            delete pinball;
            pinball = NULL;

            // We need to repeat the current i iteration
            // because we removed an item from the list 
            // and shifted its elements.
            i--;
        }
    }
    m_leftFlipper.update(keys);
    m_rightFlipper.update(keys);
    m_plunger.update(keys);
    if (m_pinballs.size() < 1) {
        m_currentBall++;
        if (m_currentBall < 5) {
            Pinball* nextPinball = new Pinball(m_renderer, m_b2world);
            m_pinballs.push_back(nextPinball);
        }
        m_scoreboard.update(m_currentBall);
    }

    // Free extra multi balls in debug mode at the press of a key
    if (Input::Key::Fire1 & keys) {
        Pinball* nextPinball = new Pinball(m_renderer, m_b2world);
        m_pinballs.push_back(nextPinball);
    }
}

void Table::BeginContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    for (size_t i = 0; i < m_pinballs.size(); i++) {
        Pinball* pinball = m_pinballs.at(i);
        if (pinball == NULL)
            continue;
            
        if ((fixtureA == m_ballOutSensor && fixtureB == pinball->getFixture()) ||
            (fixtureA == pinball->getFixture() && fixtureB == m_ballOutSensor)) {
            pinball->removeFromWorld();
        }

        // If the ball has gone out of bounds and been deleted, then don't
        // Try to check collisions with it with any ramps.
        if (pinball == NULL)
            continue;

        for (size_t r = 0; r < m_ramps.size(); r++) {
            b2Fixture* rampFixture = m_ramps.at(r).getFixture();
            if ((fixtureA == rampFixture && fixtureB == pinball->getFixture()) ||
                (fixtureA == pinball->getFixture() && fixtureB == rampFixture)) {
                int layerID =  m_ramps.at(r).getLayerID();
                pinball->setLayerID(layerID);
            }
        }

        for (size_t b = 0; b < m_bumpers.size(); b++) {
            Bumper bumper = m_bumpers.at(b);
            b2Fixture* bumperFixture = bumper.getFixture();
            if ((fixtureA == bumperFixture && fixtureB == pinball->getFixture()) ||
                (fixtureA == pinball->getFixture() && fixtureB == bumperFixture)) {
                bumper.setHit(true);
            }
        }
    }
}

void Table::EndContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();
    for (size_t i = 0; i < m_pinballs.size(); i++) {
        Pinball* pinball = m_pinballs.at(i);
        if (pinball == NULL)
            continue;

        for (size_t b = 0; b < m_bumpers.size(); b++) {
            Bumper bumper = m_bumpers.at(b);
            b2Fixture* bumperFixture = bumper.getFixture();
            if ((fixtureA == bumperFixture && fixtureB == pinball->getFixture()) ||
                (fixtureA == pinball->getFixture() && fixtureB == bumperFixture)) {
                bumper.setHit(false);
            }
        }
    }
}

void Table::cleanup() {
    for (size_t i = 0; i < m_pinballs.size(); i++) {
        Pinball* pinball = m_pinballs.at(i);
        if (pinball != NULL) {
            pinball->removeFromWorld();
            pinball->update(m_renderer, m_b2world);
            if (pinball->cleanupDone()) {
                delete pinball;
            }
        }
    }
}
