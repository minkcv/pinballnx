#include "table.h"

Table::Table(C2DRenderer* renderer, b2World& world) : 
    m_layers(),
    m_ramps(),
    m_bumpers(),
    m_pinballs(),
    m_scoreboard(renderer),
    m_leftFlipper(renderer, world, 0),
    m_rightFlipper(renderer, world, 1),
    m_leftFlipper2(renderer, world, 2),
    m_rightFlipper2(renderer, world, 3),
    m_plunger(renderer, world)
{
    m_b2world = &world;
    m_renderer = renderer;
    m_currentBall = 1;
    m_score = 0;
    m_lockedBalls = 0;
    world.SetContactListener(this);

    Layer underLayer(renderer, world, 0);
    m_layers.push_back(underLayer);

    Layer launchTubeLayer(renderer, world, 1);
    m_layers.push_back(launchTubeLayer);

    Layer mainTableLayer(renderer, world, 2);
    m_layers.push_back(mainTableLayer);

    // Rails
    Layer layer2(renderer, world, 3);
    m_layers.push_back(layer2);

    // Ramps for main layer
    Ramp ramp1(renderer, world, 0, 3);
    m_ramps.push_back(ramp1);

    Ramp ramp1up2(renderer, world, 1, 3);
    m_ramps.push_back(ramp1up2);

    Ramp ramp1Down(renderer, world, 2, 2);
    m_ramps.push_back(ramp1Down);

    Ramp hole1(renderer, world, 3, 2);
    m_ramps.push_back(hole1);

    Ramp rightRamp(renderer, world, 4, 3);
    m_ramps.push_back(rightRamp);

    Ramp rightRampUp2(renderer, world, 5, 3);
    m_ramps.push_back(rightRampUp2);

    Ramp rightRampDown(renderer, world, 6, 2);
    m_ramps.push_back(rightRampDown);
    
    Ramp hole2(renderer, world, 7, 2);
    m_ramps.push_back(hole2);

    Ramp ramp3(renderer, world, 8, 3);
    m_ramps.push_back(ramp3);

    Ramp ramp3Down(renderer, world, 9, 2);
    m_ramps.push_back(ramp3Down);

    Ramp ramp3up2(renderer, world, 10, 3);
    m_ramps.push_back(ramp3up2);

    Ramp ramp1DownMid(renderer, world, 11, 2);
    m_ramps.push_back(ramp1DownMid);

    Ramp backdoorDown(renderer, world, 12, 2);
    m_ramps.push_back(backdoorDown);

    Ramp tunnelDown(renderer, world, 13, 0);
    m_ramps.push_back(tunnelDown);

    BallLock* ballLock = new BallLock(renderer, world, 2, 0);
    m_ballLocks.push_back(ballLock);

    BallLock* underBallLock1 = new BallLock(renderer, world, 0, 1);
    m_ballLocks.push_back(underBallLock1);

    BallLock* underBallLock2 = new BallLock(renderer, world, 0, 2);
    m_ballLocks.push_back(underBallLock2);

    OptWall* leftRailWall = new OptWall(renderer, world, 0, 3);
    m_optWalls.push_back(leftRailWall);

    OptWall* underLayerLock1 = new OptWall(renderer, world, 1, 2);
    underLayerLock1->enable();
    m_optWalls.push_back(underLayerLock1);

    OptWall* underLayerLock2 = new OptWall(renderer, world, 2, 0);
    m_optWalls.push_back(underLayerLock2);

    OptWall* leftKickerLock = new OptWall(renderer, world, 3, 2);
    m_optWalls.push_back(leftKickerLock);

    OptWall* rightKickerLock = new OptWall(renderer, world, 4, 2);
    m_optWalls.push_back(rightKickerLock);

    Trigger* leftTrigger = new Trigger(renderer, world, 0, 2, leftRailWall, underLayerLock2);
    m_triggers.push_back(leftTrigger);

    // Circle bumpers at the top left
    Bumper* bumper1 = new Bumper(renderer, world, 2, -1, 8.6, 2.1);
    m_bumpers.push_back(bumper1);

    Bumper* bumper2 = new Bumper(renderer, world, 2, -1, 9.9, 2.1);
    m_bumpers.push_back(bumper2);

    Bumper* bumper3 = new Bumper(renderer, world, 2, -1, 9.25, 3.0);
    m_bumpers.push_back(bumper3);

    // Under layer bumpers
    Bumper* bumper4 = new Bumper(renderer, world, 0, -1, 6.1, 2.5);
    m_bumpers.push_back(bumper4);

    Bumper* bumper5 = new Bumper(renderer, world, 0, -1, 6.1, 4.5);
    m_bumpers.push_back(bumper5);

    Bumper* bumper6 = new Bumper(renderer, world, 0, -1, 5.5, 3.5);
    m_bumpers.push_back(bumper6);

    // Bumpers for return area bumpers
    Bumper* bumperLeftUpper = new Bumper(renderer, world, 2, 0);
    m_bumpers.push_back(bumperLeftUpper);

    Bumper* bumperLeftLower = new Bumper(renderer, world, 2, 1);
    m_bumpers.push_back(bumperLeftLower);

    Bumper* bumperRightUpper = new Bumper(renderer, world, 2, 2);
    m_bumpers.push_back(bumperRightUpper);

    Bumper* bumperRightLower = new Bumper(renderer, world, 2, 3);
    m_bumpers.push_back(bumperRightLower);

    // Kicker bumpers
    // HACK: the x and y args aren't used if we pass a positive ShapeId so we just pass 0
    Bumper* bumperLeftKicker = new Bumper(renderer, world, 2, 4, 0, 0, leftKickerLock);
    m_bumpers.push_back(bumperLeftKicker);

    Bumper* bumperRightKicker = new Bumper(renderer, world, 2, 5, 0, 0, rightKickerLock);
    m_bumpers.push_back(bumperRightKicker);

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
    
    if (m_lockBallTimers.size() == 0) {
        // We don't want to increment the current ball and put a new one 
        // in the launch tube if we're in the process of spawning a ball from the 
        // lock ball mechanism, so only do this if we don't have any lock ball timers.
        if (m_pinballs.size() < 1) {
            m_currentBall++;
            if (m_currentBall < 5) {
                Pinball* nextPinball = new Pinball(m_renderer, m_b2world);
                m_pinballs.push_back(nextPinball);
            }
            if (m_lockedBalls == -1) {
                m_lockedBalls = 0; // End previous multiball
                m_optWalls.at(1)->enable(); // Close the secret.
            }
            // Disable the kicker locks when starting a new ball.
            // This is pretty forgiving. I like it.
            m_optWalls.at(3)->disable();
            m_optWalls.at(4)->disable();
        }
    }
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

    // If triggering multiball, don't create the replacement ball, multiball will make the 3 balls
    if (m_lockBallTimers.size() > 0 && m_lockedBalls != 3) {
        for (size_t i = 0; i < m_lockBallTimers.size(); i++) {
            int timer = m_lockBallTimers.at(i);
            timer--;
            m_lockBallTimers.at(i) = timer;
            if (timer < 0) {
                int iSpawnPos = getNextBallRelease();
                Pinball* lockBallRelease = new Pinball(m_renderer, m_b2world, iSpawnPos);
                m_pinballs.push_back(lockBallRelease);
                m_lockBallTimers.erase(m_lockBallTimers.begin() + i);
                // Shoot downwards
                b2Vec2 vec(-4.0, 0);
                lockBallRelease->getBody()->ApplyForce(vec, lockBallRelease->getBody()->GetWorldVector(b2Vec2(0, 0)), true);
                break;
            }
        }
    }
    if (m_lockBallTimers.size() > 0 && m_lockedBalls == 3) { // Trigger multiball
        m_optWalls.at(1)->disable(); // Open the secret.
        m_score += 10000;
        m_lockedBalls = -1;
        m_lockBallTimers.clear();
        Pinball* launchedBall = new Pinball(m_renderer, m_b2world, 0);
        // Launch the ball up the launch tube. Some machines actually do this.
        // We do this instead of launching all 3 release slots to give the player more time to deal with all the balls.
        launchedBall->getBody()->ApplyForce(b2Vec2(30 * g_displayFrameRate / 60, 0), launchedBall->getBody()->GetWorldVector(b2Vec2(0, 0)), true);
        m_pinballs.push_back(launchedBall);
        int iPreviousSpawn = -1;
        for (int i = 0; i < 2; i++) {
            int iSpawnPos = getNextBallRelease();
            while (iSpawnPos == iPreviousSpawn) {
                iSpawnPos = getNextBallRelease();
            }
            iPreviousSpawn = iSpawnPos;
            Pinball* multiBall = new Pinball(m_renderer, m_b2world, iSpawnPos);
            m_pinballs.push_back(multiBall);
            // Shoot downwards
            b2Vec2 vec(-4.0, 0);
            multiBall->getBody()->ApplyForce(vec, multiBall->getBody()->GetWorldVector(b2Vec2(0, 0)), true);
        }
    }
    
    m_leftFlipper.update(keys);
    m_rightFlipper.update(keys);
    m_leftFlipper2.update(keys);
    m_rightFlipper2.update(keys);
    m_plunger.update(keys);
    

    for (size_t i = 0; i < m_bumpers.size(); i++) {
        Bumper* bumper = m_bumpers.at(i);
        bumper->update();
    }
    for (size_t t = 0; t < m_triggers.size(); t++) {
        Trigger* trigger = m_triggers.at(t);
        trigger->update();
    }
    if (m_tiltTimer < m_tiltCooldown) {
        m_tiltTimer++;
    }
    else if (m_tiltTimer == m_tiltCooldown) {
        if (Input::Key::Left & keys || Input::Key::Right & keys) {
            double leftOrRight = Input::Key::Left & keys ? -0.9 : 0.9;
            m_tiltTimer = 0;
            for (size_t p = 0; p < m_pinballs.size(); p++) {
                Pinball* pinball = m_pinballs.at(p);
                if (pinball != nullptr) {
                    b2Vec2 vec(1.0, leftOrRight);
                    pinball->getBody()->ApplyForce(vec, pinball->getBody()->GetWorldVector(b2Vec2(0, 0)), true);
                }
            }
        }
    }

    // Multi ball in debug mode at the press of a key
#if DEBUG
    if (Input::Key::Fire1 & keys) {
        Pinball* nextPinball = new Pinball(m_renderer, m_b2world);
        m_pinballs.push_back(nextPinball);
    }
#endif
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

        for (size_t b = 0; b < m_ballLocks.size(); b++) {
            BallLock* ballLock = m_ballLocks.at(b);
            if (!(pinball->isOut()) && ((fixtureA == ballLock->getFixture() && fixtureB == pinball->getFixture()) ||
                (fixtureA == pinball->getFixture() && fixtureB == ballLock->getFixture()))) {
                pinball->removeFromWorld();
                if (m_lockedBalls >= 0 && m_lockedBalls < 3)
                    m_lockedBalls++;
                // This queues a ball to be created in table update.
                // The table makes sure to check this value before ending the game
                // or loading the next ball.
                m_lockBallTimers.push_back(m_lockBallDelay);
                m_score += 1000;
            }
        }

        // If the ball has gone out of bounds and been deleted or locked, then don't
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

        for (size_t t = 0; t < m_triggers.size(); t++) {
            b2Fixture* triggerFixture = m_triggers.at(t)->getFixture();
            if ((fixtureA == triggerFixture && fixtureB == pinball->getFixture()) ||
                (fixtureA == pinball->getFixture() && fixtureB == triggerFixture)) {
                m_triggers.at(t)->press();
            }
        }

        for (size_t b = 0; b < m_bumpers.size(); b++) {
            Bumper* bumper = m_bumpers.at(b);
            b2Fixture* bumperFixture = bumper->getFixture();
            if ((fixtureA == bumperFixture && fixtureB == pinball->getFixture()) ||
                (fixtureA == pinball->getFixture() && fixtureB == bumperFixture)) {
                m_score += 200;
                bumper->setHit();

                // Push the pinball. This has to be queued here and applied in udpate because we're in BeginContact right now.
                b2Vec2 vec = (pinball->getBody()->GetWorldCenter() - (bumper->getBody()->GetWorldCenter()));
                float multiply = bumper->getBumpForce();
                pinball->setBumpVelocity(vec.x * multiply, vec.y * multiply);
            }
        }
    }
}

void Table::EndContact(b2Contact* contact) {

}

bool Table::isGameOver() {
    return m_currentBall > 4;
}

void Table::newGame() {
    m_currentBall = 1;
    m_lockBallLocation = 1;
    Pinball* nextPinball = new Pinball(m_renderer, m_b2world);
    m_pinballs.push_back(nextPinball);
    m_score = 0;
    m_lockedBalls = 0;
    for (size_t t = 0; t < m_triggers.size(); t++) {
        m_triggers.at(t)->reset();
    }
    for (size_t opt = 0; opt < m_optWalls.size(); opt++) {
        m_optWalls.at(opt)->disable();
    }
    m_optWalls.at(1)->enable(); // Close the secret.
}

void Table::updateScoreboard(bool paused) {
    m_scoreboard.update(m_currentBall, m_score, m_lockedBalls, paused);
}

int Table::getNextBallRelease() {
    if (m_lockBallLocation > 3)
        m_lockBallLocation = 1;
    return m_lockBallLocation++;
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
    for (size_t i = 0; i < m_bumpers.size(); i++) {
        Bumper* bumper = m_bumpers.at(i);
        delete bumper;
    }
    for (size_t opt = 0; opt < m_optWalls.size(); opt++) {
        OptWall* optWall = m_optWalls.at(opt);
        delete optWall;
    }
    for (size_t t = 0; t < m_triggers.size(); t++) {
        Trigger* trigger = m_triggers.at(t);
        delete trigger;
    }
    for (size_t b = 0; b < m_ballLocks.size(); b++) {
        BallLock* ballLock = m_ballLocks.at(b);
        delete ballLock;
    }
}
