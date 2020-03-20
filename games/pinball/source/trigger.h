#ifndef TRIGGER_H_
#define TRIGGER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include "optwall.h"

class Trigger {
    public:
        Trigger(C2DRenderer* renderer, b2World& world, int triggerID, int layerID, int behavior, int delay, OptWall* wallToChange = nullptr, OptWall* wall2 = nullptr, OptWall* wall3 = nullptr, OptWall* wall4 = nullptr);
        b2Fixture* getFixture();
        void update();
        void press();
        bool isPressed();
        void reset();
    private:
        int m_layerID;
        int m_delay;
        int m_timer;
        b2Fixture* m_fixture;
        bool m_isPressed;
        vector<OptWall*> m_wallsToChange;
        C2DTexture* m_textureEnabled;
        C2DTexture* m_textureDisabled;
        int m_hitFrames = 2100 / g_displayFrameRate;
        int m_hitFrameCurrent = m_hitFrames;
        int m_behavior; // 0 disable, 1 enable, 2 toggle

        vector<float> m_leftInletTrigger = {615.3, 11.0, 613.0, 11.9, 613.0, 32.4, 613.0, 52.9, 615.0, 54.0, 617.1, 55.1, 621.3, 54.8, 625.5, 54.5, 625.5, 32.5, 625.5, 10.5, 621.5, 10.3, 617.5, 10.1, 615.3, 11.0};
        vector<float> m_topRightTrigger = {1004.7, 533.7, 1004.0, 534.3, 1004.0, 536.1, 1004.0, 537.8, 1017.1, 550.2, 1030.2, 562.5, 1032.3, 562.5, 1034.5, 562.5, 1034.8, 560.1, 1035.2, 557.7, 1022.9, 545.4, 1010.5, 533.0, 1007.9, 533.0, 1005.3, 533.0, 1004.7, 533.7};
        vector<float> m_topLeftTrigger = {1038.1, 97.2, 1031.0, 105.5, 1031.2, 106.9, 1031.5, 108.3, 1033.3, 109.4, 1035.2, 110.5, 1039.2, 106.0, 1043.2, 101.5, 1046.8, 97.2, 1050.4, 92.8, 1049.3, 91.2, 1048.3, 89.5, 1046.8, 89.2, 1045.2, 88.9, 1038.1, 97.2};
        vector<float> m_lowerRightTrigger = {816.0, 497.5, 814.8, 499.0, 813.0, 499.0, 811.3, 499.0, 808.1, 500.1, 805.0, 501.2, 804.4, 503.6, 803.8, 506.0, 802.0, 508.8, 802.0, 511.6, 800.9, 512.7, 799.7, 513.9, 800.3, 515.4, 800.9, 517.0, 802.2, 517.0, 803.5, 517.0, 812.4, 508.1, 821.3, 499.2, 820.7, 497.6, 820.1, 496.0, 818.7, 496.0, 817.2, 496.0, 816.0, 497.5};
        vector<vector<float>> m_triggerShapes = {
            m_leftInletTrigger, m_topRightTrigger, m_topLeftTrigger, m_lowerRightTrigger
        };
        vector<float> m_positions = {
            616, 17,
            1006, 532,
            1031, 88,
            795, 497
        };
};
#endif