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
        vector<float> m_shape1 = {766.5, 299.4, 762.5, 301.7, 757.5, 302.9, 752.5, 304.1, 751.1, 304.9, 749.8, 305.7, 751.3, 313.6, 752.9, 321.5, 754.5, 331.8, 756.1, 342.1, 758.0, 347.3, 759.8, 352.5, 762.4, 358.0, 764.9, 363.5, 765.8, 364.8, 766.7, 366.1, 770.6, 363.5, 774.5, 360.8, 781.6, 357.5, 788.6, 354.3, 793.9, 352.5, 799.1, 350.8, 799.7, 349.4, 800.2, 348.0, 795.2, 339.2, 790.2, 330.5, 786.1, 322.7, 782.0, 314.9, 782.0, 313.5, 782.0, 312.1, 779.5, 307.4, 777.0, 302.7, 777.0, 300.9, 777.0, 299.1, 775.1, 298.0, 773.1, 297.0, 771.8, 297.0, 770.5, 297.0, 766.5, 299.4};
        vector<float> m_shape2 = {796.5, 289.0, 794.5, 289.9, 791.8, 290.4, 789.1, 291.0, 787.6, 292.6, 786.0, 294.1, 786.0, 297.1, 786.0, 300.1, 789.8, 306.8, 793.7, 313.6, 796.5, 321.1, 799.3, 328.5, 802.3, 333.5, 805.3, 338.5, 808.3, 342.3, 811.3, 346.1, 813.9, 345.5, 816.5, 344.9, 824.3, 341.8, 832.0, 338.6, 832.0, 334.3, 832.0, 330.0, 829.5, 326.2, 827.1, 322.5, 824.3, 318.5, 821.5, 314.5, 819.5, 310.0, 817.6, 305.5, 814.6, 301.0, 811.6, 296.5, 807.7, 292.2, 803.7, 288.0, 801.1, 288.1, 798.5, 288.1, 796.5, 289.0};
        vector<float> m_shape3 = {635.0, 59.1, 632.5, 60.1, 630.1, 62.3, 627.8, 64.5, 626.9, 66.9, 625.9, 69.3, 627.1, 72.9, 628.3, 76.5, 633.4, 82.5, 638.6, 88.5, 641.5, 93.0, 644.5, 97.5, 645.5, 99.1, 646.5, 100.7, 650.2, 106.1, 653.8, 111.5, 659.5, 117.5, 665.2, 123.5, 667.2, 127.2, 669.1, 130.9, 670.3, 131.9, 671.5, 132.8, 674.0, 133.4, 676.5, 134.1, 680.0, 132.0, 683.5, 130.0, 686.7, 128.5, 689.9, 127.0, 692.4, 123.7, 695.0, 120.3, 695.6, 117.4, 696.1, 114.5, 695.2, 111.9, 694.2, 109.3, 688.8, 102.9, 683.5, 96.5, 682.3, 94.5, 681.1, 92.5, 680.2, 90.5, 679.2, 88.5, 672.4, 80.5, 665.5, 72.5, 660.8, 66.9, 656.2, 61.4, 652.3, 60.2, 648.5, 59.1, 643.0, 58.5, 637.5, 58.0, 635.0, 59.1};
        vector<float> m_shape4 = {698.5, 46.4, 693.5, 48.7, 690.9, 52.1, 688.3, 55.5, 687.6, 57.6, 686.9, 59.7, 688.0, 62.1, 689.0, 64.5, 690.2, 66.5, 691.5, 68.5, 694.3, 71.8, 697.0, 75.1, 697.0, 76.1, 697.0, 77.2, 700.5, 81.3, 704.0, 85.4, 704.0, 86.4, 704.0, 87.3, 705.4, 88.9, 706.7, 90.5, 709.4, 98.6, 712.1, 106.7, 714.9, 109.4, 717.8, 112.2, 721.8, 112.7, 725.8, 113.2, 729.6, 112.0, 733.5, 110.8, 735.7, 108.7, 737.9, 106.7, 739.6, 101.8, 741.2, 97.0, 739.5, 86.2, 737.9, 75.5, 736.8, 72.0, 735.8, 68.5, 734.0, 66.5, 732.3, 64.5, 729.6, 58.9, 727.0, 53.2, 725.7, 52.2, 724.5, 51.2, 722.0, 50.5, 719.5, 49.8, 718.0, 48.5, 716.5, 47.3, 711.6, 45.6, 706.6, 44.0, 705.1, 44.0, 703.5, 44.0, 698.5, 46.4};

        // Access this vector by index of rampID to get the 2 collisions shapes for that ramp
        vector<vector<float>> m_rampShapes = {
            m_shape1, m_shape2, m_shape3, m_shape4
        };
};

#endif