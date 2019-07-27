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
        vector<float> m_underLayerLock2 = {460.4, 299.4, 459.8, 300.9, 460.2, 302.7, 460.5, 304.5, 482.0, 304.5, 503.5, 304.5, 503.5, 301.5, 503.5, 298.5, 482.2, 298.2, 461.0, 298.0, 460.4, 299.4};
        vector<vector<float>> m_WallShapes = {
            m_leftRailWall, m_underLayerLock1, m_underLayerLock2
        };
};

#endif