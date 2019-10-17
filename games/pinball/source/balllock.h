#ifndef BALLLOCK_H_
#define BALLLOCK_H_

#include <vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

class BallLock {
    public:
        BallLock(C2DRenderer* renderer, b2World& world, int layerID, int shapeID, int releaseLocation);
        b2Fixture* getFixture();
        int getLocation();
    private:
        int m_layerID;
        int m_releaseLocation;
        b2Fixture* m_fixture;
        vector<float> m_upperLock = {843.5, 532.5, 835.8, 540.9, 834.4, 543.6, 833.0, 546.2, 833.0, 548.1, 833.0, 549.9, 850.2, 564.0, 867.4, 578.0, 869.5, 578.0, 871.5, 578.0, 881.8, 567.7, 892.0, 557.5, 892.0, 555.2, 892.0, 553.0, 873.8, 538.5, 855.5, 524.0, 853.3, 524.0, 851.2, 524.0, 843.5, 532.5};
        vector<float> m_leftLock = {1086.2, 23.2, 1085.0, 24.4, 1085.0, 27.5, 1085.0, 30.6, 1086.2, 31.8, 1087.4, 33.0, 1090.5, 33.0, 1093.6, 33.0, 1094.8, 31.8, 1096.0, 30.6, 1096.0, 27.5, 1096.0, 24.4, 1094.8, 23.2, 1093.6, 22.0, 1090.5, 22.0, 1087.4, 22.0, 1086.2, 23.2};
        vector<float> m_middleLock = {772.5, 359.9, 770.5, 360.8, 768.0, 363.5, 765.5, 366.2, 765.5, 371.6, 765.5, 377.0, 768.7, 380.1, 771.9, 383.3, 777.4, 383.8, 782.9, 384.2, 785.9, 380.9, 788.9, 377.6, 789.6, 374.7, 790.2, 371.8, 789.6, 368.6, 789.0, 365.4, 786.1, 362.6, 783.2, 359.8, 778.8, 359.4, 774.5, 359.0, 772.5, 359.9};
        vector<float> m_lowerLock1 = {172.0, 229.0, 172.0, 248.0, 183.5, 248.0, 195.0, 248.0, 195.0, 229.0, 195.0, 210.0, 183.5, 210.0, 172.0, 210.0, 172.0, 229.0};
        vector<float> m_lowerLock2 = {118.0, 351.0, 118.0, 370.0, 129.5, 370.0, 141.0, 370.0, 141.0, 351.0, 141.0, 332.0, 129.5, 332.0, 118.0, 332.0, 118.0, 351.0};
        vector<vector<float>> m_points = {
            m_upperLock, m_leftLock, m_middleLock, m_lowerLock1, m_lowerLock2
        };
};

#endif