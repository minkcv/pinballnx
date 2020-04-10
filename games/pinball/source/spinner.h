#ifndef SPINNER_H_
#define SPINNER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include <stdlib.h>

using namespace c2d;
using namespace std;

class Spinner {
    public:
        Spinner(C2DRenderer* renderer, b2World& world, int layerID, int spinnerID);
        void update();
        int getPush();
        void push(b2Vec2 ballVelocity);
        b2Fixture* getFixture();
    private:
        int m_layerID;
        int m_push = 0;
        b2Fixture* m_fixture;
        b2Body* m_body;
        static const int m_frames = 10;
        int m_currentFrame = 0;
        int m_frameDuration = 0;
        int m_frameTimer = 0;
        C2DTexture* m_textures[m_frames];
        ConvexShape* m_shape;
        vector<float> m_topLeftSpinner = {948.0, 539.7, 944.5, 541.5, 943.2, 545.2, 941.8, 548.9, 943.6, 552.7, 945.5, 556.5, 949.1, 557.8, 952.7, 559.2, 956.4, 557.6, 960.1, 556.1, 961.6, 552.5, 963.1, 548.8, 962.0, 545.4, 960.8, 541.9, 958.7, 540.5, 956.5, 539.1, 954.0, 538.5, 951.5, 538.0, 948.0, 539.7};
        vector<vector<float>> m_shapes = {
            m_topLeftSpinner
        };
        vector<float> m_positions = {
            937, 534
        };
};

#endif