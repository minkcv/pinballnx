#ifndef FLIPPER_H_
#define FLIPPER_H_

#include <vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

class Flipper {
    public:
        Flipper(C2DRenderer* renderer, b2World& world, bool rightFlipper);
        void update(unsigned int keys);
    private:
        float m_rotateDirection;
        unsigned int m_key;
        float m_leftX = 0.68f;
        float m_leftY = 2.19f;
        float m_rightX = 0.68f;
        float m_rightY = 4.51f;
        float m_lowerLimit = -M_PI / 8;
        float m_upperLimit = M_PI / 8;
        float m_x;
        float m_y;
        vector<float> m_points = {-16, 0, -10, 93, -6, 99, -2.5, 100, 2.5, 100, 6, 99, 10, 93, 16, 0};
        b2RevoluteJoint* m_joint;
        ConvexShape* m_cshape;
        C2DTexture* m_texture;
        b2Body* m_body;
        b2Body* m_pivot;
};

#endif