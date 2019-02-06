#ifndef RAMP_H_
#define RAMP_H_

#include<vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

// The ramp class has a box2d body and fixture but they are only for detection purposes.
// The fixture in here is a  box2d sensors and doesn't cause any forces. 
// The collision detection is handled in the Table class in the overriden
// BeginContact and EndContact methods from the b2ContactListener that Table extends.
// Creating a bidirectional ramp actually takes 2 Ramp objects, one for up and one for down
// because this class only transitions the pinball TO another layer. 
// This means you can also use this class to make holes that the ball can fall through but can't go up.
class Ramp {
    public:
        // C2DRenderer is only for debug graphics, can be removed if desired.
        // b2World is necessary for adding the sensor.
        // rampID specifies the collision shape to load.
        // layerID specifies the layer that the ramp transitions to.
        Ramp(C2DRenderer* renderer, b2World& world, int rampID, int layerID);
        b2Fixture* getFixture();
        int getLayerID();
    private:
        b2Fixture* m_fixture;
        int m_layerID;
        vector<float> m_launchTubeExitSensor = {1080.3, 555.2, 1078.3, 557.5, 1074.7, 563.0, 1071.1, 568.5, 1064.1, 575.6, 1057.0, 582.7, 1057.0, 585.2, 1057.0, 587.6, 1058.2, 588.8, 1059.4, 590.0, 1061.7, 590.0, 1064.0, 590.0, 1071.4, 582.6, 1078.8, 575.1, 1083.0, 569.0, 1087.1, 562.9, 1091.8, 565.6, 1096.5, 568.3, 1101.0, 570.8, 1105.5, 573.3, 1107.5, 574.4, 1109.5, 575.6, 1114.0, 578.4, 1118.5, 581.2, 1121.2, 583.1, 1123.9, 585.0, 1125.8, 585.0, 1127.6, 585.0, 1128.8, 583.8, 1130.0, 582.6, 1130.0, 580.4, 1130.0, 578.2, 1125.6, 574.6, 1121.1, 571.0, 1110.8, 564.8, 1100.5, 558.7, 1095.2, 555.9, 1090.0, 553.0, 1086.2, 553.0, 1082.3, 553.0, 1080.3, 555.2};
        vector<float> m_ramp1 = {767.6, 169.2, 766.0, 171.4, 766.0, 173.1, 766.0, 174.7, 762.1, 185.6, 758.2, 196.5, 756.9, 204.2, 755.6, 211.9, 756.9, 213.4, 758.2, 215.0, 761.5, 215.0, 764.7, 215.0, 766.2, 213.2, 767.8, 211.5, 768.5, 207.0, 769.3, 202.5, 774.1, 188.7, 779.0, 174.8, 779.0, 172.1, 779.0, 169.4, 777.8, 168.2, 776.6, 167.0, 772.9, 167.0, 769.1, 167.0, 767.6, 169.2};
        vector<float> m_ramp1Down = {753.6, 159.1, 751.8, 160.2, 749.0, 166.4, 746.3, 172.5, 745.6, 176.5, 744.9, 180.5, 743.3, 185.0, 741.6, 189.5, 740.4, 191.5, 739.2, 193.5, 737.5, 199.2, 735.9, 205.0, 736.4, 206.8, 737.0, 208.6, 740.6, 210.3, 744.1, 212.0, 748.0, 211.0, 751.9, 209.9, 752.9, 206.2, 753.9, 202.5, 754.5, 196.5, 755.2, 190.5, 759.1, 178.9, 763.0, 167.3, 763.0, 165.2, 763.0, 163.1, 760.5, 160.5, 757.9, 158.0, 756.7, 158.0, 755.5, 158.1, 753.6, 159.1};
        vector<float> m_hole1 = {791.6, 8.6, 790.0, 10.1, 790.0, 32.0, 790.0, 53.9, 791.6, 55.4, 793.1, 57.0, 794.5, 57.0, 795.9, 57.0, 797.4, 55.4, 799.0, 53.9, 799.0, 32.0, 799.0, 10.1, 797.4, 8.6, 795.9, 7.0, 794.5, 7.0, 793.1, 7.0, 791.6, 8.6 };
        // Access this vector by index of rampID to get the 2 collisions shapes for that ramp
        vector<vector<float>> m_rampShapes = {
            m_launchTubeExitSensor, m_ramp1, m_ramp1Down, m_hole1
        };
};

#endif