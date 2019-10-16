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
        vector<float> m_leftLock = {1134.2, 23.2, 1133.0, 24.4, 1133.0, 27.5, 1133.0, 30.6, 1134.2, 31.8, 1135.4, 33.0, 1138.5, 33.0, 1141.6, 33.0, 1142.8, 31.8, 1144.0, 30.6, 1144.0, 27.5, 1144.0, 24.4, 1142.8, 23.2, 1141.6, 22.0, 1138.5, 22.0, 1135.4, 22.0, 1134.2, 23.2};
        vector<float> m_middleLock = {769.5, 223.9, 767.5, 224.8, 765.0, 227.5, 762.5, 230.2, 762.5, 235.6, 762.5, 241.0, 765.7, 244.1, 768.9, 247.3, 774.4, 247.8, 779.9, 248.2, 782.9, 244.9, 785.9, 241.6, 786.6, 238.7, 787.2, 235.8, 786.6, 232.6, 786.0, 229.4, 783.1, 226.6, 780.2, 223.8, 775.8, 223.4, 771.5, 223.0, 769.5, 223.9};
        vector<float> m_lowerLock1 = {172.0, 229.0, 172.0, 248.0, 183.5, 248.0, 195.0, 248.0, 195.0, 229.0, 195.0, 210.0, 183.5, 210.0, 172.0, 210.0, 172.0, 229.0};
        vector<float> m_lowerLock2 = {118.0, 351.0, 118.0, 370.0, 129.5, 370.0, 141.0, 370.0, 141.0, 351.0, 141.0, 332.0, 129.5, 332.0, 118.0, 332.0, 118.0, 351.0};
        vector<vector<float>> m_points = {
            m_upperLock, m_leftLock, m_middleLock, m_lowerLock1, m_lowerLock2
        };
};

#endif