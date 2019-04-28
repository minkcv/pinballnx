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
    private:
        b2Fixture* m_fixture;
        int m_layerID;
        C2DTexture* m_textureEnabled;
        C2DTexture* m_textureDisabled;

        vector<float> m_leftRailWall = {1037.5, 303.3, 1032.5, 305.7, 1027.5, 306.9, 1022.5, 308.1, 1017.0, 310.1, 1011.5, 312.2, 992.0, 312.8, 972.5, 313.5, 972.5, 315.5, 972.5, 317.5, 987.0, 317.8, 1001.5, 318.1, 1009.8, 317.1, 1018.1, 316.1, 1021.3, 314.6, 1024.5, 313.2, 1030.0, 312.0, 1035.5, 310.7, 1038.0, 309.3, 1040.5, 307.9, 1043.5, 306.1, 1046.5, 304.3, 1046.5, 302.9, 1046.5, 301.5, 1044.5, 301.2, 1042.5, 301.0, 1037.5, 303.3};
        vector<vector<float>> m_WallShapes = {
            m_leftRailWall
        };
};

#endif