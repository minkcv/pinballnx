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
        vector<float> m_topConveyor = {1100, 250, 1145, 250, 1145, 495, 1100, 495};
        vector<vector<float>> m_shapes = {
            m_topConveyor
        };
        vector<float> m_positions = {
            11.03, 2.1
        };
};

#endif