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
        GTarget(C2DRenderer* renderer, b2World& world, int targetGroupID, int layerID);
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
        vector<vector<float>> m_rightGroup = {
            m_rightTarget0, m_rightTarget1, m_rightTarget2
        };
        vector<vector<vector<float>>> m_targetGroups = {
            m_rightGroup
        };
        vector<vector<float>> m_positions = {
            {
                515, 553,
                550, 540,
                583, 529
            }
        };
};

#endif