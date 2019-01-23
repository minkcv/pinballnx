#ifndef PINBALL_H_
#define PINBALL_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace c2d;

class Pinball {
    public:
        Pinball(C2DRenderer* renderer, b2World& world);
        void update();
    private:
        b2Body* m_body;
        CircleShape* m_shape;
};
#endif
