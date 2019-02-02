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

using namespace c2d;

// This class is at the top of the heirarchy. 
// It stores and manages the pinball, plunger, 
// flippers, layers, box2d events, scoreboard.
class Table : public b2ContactListener {
    public:
        Table(C2DRenderer* renderer, b2World& world);
        void update(unsigned int keys);
        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
    private:
        std::list<Layer> m_layers;
        float m_width = 720;
        float m_height = 1280;
        b2Body* m_ballOutArea;
        b2Fixture* m_ballOutSensor;
        int m_currentBall;
        bool m_ballOut;
        Scoreboard m_scoreboard;
        Flipper m_leftFlipper;
        Flipper m_rightFlipper;
        Plunger m_plunger;
        Pinball m_pinball;
};

#endif