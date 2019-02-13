#ifndef KICKER_H_
#define KICKER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

class Kicker {
    public:
        Kicker(C2DRenderer* renderer, b2World& world, bool right);
        void update();
        b2Fixture* getFixture();
        void setHit();
    private:
        b2Body* m_body;
        b2Fixture* m_fixture;
        RectangleShape* m_shape;
        C2DTexture* m_texture;
        b2PrismaticJoint* m_joint;
        float m_leftX = 0.34;
        float m_leftY = 0.33;
        float m_rightX = 0.34;
        float m_rightY = 6.38;
        float m_halfHeight = 0.1;
        float m_halfWidth = 0.175;
        int m_hitFrames = 1;
        int m_hitFrameCurrent = m_hitFrames;
};

#endif