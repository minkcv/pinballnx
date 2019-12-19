#ifndef GTARGET_H_
#define GTARGET_H_

#include <list>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace c2d;
using namespace std;

class GTarget {
    public:
        GTarget(C2DRenderer* renderer, b2World& world, int targetGroupID, int layerID, bool sameSprites = false);
        vector<b2Fixture*> getFixtures();
        void update();
        bool press(size_t targetID); // Returns true if all targets are pressed
        void reset();
    private:
        int m_layerID;
        vector<b2Fixture*> m_fixtures;
        vector<bool> m_isPressed;
        vector<C2DTexture*> m_texturesEnabled;
        vector<C2DTexture*> m_texturesDisabled;
        int m_hitFrames = 1920 / g_displayFrameRate;
        int m_frameCurrent = m_hitFrames + 1;
        vector<float> m_rightTarget0 = {528.6, 567.3, 516.7, 572.5, 515.7, 574.2, 514.6, 575.8, 515.9, 577.4, 517.2, 579.0, 518.5, 579.0, 519.8, 579.0, 531.6, 574.0, 543.4, 569.0, 544.9, 567.5, 546.5, 566.0, 545.4, 564.2, 544.3, 562.5, 542.4, 562.3, 540.5, 562.1, 528.6, 567.3};
        vector<float> m_rightTarget1 = {563.6, 553.5, 552.6, 557.9, 551.2, 559.4, 549.7, 560.8, 550.3, 562.4, 551.0, 564.0, 552.4, 564.6, 553.9, 565.2, 565.9, 560.5, 577.8, 555.9, 579.1, 554.4, 580.4, 552.8, 579.3, 551.2, 578.3, 549.5, 576.4, 549.3, 574.5, 549.2, 563.6, 553.5};
        vector<float> m_rightTarget2 = {595.3, 540.9, 586.0, 544.7, 584.5, 546.0, 583.0, 547.2, 583.0, 548.5, 583.0, 549.8, 584.5, 551.0, 586.0, 552.2, 596.1, 548.5, 606.2, 544.7, 608.3, 542.9, 610.5, 541.1, 609.4, 539.3, 608.3, 537.5, 606.4, 537.3, 604.5, 537.1, 595.3, 540.9};
        vector<float> m_rightReturn0 = {207.9, 640.6, 206.6, 642.2, 207.7, 643.8, 208.7, 645.5, 227.0, 645.5, 245.3, 645.5, 246.3, 643.8, 247.4, 642.2, 246.1, 640.6, 244.8, 639.0, 227.0, 639.0, 209.2, 639.0, 207.9, 640.6};
        vector<float> m_rightReturn1 = {207.9, 605.6, 206.6, 607.2, 207.7, 608.8, 208.7, 610.5, 227.0, 610.5, 245.3, 610.5, 246.3, 608.8, 247.4, 607.2, 246.1, 605.6, 244.8, 604.0, 227.0, 604.0, 209.2, 604.0, 207.9, 605.6};
        vector<float> m_rightReturn2 = {207.9, 571.6, 206.6, 573.2, 207.7, 574.8, 208.7, 576.5, 227.0, 576.5, 245.3, 576.5, 246.3, 574.8, 247.4, 573.2, 246.1, 571.6, 244.8, 570.0, 227.0, 570.0, 209.2, 570.0, 207.9, 571.6};
        vector<float> m_leftReturn0 = {207.9, 97.6, 206.6, 99.2, 207.7, 100.8, 208.7, 102.5, 227.0, 102.5, 245.3, 102.5, 246.3, 100.8, 247.4, 99.2, 246.1, 97.6, 244.8, 96.0, 227.0, 96.0, 209.2, 96.0, 207.9, 97.6};
        vector<float> m_leftReturn1 = {207.9, 62.6, 206.6, 64.2, 207.7, 65.8, 208.7, 67.5, 227.0, 67.5, 245.3, 67.5, 246.3, 65.8, 247.4, 64.2, 246.1, 62.6, 244.8, 61.0, 227.0, 61.0, 209.2, 61.0, 207.9, 62.6};
        vector<float> m_leftReturn2 = {207.9, 28.6, 206.6, 30.2, 207.7, 31.8, 208.7, 33.5, 227.0, 33.5, 245.3, 33.5, 246.3, 31.8, 247.4, 30.2, 246.1, 28.6, 244.8, 27.0, 227.0, 27.0, 209.2, 27.0, 207.9, 28.6};
        vector<vector<float>> m_rightGroup = {
            m_rightTarget0, m_rightTarget1, m_rightTarget2
        };
        vector<vector<float>> m_rightReturn = {
            m_rightReturn0, m_rightReturn1, m_rightReturn2
        };
        vector<vector<float>> m_leftReturn = {
            m_leftReturn0, m_leftReturn1, m_leftReturn2
        };
        vector<vector<vector<float>>> m_targetGroups = {
            m_rightGroup, m_rightReturn, m_leftReturn
        };
        vector<vector<float>> m_positions = {
            {
                515, 553,
                550, 540,
                583, 529
            },
            {
                207, 638,
                207, 603,
                207, 569
            },
            {
                207, 95,
                207, 60,
                207, 26
            }
        };
};

#endif