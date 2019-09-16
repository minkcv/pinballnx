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
        void update(unsigned int keys);
        b2Fixture* getFixture();
        b2Vec2 getDirection();
        void resetDirection();
    private:
        b2Fixture* m_fixture;
        int m_layerID;
        b2Vec2 m_direction;
        static const int m_frames = 7;
        int m_currentFrame = 0;
        int m_frameDuration = 30 / g_displayFrameRate;
        int m_frameTimer = 0;
        C2DTexture* m_textureEnabled[m_frames];
        C2DTexture* m_textureDisabled[m_frames];
        ConvexShape* m_shape;
        vector<float> m_topConveyor = {1100, 250, 1145, 250, 1145, 495, 1100, 495};
        vector<vector<float>> m_shapes = {
            m_topConveyor
        };
        vector<float> m_positions = {
            1100, 248
        };
};

#endif