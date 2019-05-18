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
        vector<float> m_leftCenter = {130, 140};
        vector<float> m_rightCenter = {130, 540};
        vector<float> m_leftKickerCenter = {-20, 32};
        vector<float> m_rightKickerCenter = {-20, 640};
        vector<vector<float>> m_centers = {m_leftCenter, m_rightCenter, m_leftKickerCenter, m_rightKickerCenter};
        vector<float> m_leftBumperShape = {214.0, 140.1, 181.5, 157.2, 164.5, 165.7, 147.5, 174.2, 145.8, 175.8, 144.0, 177.3, 144.0, 179.2, 144.0, 181.1, 145.4, 181.6, 146.8, 182.1, 172.7, 171.0, 198.5, 159.8, 201.4, 158.3, 204.4, 156.8, 228.2, 141.2, 252.1, 125.7, 251.7, 124.6, 251.3, 123.5, 248.9, 123.2, 246.5, 123.0, 214.0, 140.1};
        vector<float> m_rightBumperShape = {144.3, 491.6, 143.7, 493.3, 144.7, 494.9, 145.6, 496.5, 155.1, 501.3, 164.5, 506.2, 205.7, 527.7, 246.9, 549.2, 249.1, 548.8, 251.3, 548.5, 251.7, 547.4, 252.1, 546.3, 228.2, 530.8, 204.4, 515.2, 201.4, 513.7, 198.5, 512.2, 172.8, 501.1, 147.2, 490.0, 146.1, 490.0, 144.9, 490.0, 144.3, 491.6};
        vector<float> m_leftKicker = {10.0, 31.0, 10.0, 44.0, 23.5, 44.0, 37.0, 44.0, 37.0, 31.0, 37.0, 18.0, 23.5, 18.0, 10.0, 18.0, 10.0, 31.0};
        vector<float> m_rightKicker = {10.0, 640.5, 10.0, 654.0, 23.5, 654.0, 37.0, 654.0, 37.0, 640.5, 37.0, 627.0, 23.5, 627.0, 10.0, 627.0, 10.0, 640.5};
        vector<vector<float>> m_shapes = {
            m_leftBumperShape, m_rightBumperShape, m_leftKicker, m_rightKicker
        };
};
#endif
