#ifndef PLUNGER_H_
#define PLUNGER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

class Plunger {
    public:
        Plunger(C2DRenderer* renderer, b2World& world);
        void update(unsigned int keys);
    private:
        float m_halfWidth = 0.5f;
        float m_halfHeight = 0.1f;
        float m_startX = 0.6f;
        float m_startY = 6.9;
        b2Body* m_body;
        b2Body* m_constraint;
        b2PrismaticJoint* m_joint;
        RectangleShape* m_shape;
};

#endif