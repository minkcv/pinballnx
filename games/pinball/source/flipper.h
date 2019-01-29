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
        float m_leftX = 0.78f;
        float m_leftY = 2.4f;
        float m_rightX = 0.78f;
        float m_rightY = 4.3f;
        float m_leftLowerLimit = -M_PI / 8;
        float m_leftUpperLimit = M_PI / 8;
        float m_rightLowerLimit = -M_PI / 8;
        float m_rightUpperLimit = M_PI / 8;
        float m_x;
        float m_y;
        float m_lowerLimit;
        float m_upperLimit;
        float m_points[144] = {7.7, 2.1, 11.5, 0.1, 15.8, -1.5099e-14, 15.8, -1.5099e-14, 20.1, -1.5099e-14, 24, 2, 24, 2, 28, 4, 30.1, 8.2, 30.1, 8.2, 32.2, 12.4, 31.6, 19.9, 31.6, 19.9, 30.9, 27.5, 27.9, 57.8, 27.9, 57.8, 24.9, 88, 24.1, 90.3, 24.1, 90.3, 23.2, 92.6, 21.5, 94, 21.5, 94, 19.8, 95.4, 16.5, 95.4, 16.5, 95.4, 13.1, 95.4, 11.1, 93.6, 11.1, 93.6, 9.1, 91.8, 8.2, 87.2, 8.2, 87.2, 7.2, 82.5, 3.4, 47.7, 3.4, 47.7, -0.4, 13, 1.8, 8.5, 1.8, 8.5, 3.9, 4.1, 7.7, 2.1, 7.7, 2.1, 15.8, -1.5099e-14, 24, 2, 24, 2, 30.1, 8.2, 31.6, 19.9, 31.6, 19.9, 27.9, 57.8, 24.1, 90.3, 24.1, 90.3, 21.5, 94, 16.5, 95.4, 16.5, 95.4, 11.1, 93.6, 8.2, 87.2, 8.2, 87.2, 3.4, 47.7, 1.8, 8.5, 1.8, 8.5, 7.7, 2.1, 24, 2, 24, 2, 31.6, 19.9, 24.1, 90.3, 24.1, 90.3, 16.5, 95.4, 8.2, 87.2, 8.2, 87.2, 1.8, 8.5, 24, 2, 24, 2, 24.1, 90.3, 8.2, 87.2};
        b2RevoluteJoint* m_joint;
        ConvexShape* m_cshape;
        b2Body* m_body;
        b2Body* m_pivot;
};

#endif