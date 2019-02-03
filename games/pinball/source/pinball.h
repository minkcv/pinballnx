#ifndef PINBALL_H_
#define PINBALL_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace c2d;

class Pinball {
    public:
        Pinball(C2DRenderer* renderer, b2World* world);
        void update(C2DRenderer* renderer, b2World* world);
        b2Fixture* getFixture();
        uint16 getCollisionMask();
        void setCollisionMask(uint16 mask);
        void removeFromWorld();
        bool cleanupDone();
    private:
        b2Body* m_body;
        b2Fixture* m_fixture;
        CircleShape* m_shape;

        // Box2D works best with objects between 0.1m and 10m in size.
        // A pinball is normally 0.027 meters in diameter, but this is too small for Box2D.
        // We simulate a pinball with a diameter of 0.16m and scale the pinball machine around this.
        float m_radius = 0.08;

        // Coordinates for the launch tube.
        float m_startX = 2.0f;
        float m_startY = 6.9f;
        bool m_ballOut = false;
        bool m_removed = false;
};
#endif
