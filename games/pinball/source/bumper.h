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
    private:
        b2Fixture* m_fixture;
        ConvexShape* m_shape;
        C2DTexture* m_texture;
        float m_radius = 0.3;
        float m_sensorRadius = 0.35;
};
#endif
