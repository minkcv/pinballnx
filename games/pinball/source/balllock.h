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
        vector<float> m_lowerLock1 = {344.0, 232.0, 344.0, 251.0, 355.5, 251.0, 367.0, 251.0, 367.0, 232.0, 367.0, 213.0, 355.5, 213.0, 344.0, 213.0, 344.0, 232.0};
        vector<float> m_lowerLock2 = {344.0, 317.0, 344.0, 336.0, 355.5, 336.0, 367.0, 336.0, 367.0, 317.0, 367.0, 298.0, 355.5, 298.0, 344.0, 298.0, 344.0, 317.0};
        vector<float> m_lowerLock3 = {440.6, 371.2, 439.2, 373.5, 433.5, 391.3, 427.9, 409.2, 428.2, 412.3, 428.5, 415.3, 431.5, 417.0, 434.5, 418.7, 446.5, 423.3, 458.6, 428.0, 461.7, 428.0, 464.8, 428.0, 466.0, 426.6, 467.2, 425.1, 471.1, 409.8, 475.1, 394.5, 476.2, 388.2, 477.4, 381.9, 476.4, 380.2, 475.3, 378.5, 462.4, 373.8, 449.5, 369.2, 445.8, 369.1, 442.0, 369.0, 440.6, 371.2};
        vector<vector<float>> m_points = {
            m_upperLock, m_lowerLock1, m_lowerLock2, m_lowerLock3
        };
};

#endif