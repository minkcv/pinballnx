#ifndef CONVEYOR_H_
#define CONVEYOR_H_

#include <vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace c2d;
using namespace std;

class Conveyor {
    public:
        Conveyor(C2DRenderer* renderer, b2World& world, int conveyorID, int layerID);
        b2Fixture* getFixture();
        void setDirection(b2Vec2);
        b2Vec2 getDirection();
    private:
        b2Fixture* m_fixture;
        int m_layerID;
        b2Vec2 m_direction;
        C2DTexture* m_textureEnabled;
        C2DTexture* m_textureDisabled;
        ConvexShape* m_shape;
        vector<float> m_topConveyor = {1104.7, 246.8, 1103.0, 248.7, 1103.0, 372.7, 1103.0, 496.7, 1104.8, 498.3, 1106.7, 500.0, 1119.7, 500.0, 1132.7, 500.0, 1134.3, 498.2, 1136.0, 496.3, 1136.0, 372.3, 1136.0, 248.3, 1134.2, 246.7, 1132.3, 245.0, 1119.3, 245.0, 1106.3, 245.0, 1104.7, 246.8};
        vector<vector<float>> m_shapes = {
            m_topConveyor
        };
        vector<float> m_positions = {
            11.03, 2.1
        };
};

#endif