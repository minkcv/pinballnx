#ifndef BALLLOCK_H_
#define BALLLOCK_H_

#include <vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

class BallLock {
    public:
        BallLock(C2DRenderer* renderer, b2World& world, int layerID, int shapeID, int releaseLocation, bool multi = false);
        void update();
        b2Fixture* getFixture();
        void trigger();
        bool release();
        int getLocation();
        int getNumLocked();
        void reset();
    private:
        int m_layerID;
        int m_releaseLocation;
        bool m_multi;
        int m_move;
        int m_locked;
        int m_capacity = 4;
        float m_xOffset = 16.5;
        float m_yOffset = 16;
        vector<C2DTexture*> m_textures;
        b2Fixture* m_fixture;
        b2Body* m_body;
        ConvexShape* m_cshape;
        vector<float> m_upperLock = {744.2, 494.2, 743.0, 495.4, 743.0, 497.5, 743.0, 499.6, 744.2, 500.8, 745.4, 502.0, 747.5, 502.0, 749.6, 502.0, 750.8, 500.8, 752.0, 499.6, 752.0, 497.5, 752.0, 495.4, 750.8, 494.2, 749.6, 493.0, 747.5, 493.0, 745.4, 493.0, 744.2, 494.2};
        vector<float> m_leftLock = {1086.2, 23.2, 1085.0, 24.4, 1085.0, 27.5, 1085.0, 30.6, 1086.2, 31.8, 1087.4, 33.0, 1090.5, 33.0, 1093.6, 33.0, 1094.8, 31.8, 1096.0, 30.6, 1096.0, 27.5, 1096.0, 24.4, 1094.8, 23.2, 1093.6, 22.0, 1090.5, 22.0, 1087.4, 22.0, 1086.2, 23.2};
        vector<float> m_middleLock = {772.5, 364.9, 770.5, 365.8, 768.0, 368.5, 765.5, 371.2, 765.5, 376.6, 765.5, 382.0, 768.7, 385.1, 771.9, 388.3, 777.4, 388.8, 782.9, 389.2, 785.9, 385.9, 788.9, 382.6, 789.6, 379.7, 790.2, 376.8, 789.6, 373.6, 789.0, 370.4, 786.1, 367.6, 783.2, 364.8, 778.8, 364.4, 774.5, 364.0, 772.5, 364.9};
        vector<float> m_upperMiddleLock = {779.0, 398.4, 779.0, 411.0, 782.1, 411.0, 785.1, 411.0, 788.0, 407.8, 790.9, 404.6, 791.6, 401.7, 792.2, 398.8, 791.6, 395.6, 791.0, 392.4, 788.2, 389.7, 785.4, 387.0, 782.2, 386.4, 779.0, 385.7, 779.0, 398.4};
        vector<float> m_lowerLock1 = {204.4, 262.4, 203.8, 263.9, 204.2, 265.7, 204.5, 267.5, 207.5, 267.5, 210.5, 267.5, 210.5, 264.5, 210.5, 261.5, 207.7, 261.2, 205.0, 260.9, 204.4, 262.4};
        vector<float> m_lowerLock2 = {386.0, 499.0, 386.0, 518.0, 397.5, 518.0, 409.0, 518.0, 409.0, 499.0, 409.0, 480.0, 397.5, 480.0, 386.0, 480.0, 386.0, 499.0};
        vector<float> m_railLock1 = {805.5, 433.5, 803.0, 435.9, 803.0, 439.5, 803.0, 443.1, 805.5, 445.5, 807.9, 448.0, 811.5, 448.0, 815.1, 448.0, 817.5, 445.5, 820.0, 443.1, 820.0, 439.5, 820.0, 435.9, 817.5, 433.5, 815.1, 431.0, 811.5, 431.0, 807.9, 431.0, 805.5, 433.5};
        vector<float> m_lowerLock3 = {217.2, 380.3, 215.0, 382.6, 215.0, 384.6, 215.0, 386.7, 217.3, 388.8, 219.6, 391.0, 221.6, 391.0, 223.7, 391.0, 225.8, 388.7, 228.0, 386.4, 228.0, 384.4, 228.0, 382.3, 225.7, 380.2, 223.4, 378.0, 221.4, 378.0, 219.3, 378.0, 217.2, 380.3};
        vector<vector<float>> m_points = {
            m_upperLock, m_leftLock, m_middleLock, m_upperMiddleLock, m_lowerLock1, m_lowerLock2, m_railLock1, m_lowerLock3
        };
};

#endif