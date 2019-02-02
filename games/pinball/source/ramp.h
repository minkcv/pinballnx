#ifndef RAMP_H_
#define RAMP_H_

#include<vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

// The ramp class has box2d bodies but it is only for detection purposes.
// The bodies in here are box2d sensors and don't cause any forces. 
// Their collision detection is handled in the Table class in the overriden
// BeginContact and EndContact methods from the b2ContactListener that Table extends.
class Ramp {
    public:
        // C2DRenderer is only for debug graphics, can be removed if desired.
        // b2World is necessary for adding the sensors.
        // rampID specifies the 2 collision shapes to load.
        // layer1ID and layer2ID specify the layers that the ramp transitions between.
        // The layer IDs are assigned to the first and second collision shapes. 
        Ramp(C2DRenderer* renderer, b2World& world, int rampID, int layer1ID, int layer2ID);
        b2Fixture* getFixture1();
        b2Fixture* getFixture2();
        int getLayer1ID();
        int getLayer2ID();
    private:
        b2Fixture* m_fixture1;
        b2Fixture* m_fixture2;
        int m_layer1ID;
        int m_layer2ID;
        vector<float> m_shape1 = {766.5, 299.4, 762.5, 301.7, 757.5, 302.9, 752.5, 304.1, 751.1, 304.9, 749.8, 305.7, 751.3, 313.6, 752.9, 321.5, 754.5, 331.8, 756.1, 342.1, 758.0, 347.3, 759.8, 352.5, 762.4, 358.0, 764.9, 363.5, 765.8, 364.8, 766.7, 366.1, 770.6, 363.5, 774.5, 360.8, 781.6, 357.5, 788.6, 354.3, 793.9, 352.5, 799.1, 350.8, 799.7, 349.4, 800.2, 348.0, 795.2, 339.2, 790.2, 330.5, 786.1, 322.7, 782.0, 314.9, 782.0, 313.5, 782.0, 312.1, 779.5, 307.4, 777.0, 302.7, 777.0, 300.9, 777.0, 299.1, 775.1, 298.0, 773.1, 297.0, 771.8, 297.0, 770.5, 297.0, 766.5, 299.4};
        vector<float> m_shape2 = {796.5, 289.0, 794.5, 289.9, 791.8, 290.4, 789.1, 291.0, 787.6, 292.6, 786.0, 294.1, 786.0, 297.1, 786.0, 300.1, 789.8, 306.8, 793.7, 313.6, 796.5, 321.1, 799.3, 328.5, 802.3, 333.5, 805.3, 338.5, 808.3, 342.3, 811.3, 346.1, 813.9, 345.5, 816.5, 344.9, 824.3, 341.8, 832.0, 338.6, 832.0, 334.3, 832.0, 330.0, 829.5, 326.2, 827.1, 322.5, 824.3, 318.5, 821.5, 314.5, 819.5, 310.0, 817.6, 305.5, 814.6, 301.0, 811.6, 296.5, 807.7, 292.2, 803.7, 288.0, 801.1, 288.1, 798.5, 288.1, 796.5, 289.0};
        vector<vector<float>> m_ramp1 = {m_shape1, m_shape2};

        // Access this vector by index of rampID to get the 2 collisions shapes for that ramp
        vector<vector<vector<float>>> m_rampShapes = {
            m_ramp1
        };
};

#endif