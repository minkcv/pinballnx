#ifndef BUMPER_H_
#define BUMPER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include <list>
#include <string>
#include "optwall.h"

using namespace c2d;
using namespace std;

class Bumper {
    public:
        // -1 for shapeID creates circle
        Bumper(C2DRenderer* renderer, b2World& world, int layerID, int shapeID, float x = 0, float y = 0, OptWall* optwall = nullptr, int isKicker = 0);
        b2Fixture* getFixture();
        b2Body* getBody();
        void update();
        void setHit();
        float getBumpForce();
        int isKicker();
    private:
        int m_layerID;
        int m_isKicker;
        b2Fixture* m_fixture;
        b2Body* m_body;
        C2DTexture* m_texture1;
        C2DTexture* m_texture2;
        OptWall* m_optwall;
        float m_bumpForce;
        float m_radius = 0.25;
        int m_flashFrames = 16;
        int m_flashFrameCurrent = m_flashFrames;
        int m_lockDelay = 16;
        int m_lockDelayCurrent = m_lockDelay + 1;
        vector<float> m_leftCenterUpper = {200, 0};
        vector<float> m_leftCenterLower = {120, 0};
        vector<float> m_rightCenterUpper = {200, 720};
        vector<float> m_rightCenterLower = {120, 720};
        vector<float> m_leftKickerCenter = {-20, 32};
        vector<float> m_rightKickerCenter = {-20, 640};
        vector<float> m_underBumperCenter = {358, 264};
        vector<float> m_underBumperCenter2 = {238, 402};
        vector<vector<float>> m_centers = {m_leftCenterUpper, m_leftCenterLower, m_rightCenterUpper, m_rightCenterLower, m_leftKickerCenter, m_rightKickerCenter, m_underBumperCenter, m_underBumperCenter2};
        vector<float> m_leftBumperUpper = {226.8, 133.3, 207.0, 143.5, 207.0, 149.3, 207.0, 155.1, 207.8, 154.7, 208.5, 154.3, 231.2, 141.1, 253.9, 127.8, 252.3, 125.4, 250.8, 123.0, 248.6, 123.0, 246.5, 123.1, 226.8, 133.3};
        vector<float> m_leftBumperLower = {176.7, 159.5, 146.8, 174.8, 145.3, 176.3, 143.8, 177.8, 144.5, 180.9, 145.2, 184.0, 161.1, 176.6, 176.5, 169.3, 190.7, 163.1, 204.9, 156.8, 206.0, 155.5, 207.1, 154.2, 206.8, 149.2, 206.5, 144.2, 176.7, 159.5};
        vector<float> m_rightBumperUpper = {207.0, 522.7, 207.0, 528.5, 226.9, 538.7, 246.7, 549.0, 248.8, 549.0, 250.8, 549.0, 252.3, 546.6, 253.9, 544.2, 231.2, 531.0, 208.5, 517.7, 207.8, 517.3, 207.0, 516.9, 207.0, 522.7};
        vector<float> m_rightBumperLower = {144.5, 491.1, 143.8, 494.2, 145.6, 496.0, 147.5, 497.7, 177.3, 512.9, 207.0, 528.0, 207.0, 522.5, 207.0, 517.0, 204.7, 515.5, 202.4, 514.0, 188.4, 507.9, 174.5, 501.8, 160.1, 494.9, 145.7, 488.0, 144.5, 491.1};
        vector<float> m_leftKicker = {10.0, 31.0, 10.0, 44.0, 23.5, 44.0, 37.0, 44.0, 37.0, 31.0, 37.0, 18.0, 23.5, 18.0, 10.0, 18.0, 10.0, 31.0};
        vector<float> m_rightKicker = {10.0, 640.5, 10.0, 654.0, 23.5, 654.0, 37.0, 654.0, 37.0, 640.5, 37.0, 627.0, 23.5, 627.0, 10.0, 627.0, 10.0, 640.5};
        vector<float> m_underBumper = {457.5, 451.3, 456.9, 452.6, 457.2, 465.6, 457.5, 478.5, 464.0, 478.5, 470.5, 478.5, 470.5, 464.5, 470.5, 450.5, 464.2, 450.2, 458.0, 449.9, 457.5, 451.3};
        vector<float> m_underBumper2 = {319.5, 166.3, 318.9, 167.6, 319.2, 179.6, 319.5, 191.5, 326.5, 191.5, 333.5, 191.5, 333.5, 178.5, 333.5, 165.5, 326.7, 165.2, 320.0, 164.9, 319.5, 166.3};
        vector<vector<float>> m_shapes = {
            m_leftBumperUpper, m_leftBumperLower, m_rightBumperUpper, m_rightBumperLower, m_leftKicker, m_rightKicker, m_underBumper, m_underBumper2
        };
        // sprite positions (x, y)
        vector<float> m_positions {
            144, 130,
            144, 130,
            144, 485,
            144, 485,
            10, 18,
            10, 628,
            457, 461,
            319, 175
        };
};
#endif
