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
        vector<float> m_ramp1 = {759.2, 162.2, 758.2, 163.5, 757.0, 168.0, 755.9, 172.5, 753.8, 179.0, 751.8, 185.5, 747.8, 194.2, 743.9, 203.0, 744.2, 206.6, 744.5, 210.3, 747.5, 212.0, 750.5, 213.6, 756.4, 214.8, 762.3, 216.0, 765.0, 216.0, 767.6, 216.0, 770.6, 213.2, 773.7, 210.5, 777.8, 201.5, 781.8, 192.5, 783.4, 186.4, 785.0, 180.2, 785.0, 176.6, 785.0, 173.0, 782.5, 170.9, 781.5, 168.8, 777.5, 166.8, 773.5, 164.7, 771.8, 163.9, 770.0, 163.0, 768.1, 163.0, 766.1, 163.0, 765.5, 162.0, 764.9, 161.0, 762.6, 161.0, 760.2, 161.0, 759.2, 162.2};
        vector<float> m_ramp1Down = {737.6, 154.1, 735.8, 155.2, 733.0, 161.4, 730.3, 167.5, 729.6, 171.5, 728.9, 175.5, 727.3, 180.0, 725.6, 184.5, 724.4, 186.5, 723.2, 188.5, 721.5, 194.2, 719.9, 200.0, 720.4, 201.8, 721.0, 203.6, 724.6, 205.3, 728.1, 207.0, 732.0, 206.0, 735.9, 204.9, 736.9, 201.2, 737.9, 197.5, 738.5, 191.5, 739.2, 185.5, 743.1, 173.9, 747.0, 162.3, 747.0, 160.2, 747.0, 158.1, 744.5, 155.5, 741.9, 153.0, 740.7, 153.0, 739.5, 153.1, 737.6, 154.1};
        vector<float> m_ramp2 = {651.5, 445.1, 651.0, 447.5, 647.0, 470.0, 643.0, 492.5, 643.0, 494.5, 643.0, 496.5, 659.3, 499.3, 675.5, 502.0, 681.6, 502.0, 687.6, 502.0, 698.5, 504.0, 709.4, 506.0, 714.0, 506.0, 718.6, 506.0, 723.0, 503.7, 727.5, 501.5, 729.7, 498.1, 732.0, 494.7, 732.0, 479.6, 732.0, 464.5, 730.1, 460.5, 728.3, 456.5, 726.4, 454.8, 724.4, 453.1, 720.7, 451.5, 717.1, 450.0, 710.4, 450.0, 703.7, 450.0, 697.1, 448.9, 690.5, 447.9, 688.5, 447.0, 686.5, 446.1, 672.5, 445.1, 658.5, 444.0, 655.3, 443.4, 652.1, 442.8, 651.5, 445.1};
        vector<float> m_ramp2Down = {619.1, 439.4, 618.0, 440.7, 613.5, 464.1, 609.0, 487.4, 609.0, 489.7, 609.0, 492.0, 624.6, 493.5, 638.3, 495.1, 639.2, 494.2, 640.0, 493.4, 644.5, 469.9, 649.1, 446.5, 648.8, 444.0, 648.5, 441.5, 641.5, 440.8, 634.5, 440.2, 630.0, 439.1, 625.5, 438.0, 622.9, 438.0, 620.2, 438.0, 619.1, 439.4};
        vector<float> m_hole1 = {237.6, 49.6, 236.0, 51.1, 236.0, 73.0, 236.0, 94.9, 237.6, 96.4, 239.1, 98.0, 240.5, 98.0, 241.9, 98.0, 243.4, 96.4, 245.0, 94.9, 245.0, 73.0, 245.0, 51.1, 243.4, 49.6, 241.9, 48.0, 240.5, 48.0, 239.1, 48.0, 237.6, 49.6};
        vector<float> m_hole2 = {237.2, 578.2, 236.0, 579.4, 236.0, 600.0, 236.0, 620.6, 237.2, 621.8, 238.4, 623.0, 240.5, 623.0, 242.6, 623.0, 243.8, 621.8, 245.0, 620.6, 245.0, 600.0, 245.0, 579.4, 243.8, 578.2, 242.6, 577.0, 240.5, 577.0, 238.4, 577.0, 237.2, 578.2};
        // Access this vector by index of rampID to get the 2 collisions shapes for that ramp
        vector<vector<float>> m_rampShapes = {
            m_launchTubeExitSensor, m_ramp1, m_ramp1Down, m_hole1, m_ramp2, m_ramp2Down, m_hole2
        };
};

#endif