#ifndef TABLE_H_
#define TABLE_H_

#include <list>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include "pinball.h"
#include "flipper.h"
#include "plunger.h"
#include "layer.h"
#include "scoreboard.h"
#include "ramp.h"
#include "bumper.h"
#include "optwall.h"
#include "trigger.h"
#include "balllock.h"
#include "conveyor.h"

using namespace c2d;
using namespace std;

// This class is at the top of the heirarchy. 
// It stores and manages the pinball, plunger, 
// flippers, layers, box2d events, scoreboard.
// The box2d events detect when the ball passes 
// out of bounds, onto and off of ramps, and 
// onto and off of scoring triggers.
class Table : public b2ContactListener {
    public:
        Table(C2DRenderer* renderer, b2World& world);
        void update(unsigned int keys);
        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
        bool isGameOver();
        void newGame();
        void updateScoreboard(bool paused);
        void cleanup();
    private:
        int getNextBallRelease();
        vector<Layer> m_layers;
        vector<Ramp> m_ramps;
        vector<OptWall*> m_optWalls;
        vector<Trigger*> m_triggers;
        vector<Bumper*> m_bumpers;
        vector<Pinball*> m_pinballs;
        vector<int> m_lockBallTimers;
        vector<BallLock*> m_ballLocks;
        vector<Conveyor*> m_conveyors;
        Scoreboard m_scoreboard;
        Flipper m_leftFlipper;
        Flipper m_rightFlipper;
        Flipper m_leftFlipper2;
        Flipper m_rightFlipper2;
        Plunger m_plunger;
        C2DRenderer* m_renderer;
        // The width of the table, which is the height of the screen.
        float m_width = 720;
        // The height of the table, which is the width of the screen.
        float m_height = 1280;
        b2World* m_b2world;
        b2Body* m_ballOutArea;
        b2Fixture* m_ballOutSensor;
        int m_currentBall;
        int m_maxBalls = 4;
        int m_score;
        int m_lockedBalls;
        int m_lockBallDelay = 1920 / g_displayFrameRate;
        int m_lockBallLocation = 1;
        int m_tiltCooldown = 6000  / g_displayFrameRate;
        int m_tiltTimer = m_tiltCooldown;
};

#endif
