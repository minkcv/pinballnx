#ifndef FLIPPER_H_
#define FLIPPER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

class Flipper {
    public:
        Flipper(C2DRenderer* renderer, b2World& world, bool rightFlipper);
        void update(unsigned int keys);
    private:
        float m_rotateDirection;
        unsigned int m_key;
        float m_leftX = 0.58f;
        float m_leftY = 2.16f;
        float m_rightX = 0.90f;
        float m_rightY = 4.56f;
        float m_leftLowerLimit = -M_PI / 8;
        float m_leftUpperLimit = M_PI / 8;
        float m_rightLowerLimit = -M_PI / 8;
        float m_rightUpperLimit = M_PI / 8;
        float m_x;
        float m_y;
        float m_lowerLimit;
        float m_upperLimit;
        float m_points[16] = {0, 16, 8, 91, 11, 95, 14, 96, 18, 96, 21, 95, 24, 91, 32, 16};
        b2RevoluteJoint* m_joint;
        ConvexShape* m_cshape;
        b2Body* m_body;
        b2Body* m_pivot;
};

#endif