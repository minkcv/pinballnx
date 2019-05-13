#ifndef BUMPER_H_
#define BUMPER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace c2d;

class Bumper {
    public:
        Bumper(C2DRenderer* renderer, b2World& world, int layerID, float x, float y);
        b2Fixture* getFixture();
        b2Body* getBody();
        void update();
        void setHit();
    private:
        int m_layerID;
        b2Fixture* m_fixture;
        b2Body* m_body;
        CircleShape* m_shape;
        C2DTexture* m_texture1;
        C2DTexture* m_texture2;
        float m_radius = 0.3;
        float m_sensorRadius = 0.32;
        int m_flashFrames = 16;
        int m_flashFrameCurrent = m_flashFrames;
};
#endif
