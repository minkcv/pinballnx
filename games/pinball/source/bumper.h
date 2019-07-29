#ifndef BUMPER_H_
#define BUMPER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include <list>
#include <string>

using namespace c2d;
using namespace std;

class Bumper {
    public:
        // -1 for shapeID creates circle
        Bumper(C2DRenderer* renderer, b2World& world, int layerID, int shapeID, float x = 0, float y = 0);
        b2Fixture* getFixture();
        b2Body* getBody();
        void update();
        void setHit();
        float getBumpForce();
    private:
        int m_layerID;
        b2Fixture* m_fixture;
        b2Body* m_body;
        C2DTexture* m_texture1;
        C2DTexture* m_texture2;
        float m_bumpForce;
        float m_radius = 0.3;
        float m_sensorRadius = 0.32;
        int m_flashFrames = 16;
        int m_flashFrameCurrent = m_flashFrames;
        vector<float> m_leftCenterUpper = {200, 120};
        vector<float> m_leftCenterLower = {150, 120};
        vector<float> m_rightCenterUpper = {200, 560};
        vector<float> m_rightCenterLower = {150, 560};
        vector<float> m_leftKickerCenter = {-20, 32};
        vector<float> m_rightKickerCenter = {-20, 640};
        vector<vector<float>> m_centers = {m_leftCenterUpper, m_leftCenterLower, m_rightCenterUpper, m_rightCenterLower, m_leftKickerCenter, m_rightKickerCenter};
        vector<float> m_leftBumperUpper = {226.8, 133.3, 207.0, 143.5, 207.0, 149.3, 207.0, 155.0, 215.3, 149.7, 223.5, 144.3, 237.8, 135.0, 252.1, 125.7, 251.7, 124.6, 251.3, 123.5, 248.9, 123.3, 246.5, 123.0, 226.8, 133.3};
        vector<float> m_leftBumperLower = {176.9, 159.3, 147.3, 174.5, 145.6, 175.9, 144.0, 177.2, 144.0, 179.2, 144.0, 181.1, 145.4, 181.6, 146.9, 182.2, 174.5, 170.1, 202.2, 158.1, 204.6, 156.5, 207.0, 155.0, 207.0, 149.5, 207.0, 144.0, 176.9, 159.3};
        vector<float> m_rightBumperUpper = {207.0, 522.7, 207.0, 528.5, 227.0, 538.8, 247.0, 549.1, 249.2, 548.8, 251.3, 548.5, 251.7, 547.4, 252.1, 546.3, 237.8, 537.0, 223.5, 527.7, 215.3, 522.3, 207.0, 517.0, 207.0, 522.7};
        vector<float> m_rightBumperLower = {144.7, 490.6, 144.0, 491.3, 144.0, 493.0, 144.0, 494.7, 145.8, 496.2, 147.5, 497.7, 177.3, 512.9, 207.0, 528.0, 207.0, 522.5, 207.0, 517.0, 204.6, 515.5, 202.2, 513.9, 175.9, 502.4, 149.5, 490.9, 147.5, 490.4, 145.4, 489.9, 144.7, 490.6};
        vector<float> m_leftKicker = {10.0, 31.0, 10.0, 44.0, 23.5, 44.0, 37.0, 44.0, 37.0, 31.0, 37.0, 18.0, 23.5, 18.0, 10.0, 18.0, 10.0, 31.0};
        vector<float> m_rightKicker = {10.0, 640.5, 10.0, 654.0, 23.5, 654.0, 37.0, 654.0, 37.0, 640.5, 37.0, 627.0, 23.5, 627.0, 10.0, 627.0, 10.0, 640.5};
        vector<vector<float>> m_shapes = {
            m_leftBumperUpper, m_leftBumperLower, m_rightBumperUpper, m_rightBumperLower, m_leftKicker, m_rightKicker
        };
        // sprite positions (x, y)
        vector<float> m_positions {
            144, 130,
            144, 130,
            144, 485,
            144, 485,
            10, 18,
            10, 628
        };
};
#endif
