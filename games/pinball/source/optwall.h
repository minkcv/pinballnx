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

        vector<float> m_leftRailWall = {1048.0, 296.1, 1044.5, 299.1, 1040.4, 301.5, 1036.3, 303.9, 1028.6, 306.5, 1021.0, 309.0, 1011.3, 310.5, 1001.5, 312.0, 990.4, 312.0, 979.2, 312.0, 978.0, 313.5, 976.8, 315.0, 977.4, 316.5, 977.9, 318.0, 990.4, 318.0, 1002.8, 318.0, 1014.2, 316.0, 1025.7, 314.1, 1032.3, 311.7, 1039.0, 309.3, 1044.5, 305.9, 1050.1, 302.5, 1052.8, 299.7, 1055.4, 296.9, 1054.4, 295.3, 1053.4, 293.6, 1052.4, 293.4, 1051.5, 293.1, 1048.0, 296.1};
        vector<float> m_underLayerLock1 = {697.7, 7.7, 697.0, 8.3, 697.0, 27.7, 697.0, 47.0, 699.3, 48.1, 701.7, 49.2, 706.6, 47.7, 711.5, 46.2, 724.0, 40.8, 736.5, 35.3, 763.3, 24.5, 790.2, 13.6, 790.8, 12.2, 791.3, 10.7, 789.1, 8.8, 786.8, 7.0, 742.6, 7.0, 698.3, 7.0, 697.7, 7.7};
        vector<float> m_underLayerLock2 = {521.4, 447.7, 519.6, 450.5, 513.6, 460.0, 507.5, 469.5, 504.5, 475.2, 501.5, 480.9, 502.7, 482.1, 503.9, 483.3, 505.2, 482.7, 506.6, 482.2, 512.9, 471.7, 519.3, 461.1, 523.6, 456.9, 527.8, 452.8, 534.2, 451.0, 540.5, 449.3, 540.5, 447.4, 540.5, 445.5, 531.8, 445.2, 523.1, 444.9, 521.4, 447.7};
        vector<float> m_leftKickerLock = {87.6, 7.2, 86.2, 9.5, 78.9, 28.4, 71.7, 47.3, 72.7, 48.9, 73.7, 50.5, 75.3, 50.8, 76.9, 51.1, 78.4, 48.8, 79.8, 46.5, 87.1, 27.6, 94.3, 8.7, 93.3, 7.1, 92.3, 5.5, 90.7, 5.2, 89.1, 4.9, 87.6, 7.2};
        vector<float> m_rightKickerLock = {70.2, 616.2, 69.0, 617.4, 69.0, 618.5, 69.0, 619.6, 77.0, 641.5, 85.0, 663.5, 86.4, 664.9, 87.8, 666.3, 89.4, 665.7, 91.0, 665.0, 91.6, 663.5, 92.2, 662.0, 84.5, 640.8, 76.8, 619.5, 75.4, 617.2, 74.0, 615.0, 72.7, 615.0, 71.4, 615.0, 70.2, 616.2};
        vector<vector<float>> m_WallShapes = {
            m_leftRailWall, m_underLayerLock1, m_underLayerLock2, m_leftKickerLock, m_rightKickerLock
        };
        vector<float> m_positions = {
            977, 293,
            704, 14,
            208, 207,
            73, 18,
            72, 624
        };
};

#endif