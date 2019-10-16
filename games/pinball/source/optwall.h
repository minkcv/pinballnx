#ifndef OPTWALL_H_
#define OPTWALL_H_

#include<vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

class OptWall {
    public:
        OptWall(C2DRenderer* renderer, b2World& world, int optWallId, int layerID);
        void disable();
        void enable();
        bool isEnabled();
    private:
        b2Fixture* m_fixture;
        int m_layerID;
        C2DTexture* m_textureEnabled;
        C2DTexture* m_textureDisabled;
        ConvexShape* m_shapeEnabled;
        bool m_isEnabled;

        vector<float> m_leftRailWall = {1057.0, 296.6, 1051.5, 300.2, 1044.5, 303.6, 1037.5, 306.9, 1031.0, 308.0, 1024.5, 309.0, 998.9, 309.0, 973.3, 309.0, 971.4, 311.1, 969.6, 313.1, 970.7, 314.8, 971.7, 316.5, 999.6, 316.3, 1027.5, 316.2, 1035.2, 314.7, 1042.8, 313.1, 1048.2, 310.4, 1053.5, 307.7, 1060.3, 303.4, 1067.0, 299.0, 1067.0, 297.2, 1067.0, 295.4, 1065.8, 294.2, 1064.6, 293.0, 1063.6, 293.0, 1062.5, 293.1, 1057.0, 296.6};
        vector<float> m_underLayerLock1 = {697.7, 7.7, 697.0, 8.3, 697.0, 27.7, 697.0, 47.0, 699.3, 48.1, 701.7, 49.2, 706.6, 47.7, 711.5, 46.2, 724.0, 40.8, 736.5, 35.3, 763.3, 24.5, 790.2, 13.6, 790.8, 12.2, 791.3, 10.7, 789.1, 8.8, 786.8, 7.0, 742.6, 7.0, 698.3, 7.0, 697.7, 7.7};
        vector<float> m_underLayerLock2 = {234.7, 227.6, 207.9, 248.2, 208.2, 250.9, 208.5, 253.5, 211.0, 253.8, 213.5, 254.0, 240.3, 233.4, 267.1, 212.8, 266.8, 210.1, 266.5, 207.5, 264.0, 207.2, 261.5, 207.0, 234.7, 227.6};
        vector<float> m_leftKickerLock = {87.6, 7.2, 86.2, 9.5, 78.9, 28.4, 71.7, 47.3, 72.7, 48.9, 73.7, 50.5, 75.3, 50.8, 76.9, 51.1, 78.4, 48.8, 79.8, 46.5, 87.1, 27.6, 94.3, 8.7, 93.3, 7.1, 92.3, 5.5, 90.7, 5.2, 89.1, 4.9, 87.6, 7.2};
        vector<float> m_rightKickerLock = {70.2, 616.2, 69.0, 617.4, 69.0, 618.5, 69.0, 619.6, 77.0, 641.5, 85.0, 663.5, 86.4, 664.9, 87.8, 666.3, 89.4, 665.7, 91.0, 665.0, 91.6, 663.5, 92.2, 662.0, 84.5, 640.8, 76.8, 619.5, 75.4, 617.2, 74.0, 615.0, 72.7, 615.0, 71.4, 615.0, 70.2, 616.2};
        vector<vector<float>> m_WallShapes = {
            m_leftRailWall, m_underLayerLock1, m_underLayerLock2, m_leftKickerLock, m_rightKickerLock
        };
        vector<float> m_positions = {
            970, 293,
            704, 14,
            208, 207,
            73, 18,
            72, 624
        };
};

#endif