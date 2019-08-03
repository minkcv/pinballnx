#ifndef BALLLOCK_H_
#define BALLLOCK_H_

#include <vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

class BallLock {
    public:
        BallLock(C2DRenderer* renderer, b2World& world, int layerID, int shapeID);
        b2Fixture* getFixture();
    private:
        int m_layerID;
        b2Fixture* m_fixture;
        vector<float> m_upperLock = {843.5, 532.5, 835.8, 540.9, 834.4, 543.6, 833.0, 546.2, 833.0, 548.1, 833.0, 549.9, 850.2, 564.0, 867.4, 578.0, 869.5, 578.0, 871.5, 578.0, 881.8, 567.7, 892.0, 557.5, 892.0, 555.2, 892.0, 553.0, 873.8, 538.5, 855.5, 524.0, 853.3, 524.0, 851.2, 524.0, 843.5, 532.5};
        vector<float> m_lowerLock1 = {172.0, 229.0, 172.0, 248.0, 183.5, 248.0, 195.0, 248.0, 195.0, 229.0, 195.0, 210.0, 183.5, 210.0, 172.0, 210.0, 172.0, 229.0};
        vector<float> m_lowerLock2 = {118.0, 351.0, 118.0, 370.0, 129.5, 370.0, 141.0, 370.0, 141.0, 351.0, 141.0, 332.0, 129.5, 332.0, 118.0, 332.0, 118.0, 351.0};
        vector<vector<float>> m_points = {
            m_upperLock, m_lowerLock1, m_lowerLock2
        };
};

#endif