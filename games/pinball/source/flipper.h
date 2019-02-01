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
        float m_leftX = 0.74f;
        float m_leftY = 2.32f;
        float m_rightX = 0.74f;
        float m_rightY = 4.40f;
        float m_lowerLimit = -M_PI / 8;
        float m_upperLimit = M_PI / 8;
        float m_x;
        float m_y;
        float m_points[16] = {-16, 0, -8, 75, -5, 79, -2, 80, 2, 80, 5, 79, 8, 75, 16, 0};
        b2RevoluteJoint* m_joint;
        ConvexShape* m_cshape;
        b2Body* m_body;
        b2Body* m_pivot;
};

#endif