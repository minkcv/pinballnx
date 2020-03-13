#ifndef PTARGET_H_
#define PTARGET_H_

#include <list>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace c2d;
using namespace std;

class PTarget {
    public:
        PTarget(C2DRenderer* renderer, b2World& world, int targetGroupID, int layerID);
        vector<b2Fixture*> getFixtures();
        void update();
        bool isCurrent(size_t targetID);
        bool press(size_t targetID); // Returns true if the last target in the progression was pressed.
        void reset();
    private:
        int m_layerID;
        vector<b2Fixture*> m_fixtures;
        vector<C2DTexture*> m_texturesEnabled;
        vector<C2DTexture*> m_texturesDisabled;
        size_t m_currentTarget = 0;
        int m_flashTimer = 0;
        int m_flashFrames = 2048 / g_displayFrameRate;
        int m_frame = 0;

        vector<float> m_rightRamp = {792.0, 588.4, 784.5, 591.6, 770.3, 597.5, 756.0, 603.4, 755.5, 605.0, 755.0, 606.7, 755.5, 608.3, 756.1, 609.8, 766.6, 616.9, 777.1, 624.0, 778.3, 624.0, 779.5, 624.0, 800.3, 616.9, 821.2, 609.7, 822.6, 608.3, 824.0, 606.9, 824.0, 605.2, 824.0, 603.6, 819.3, 599.2, 814.5, 594.7, 808.7, 589.9, 802.9, 585.0, 801.2, 585.1, 799.5, 585.1, 792.0, 588.4};
        vector<float> m_leftRamp = {996.6, 66.5, 995.1, 68.1, 990.5, 82.4, 986.0, 96.8, 986.0, 97.8, 986.0, 98.9, 987.6, 100.4, 989.1, 102.0, 1004.7, 102.0, 1020.2, 102.0, 1023.7, 98.2, 1027.2, 94.5, 1029.8, 90.7, 1032.3, 87.0, 1031.4, 85.0, 1030.5, 83.0, 1015.6, 74.0, 1000.7, 65.0, 999.4, 65.0, 998.1, 65.0, 996.6, 66.5};
        vector<float> m_topRightRamp = {1029.9, 578.0, 1028.3, 578.9, 1024.5, 584.4, 1020.8, 589.8, 1021.4, 591.7, 1022.0, 593.5, 1029.2, 599.6, 1036.5, 605.6, 1039.2, 607.4, 1041.9, 609.2, 1043.8, 608.5, 1045.8, 607.9, 1050.4, 603.0, 1055.0, 598.1, 1055.0, 596.4, 1055.0, 594.8, 1051.9, 591.9, 1048.7, 588.9, 1041.3, 583.0, 1033.9, 577.0, 1032.7, 577.0, 1031.5, 577.1, 1029.9, 578.0};

        vector<vector<float>> m_rampGroup = {
            m_rightRamp, m_leftRamp, m_topRightRamp
        };

        vector<vector<vector<float>>> m_targetGroups = {
            m_rampGroup
        };

        vector<vector<float>> m_positions = {
            {
                723, 545,
                768, 111,
                1020, 581
            }
        };
};

#endif