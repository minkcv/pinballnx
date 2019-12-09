#ifndef TRIGGER_H_
#define TRIGGER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include "optwall.h"

class Trigger {
    public:
        Trigger(C2DRenderer* renderer, b2World& world, int triggerID, int layerID, int behavior, OptWall* wallToChange, OptWall* wall2 = nullptr, OptWall* wall3 = nullptr, OptWall* wall4 = nullptr);
        b2Fixture* getFixture();
        void update();
        void press();
        void reset();
    private:
        int m_layerID;
        b2Fixture* m_fixture;
        bool m_isPressed;
        vector<OptWall*> m_wallsToChange;
        C2DTexture* m_textureEnabled;
        C2DTexture* m_textureDisabled;
        int m_hitFrames = 1920 / g_displayFrameRate;
        int m_hitFrameCurrent = m_hitFrames;
        int m_behavior; // 0 disable, 1 enable, 2 toggle

        vector<float> m_leftInletTrigger = {615.3, 11.0, 613.0, 11.9, 613.0, 32.4, 613.0, 52.9, 615.0, 54.0, 617.1, 55.1, 621.3, 54.8, 625.5, 54.5, 625.5, 32.5, 625.5, 10.5, 621.5, 10.3, 617.5, 10.1, 615.3, 11.0};
        vector<float> m_topRightTrigger = {1004.7, 533.7, 1004.0, 534.3, 1004.0, 536.1, 1004.0, 537.8, 1017.1, 550.2, 1030.2, 562.5, 1032.3, 562.5, 1034.5, 562.5, 1034.8, 560.1, 1035.2, 557.7, 1022.9, 545.4, 1010.5, 533.0, 1007.9, 533.0, 1005.3, 533.0, 1004.7, 533.7};
        vector<float> m_topLeftTrigger = {1038.1, 97.2, 1031.0, 105.5, 1031.2, 106.9, 1031.5, 108.3, 1033.3, 109.4, 1035.2, 110.5, 1039.2, 106.0, 1043.2, 101.5, 1046.8, 97.2, 1050.4, 92.8, 1049.3, 91.2, 1048.3, 89.5, 1046.8, 89.2, 1045.2, 88.9, 1038.1, 97.2};
        vector<vector<float>> m_triggerShapes = {
            m_leftInletTrigger, m_topRightTrigger, m_topLeftTrigger
        };
        vector<float> m_positions = {
            616, 17,
            1006, 532,
            1031, 88
        };
};
#endif