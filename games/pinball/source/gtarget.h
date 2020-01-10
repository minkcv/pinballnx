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
        GTarget(C2DRenderer* renderer, b2World& world, int targetGroupID, int layerID, bool sameSprites = false, bool collide = false);
        vector<b2Fixture*> getFixtures();
        void update();
        bool press(size_t targetID); // Returns true if all targets are pressed
        bool isPressed(size_t targetID);
        void reset();
    private:
        int m_layerID;
        bool m_collide;
        vector<b2Fixture*> m_fixtures;
        vector<bool> m_isPressed;
        vector<int> m_dropTimers;
        int m_dropTime = 10;
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
        vector<float> m_middleTarget0 = {732.4, 296.5, 731.8, 298.0, 734.0, 307.3, 736.3, 316.5, 737.2, 318.2, 738.1, 320.0, 739.5, 320.0, 740.9, 320.0, 741.5, 319.1, 742.0, 318.1, 740.1, 310.8, 738.1, 303.5, 737.0, 299.2, 735.9, 295.0, 734.4, 295.0, 732.9, 295.0, 732.4, 296.5};
        vector<float> m_middleTarget1 = {724.4, 268.4, 723.9, 269.7, 726.0, 278.1, 728.1, 286.5, 729.1, 289.7, 730.2, 293.0, 731.6, 293.0, 733.1, 293.0, 733.6, 291.5, 734.2, 289.9, 732.0, 280.2, 729.8, 270.5, 728.8, 268.7, 727.9, 267.0, 726.4, 267.0, 724.9, 267.0, 724.4, 268.4};
        vector<float> m_middleTarget2 = {716.4, 240.4, 715.8, 242.0, 718.5, 253.1, 721.3, 264.2, 722.7, 264.7, 724.1, 265.3, 725.3, 264.1, 726.4, 263.0, 723.5, 251.2, 720.5, 239.5, 718.7, 239.2, 717.0, 238.9, 716.4, 240.4};
        vector<float> m_launchTarget0 = {517.5, 678.2, 516.9, 679.6, 517.2, 690.1, 517.5, 700.5, 519.5, 700.5, 521.5, 700.5, 521.5, 689.0, 521.5, 677.5, 519.7, 677.2, 518.0, 676.9, 517.5, 678.2};
        vector<float> m_launchTarget1 = {598.5, 678.2, 597.9, 679.6, 598.2, 690.1, 598.5, 700.5, 600.5, 700.5, 602.5, 700.5, 602.5, 689.0, 602.5, 677.5, 600.7, 677.2, 599.0, 676.9, 598.5, 678.2};
        vector<float> m_launchTarget2 = {679.5, 678.2, 678.9, 679.6, 679.2, 690.1, 679.5, 700.5, 681.5, 700.5, 683.5, 700.5, 683.5, 689.0, 683.5, 677.5, 681.7, 677.2, 680.0, 676.9, 679.5, 678.2};
        vector<float> m_launchTarget3 = {760.5, 678.2, 759.9, 679.6, 760.2, 690.1, 760.5, 700.5, 762.5, 700.5, 764.5, 700.5, 764.5, 689.0, 764.5, 677.5, 762.7, 677.2, 761.0, 676.9, 760.5, 678.2};
        vector<float> m_launchTarget4 = {841.5, 678.2, 840.9, 679.6, 841.2, 690.1, 841.5, 700.5, 843.5, 700.5, 845.5, 700.5, 845.5, 689.0, 845.5, 677.5, 843.7, 677.2, 842.0, 676.9, 841.5, 678.2};
        vector<float> m_launchTarget5 = {922.5, 678.2, 921.9, 679.6, 922.2, 690.1, 922.5, 700.5, 924.5, 700.5, 926.5, 700.5, 926.5, 689.0, 926.5, 677.5, 924.7, 677.2, 923.0, 676.9, 922.5, 678.2};

        vector<vector<float>> m_rightGroup = {
            m_rightTarget0, m_rightTarget1, m_rightTarget2
        };
        vector<vector<float>> m_rightReturn = {
            m_rightReturn0, m_rightReturn1, m_rightReturn2
        };
        vector<vector<float>> m_leftReturn = {
            m_leftReturn0, m_leftReturn1, m_leftReturn2
        };
        vector<vector<float>> m_middleTargets = {
            m_middleTarget0, m_middleTarget1, m_middleTarget2
        };
        vector<vector<float>> m_launchTargets = {
            m_launchTarget0, m_launchTarget1, m_launchTarget2, m_launchTarget3, m_launchTarget4, m_launchTarget5
        };
        vector<vector<vector<float>>> m_targetGroups = {
            m_rightGroup, m_rightReturn, m_leftReturn, m_middleTargets, m_launchTargets
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
            },
            {
                722, 295,
                714, 267,
                706, 239
            },
            {
                517, 677,
                598, 677,
                679, 677,
                760, 677,
                841, 677,
                922, 677
            }
        };
};

#endif