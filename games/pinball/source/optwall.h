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

        vector<float> m_leftRailWall = {1038.0, 303.1, 1033.5, 305.2, 1026.5, 307.1, 1019.5, 309.0, 999.2, 309.0, 978.9, 309.0, 975.4, 310.5, 971.9, 312.0, 972.2, 314.7, 972.5, 317.5, 987.0, 317.8, 1001.5, 318.1, 1009.8, 317.1, 1018.1, 316.1, 1021.3, 314.6, 1024.5, 313.2, 1030.0, 312.0, 1035.5, 310.7, 1038.0, 309.3, 1040.5, 307.9, 1043.5, 306.1, 1046.5, 304.3, 1046.5, 302.9, 1046.5, 301.5, 1044.5, 301.3, 1042.5, 301.0, 1038.0, 303.1};
        vector<float> m_underLayerLock1 = {782.5, 9.0, 779.5, 9.7, 752.5, 21.7, 725.5, 33.7, 715.0, 38.1, 704.5, 42.5, 704.5, 44.5, 704.5, 46.5, 706.8, 46.8, 709.1, 47.2, 725.3, 40.2, 741.5, 33.3, 765.8, 23.5, 790.2, 13.7, 790.7, 12.3, 791.2, 11.0, 790.0, 9.5, 788.8, 8.0, 787.1, 8.1, 785.5, 8.2, 782.5, 9.0};
        vector<float> m_underLayerLock2 = {234.7, 227.6, 207.9, 248.2, 208.2, 250.9, 208.5, 253.5, 211.0, 253.8, 213.5, 254.0, 240.3, 233.4, 267.1, 212.8, 266.8, 210.1, 266.5, 207.5, 264.0, 207.2, 261.5, 207.0, 234.7, 227.6};
        vector<float> m_leftKickerLock = {87.6, 7.2, 86.2, 9.5, 78.9, 28.4, 71.7, 47.3, 72.7, 48.9, 73.7, 50.5, 75.3, 50.8, 76.9, 51.1, 78.4, 48.8, 79.8, 46.5, 87.1, 27.6, 94.3, 8.7, 93.3, 7.1, 92.3, 5.5, 90.7, 5.2, 89.1, 4.9, 87.6, 7.2};
        vector<float> m_rightKickerLock = {70.2, 616.2, 69.0, 617.4, 69.0, 618.5, 69.0, 619.6, 77.0, 641.5, 85.0, 663.5, 86.4, 664.9, 87.8, 666.3, 89.4, 665.7, 91.0, 665.0, 91.6, 663.5, 92.2, 662.0, 84.5, 640.8, 76.8, 619.5, 75.4, 617.2, 74.0, 615.0, 72.7, 615.0, 71.4, 615.0, 70.2, 616.2};
        vector<vector<float>> m_WallShapes = {
            m_leftRailWall, m_underLayerLock1, m_underLayerLock2, m_leftKickerLock, m_rightKickerLock
        };
        vector<float> m_positions = {
            972, 301,
            704, 14,
            208, 207
        };
};

#endif