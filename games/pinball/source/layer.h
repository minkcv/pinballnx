#ifndef LAYER_H_
#define LAYER_H_

#include <list>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

// The pinball table is a series of layers.
// Each layer has it's own set of collision shapes and graphics, 
// Each layer's collision shapes have a category filter for box2d collisions.
// This allows the ball to pass from one layer to another by having the table 
// change the balls collision mask.
class Layer {
    public:
        Layer(C2DRenderer* renderer, b2World& world, int layerID);
        int getLayerID();
    private:
        void loadShape(vector<float> points, C2DRenderer* renderer, b2World& world, int layerID);
        int m_layerID;

        // Underlayer
        vector<float> m_underOuter = {698.5, 7.0, 697.9, 8.0, 689.2, 12.4, 680.5, 16.7, 649.0, 33.2, 617.5, 49.7, 607.5, 54.8, 597.5, 59.8, 564.8, 73.8, 532.1, 87.9, 525.8, 91.1, 519.5, 94.2, 517.8, 95.7, 516.2, 97.1, 503.9, 124.1, 491.7, 151.0, 454.4, 151.0, 417.1, 151.0, 416.6, 151.9, 416.0, 152.8, 410.8, 154.1, 405.5, 155.3, 399.0, 157.5, 392.5, 159.8, 390.8, 160.5, 389.0, 161.2, 389.0, 143.3, 389.0, 125.4, 387.8, 124.2, 386.6, 123.0, 359.5, 123.0, 332.4, 123.0, 331.2, 124.2, 330.0, 125.4, 330.0, 153.6, 330.0, 181.8, 326.8, 183.3, 323.5, 184.8, 293.5, 195.6, 263.5, 206.5, 214.5, 207.0, 165.5, 207.5, 165.5, 230.5, 165.5, 253.5, 185.1, 254.0, 204.7, 254.5, 198.2, 266.0, 191.8, 277.5, 182.9, 294.5, 174.1, 311.5, 170.3, 318.7, 166.5, 326.0, 139.5, 326.2, 112.5, 326.5, 112.5, 351.0, 112.5, 375.5, 138.5, 375.8, 164.5, 376.0, 187.8, 417.4, 211.1, 458.8, 212.9, 460.4, 214.6, 462.0, 234.0, 462.2, 253.4, 462.5, 271.2, 499.9, 288.9, 537.2, 290.1, 538.6, 291.2, 540.0, 310.6, 540.0, 330.0, 540.0, 330.2, 562.7, 330.5, 585.5, 359.5, 585.5, 388.5, 585.5, 388.8, 562.8, 389.0, 540.0, 503.3, 540.0, 617.5, 540.0, 669.3, 488.2, 721.0, 436.5, 721.0, 351.0, 721.0, 265.5, 663.7, 208.2, 606.5, 151.0, 576.8, 151.0, 547.0, 151.0, 546.4, 148.3, 545.7, 145.6, 547.0, 142.6, 548.2, 139.5, 549.7, 135.5, 551.2, 131.5, 554.1, 126.3, 557.0, 121.2, 618.3, 90.0, 679.5, 58.7, 682.0, 57.0, 684.5, 55.3, 689.7, 52.6, 694.9, 50.0, 769.8, 50.0, 844.8, 50.0, 846.1, 48.4, 847.4, 46.8, 846.3, 45.2, 845.3, 43.5, 770.8, 43.2, 696.2, 43.0, 662.9, 59.6, 629.5, 76.3, 590.2, 94.6, 550.8, 112.9, 549.0, 114.5, 547.2, 116.1, 539.5, 134.5, 531.8, 152.9, 532.2, 155.2, 532.5, 157.5, 567.5, 157.8, 602.5, 158.0, 657.3, 212.8, 712.0, 267.5, 712.0, 280.5, 712.0, 293.5, 692.0, 313.5, 672.0, 333.5, 672.0, 352.0, 672.0, 370.5, 692.0, 390.5, 712.0, 410.5, 712.0, 422.5, 712.0, 434.5, 662.7, 483.8, 613.5, 533.0, 497.7, 533.0, 382.0, 533.0, 382.0, 556.0, 382.0, 579.0, 359.5, 579.0, 337.0, 579.0, 337.0, 556.0, 337.0, 533.0, 315.8, 532.8, 294.6, 532.5, 276.9, 495.2, 259.1, 457.8, 257.9, 456.4, 256.8, 455.0, 236.8, 454.8, 216.8, 454.5, 193.7, 413.4, 170.5, 372.3, 169.1, 370.6, 167.8, 369.0, 143.4, 369.0, 119.0, 369.0, 119.0, 351.0, 119.0, 333.0, 145.4, 333.0, 171.8, 333.0, 172.8, 331.7, 173.8, 330.5, 181.4, 315.6, 189.0, 300.8, 202.1, 276.4, 215.2, 252.1, 214.8, 249.8, 214.5, 247.5, 193.3, 247.2, 172.0, 247.0, 172.0, 230.5, 172.0, 214.0, 218.5, 214.0, 265.1, 214.0, 267.8, 212.6, 270.5, 211.3, 303.8, 199.9, 337.0, 188.6, 337.0, 159.3, 337.0, 130.0, 359.5, 130.0, 382.0, 130.0, 382.0, 151.5, 382.0, 173.0, 404.5, 165.5, 426.2, 158.0, 463.0, 158.0, 499.7, 158.0, 512.5, 130.1, 525.2, 102.2, 527.8, 99.7, 530.5, 97.2, 564.8, 81.1, 599.1, 65.0, 640.7, 43.6, 681.5, 22.3, 690.0, 17.9, 698.5, 13.5, 771.9, 13.0, 845.3, 12.5, 846.3, 10.8, 847.4, 9.2, 846.1, 7.6, 844.8, 6.0, 771.9, 6.0, 699.1, 6.0, 698.5, 7.0};
        vector<float> m_under1 = {398.7, 301.7, 398.0, 302.3, 398.0, 352.7, 398.0, 403.1, 399.6, 403.7, 401.2, 404.3, 426.6, 378.9, 452.0, 353.5, 452.0, 352.5, 452.0, 351.5, 426.7, 326.2, 401.5, 301.0, 400.4, 301.0, 399.3, 301.0, 398.7, 301.7};
        vector<vector<float>> m_underLayer = {
            m_underOuter, m_under1
        };

        // Launch tube layer
        vector<float> m_tubeLeft = {0.0, 540.8, 0.0, 675.0, 210.3, 675.0, 420.7, 675.0, 423.0, 672.5, 425.3, 670.0, 418.5, 655.4, 411.6, 640.8, 397.1, 630.4, 382.5, 620.1, 377.5, 620.0, 372.5, 620.0, 355.5, 637.0, 338.5, 654.0, 174.3, 654.0, 10.0, 654.0, 10.0, 641.0, 10.0, 628.0, 42.3, 628.0, 74.7, 628.0, 76.5, 626.0, 78.3, 624.1, 39.5, 515.8, 0.8, 407.5, 3.97459842816e-14, 540.8};
        vector<float> m_tubeLeftUpper = {988.0, 542.3, 977.5, 552.6, 942.0, 584.0, 906.5, 615.4, 897.0, 621.4, 887.5, 627.4, 873.5, 634.6, 859.5, 641.8, 850.5, 645.6, 841.5, 649.3, 830.0, 653.2, 818.5, 657.1, 803.5, 659.1, 788.5, 661.0, 696.5, 661.0, 604.5, 661.0, 588.7, 658.5, 573.0, 656.1, 561.2, 653.4, 549.5, 650.8, 538.2, 647.4, 526.9, 643.9, 519.0, 640.0, 511.1, 636.0, 498.8, 628.0, 486.5, 620.0, 461.3, 620.0, 436.1, 620.0, 435.5, 621.9, 434.9, 623.8, 436.2, 626.6, 437.4, 629.5, 444.0, 641.5, 450.6, 653.5, 454.1, 660.4, 457.5, 667.2, 460.8, 671.1, 464.2, 675.0, 705.3, 674.7, 946.5, 674.5, 958.6, 671.8, 970.6, 669.1, 980.6, 665.6, 990.5, 662.1, 997.5, 659.0, 1004.5, 655.9, 1013.3, 650.8, 1022.1, 645.8, 1030.3, 639.7, 1038.5, 633.6, 1048.9, 623.6, 1059.2, 613.5, 1065.2, 606.2, 1071.2, 598.9, 1067.9, 595.4, 1064.6, 592.0, 1058.3, 598.7, 1053.2, 605.5, 1038.8, 619.5, 1024.5, 633.5, 1013.2, 639.9, 1001.8, 646.3, 992.5, 650.1, 983.1, 653.9, 972.3, 656.9, 961.5, 659.9, 951.2, 660.9, 940.9, 662.0, 928.0, 662.0, 915.0, 662.0, 915.0, 646.0, 915.0, 630.0, 920.3, 630.0, 925.6, 630.0, 935.1, 628.4, 944.5, 626.8, 954.0, 623.8, 963.5, 620.8, 973.7, 616.0, 983.9, 611.2, 992.7, 605.4, 1001.5, 599.7, 1007.5, 595.2, 1013.5, 590.6, 1025.3, 579.1, 1037.0, 567.7, 1037.0, 566.5, 1037.0, 565.4, 1019.6, 548.7, 1002.2, 532.0, 1000.3, 532.0, 998.5, 532.0, 988.0, 542.3};
        vector<float> m_tubeRight = {0.0, 132.7, 0.0, 265.3, 39.5, 156.2, 78.3, 47.9, 76.5, 46.0, 74.7, 44.0, 42.3, 44.0, 10.0, 44.0, 10.0, 31.0, 10.0, 18.0, 173.5, 18.0, 337.0, 18.0, 364.0, 45.0, 391.0, 72.0, 397.9, 72.0, 404.9, 72.0, 411.2, 68.6, 417.5, 65.2, 429.5, 58.6, 441.5, 52.0, 456.5, 45.6, 471.5, 39.2, 485.0, 34.7, 498.5, 30.2, 513.0, 26.6, 527.5, 23.0, 540.6, 21.0, 553.6, 19.0, 567.6, 18.0, 581.5, 17.0, 603.3, 16.3, 625.0, 15.7, 625.0, 31.2, 625.0, 46.8, 623.4, 47.4, 621.8, 48.0, 620.2, 48.0, 618.5, 48.0, 613.5, 50.6, 608.5, 53.2, 605.8, 55.8, 603.0, 58.4, 603.0, 59.7, 603.0, 61.1, 604.7, 63.8, 606.5, 66.5, 613.1, 75.5, 619.8, 84.5, 624.3, 88.9, 628.9, 93.3, 630.7, 92.6, 632.5, 91.9, 662.0, 74.1, 691.5, 56.3, 699.5, 51.7, 707.5, 47.1, 708.9, 46.2, 710.4, 45.4, 709.6, 44.2, 708.9, 43.0, 679.9, 43.0, 651.0, 43.0, 651.0, 28.5, 651.0, 14.0, 897.9, 14.0, 1144.9, 14.0, 1146.4, 15.6, 1148.0, 17.1, 1148.0, 28.0, 1148.0, 38.9, 1146.4, 40.4, 1144.9, 42.0, 1103.0, 42.0, 1061.1, 42.0, 1060.4, 43.2, 1059.6, 44.4, 1060.7, 44.7, 1061.8, 45.1, 1070.7, 50.9, 1079.5, 56.8, 1087.6, 63.8, 1095.7, 70.8, 1102.2, 78.7, 1108.7, 86.5, 1113.5, 93.8, 1118.2, 101.2, 1121.5, 108.3, 1124.8, 115.5, 1127.3, 124.5, 1129.9, 133.5, 1132.7, 146.0, 1135.5, 158.5, 1135.8, 339.0, 1136.1, 519.5, 1135.0, 530.5, 1133.9, 541.5, 1131.5, 552.5, 1129.2, 563.5, 1126.0, 573.0, 1122.9, 582.5, 1117.0, 594.8, 1111.1, 607.1, 1105.4, 615.8, 1099.8, 624.5, 1094.2, 631.5, 1088.6, 638.5, 1082.5, 644.9, 1076.5, 651.3, 1067.5, 658.8, 1058.5, 666.4, 1048.9, 672.7, 1039.2, 679.0, 1026.9, 684.9, 1014.5, 690.9, 1005.0, 694.0, 995.5, 697.2, 984.5, 699.8, 973.5, 702.4, 486.8, 702.7, -5.68434188608e-13, 703.0, -5.68434188608e-13, 711.5, -5.68434188608e-13, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 360.0, 1152.0, 0.0, 576.0, 0.0, -4.54747350886e-13, 0.0, -4.54747350886e-13, 132.7};
        vector<float> m_tubeRightLaunch = {1136.0, 402.7, 1136.0, 522.5, 1135.0, 531.5, 1134.0, 540.5, 1131.9, 550.9, 1129.8, 561.3, 1126.3, 571.9, 1122.9, 582.5, 1116.9, 594.9, 1111.0, 607.2, 1104.7, 616.9, 1098.4, 626.5, 1090.8, 635.5, 1083.3, 644.5, 1076.9, 650.5, 1070.5, 656.6, 1063.5, 662.2, 1056.5, 667.8, 1047.8, 673.4, 1039.1, 679.1, 1026.8, 685.0, 1014.5, 690.9, 1005.0, 694.0, 995.5, 697.2, 984.5, 699.8, 973.5, 702.4, 486.7, 702.7, 0.0, 703.0, 0.0, 711.5, 0.0, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 501.5, 1152.0, 283.0, 1144.0, 283.0, 1136.0, 283.0, 1136.0, 402.7};
        vector<vector<float>> m_launchTubeLayer = {
            m_tubeLeft, m_tubeRightLaunch, m_tubeLeftUpper
        };

        // Main table layer
        vector<float> m_upperWall = {859.0, 48.1, 854.5, 49.0, 849.1, 50.1, 843.8, 51.2, 822.1, 62.0, 800.5, 72.8, 766.0, 91.8, 731.5, 110.8, 731.2, 113.0, 730.8, 115.1, 734.1, 120.6, 737.4, 126.0, 738.9, 126.0, 740.3, 126.0, 789.8, 98.9, 839.2, 71.8, 848.9, 69.4, 858.5, 66.9, 912.0, 67.3, 965.5, 67.7, 977.6, 70.3, 989.7, 73.0, 998.6, 76.1, 1007.5, 79.2, 1015.7, 83.1, 1023.8, 87.0, 1032.7, 92.9, 1041.5, 98.8, 1048.2, 104.9, 1054.9, 111.1, 1061.3, 118.8, 1067.7, 126.5, 1069.8, 129.9, 1071.9, 133.3, 1070.3, 136.4, 1068.8, 139.5, 1065.3, 143.8, 1061.8, 148.1, 1055.1, 152.6, 1048.5, 157.0, 1036.5, 144.6, 1024.5, 132.2, 1020.0, 129.2, 1015.5, 126.3, 1008.9, 122.3, 1002.4, 118.3, 993.2, 114.6, 984.1, 110.9, 976.5, 109.0, 968.9, 107.1, 958.9, 106.0, 948.8, 105.0, 928.4, 105.0, 907.9, 105.0, 901.7, 108.1, 895.5, 111.2, 839.0, 146.9, 782.5, 182.6, 766.8, 192.4, 751.1, 202.2, 750.5, 204.1, 749.9, 206.0, 753.6, 213.1, 757.4, 220.3, 760.4, 222.1, 763.5, 224.0, 767.8, 224.0, 772.1, 224.0, 776.0, 226.0, 780.0, 228.0, 782.0, 232.0, 784.0, 235.9, 784.0, 239.6, 784.0, 243.3, 781.0, 248.7, 778.0, 254.0, 778.0, 255.5, 778.0, 257.1, 780.1, 261.3, 782.2, 265.5, 784.3, 267.7, 786.3, 270.0, 797.6, 270.0, 808.9, 270.0, 810.3, 268.5, 811.8, 267.0, 813.1, 263.3, 814.3, 259.5, 816.1, 255.8, 818.0, 252.1, 832.8, 232.3, 847.6, 212.5, 857.0, 199.5, 866.5, 186.5, 875.5, 177.4, 884.5, 168.4, 892.0, 163.1, 899.5, 157.8, 907.0, 154.0, 914.5, 150.2, 922.5, 147.7, 930.5, 145.2, 939.0, 143.9, 947.4, 142.7, 959.4, 143.3, 971.5, 143.9, 981.6, 146.4, 991.7, 148.9, 999.1, 151.8, 1006.5, 154.8, 1023.2, 162.9, 1039.9, 171.1, 1046.2, 175.4, 1052.5, 179.7, 1058.5, 181.7, 1064.5, 183.8, 1070.3, 184.5, 1076.0, 185.2, 1077.9, 180.9, 1079.8, 176.5, 1080.9, 168.7, 1082.0, 160.9, 1082.0, 154.2, 1082.0, 147.5, 1081.1, 141.5, 1080.2, 135.5, 1078.6, 130.0, 1077.0, 124.4, 1071.1, 114.1, 1065.2, 103.7, 1054.3, 92.3, 1043.5, 80.8, 1036.4, 75.4, 1029.3, 70.0, 1019.4, 65.1, 1009.5, 60.1, 999.1, 56.5, 988.6, 52.9, 976.6, 50.3, 964.5, 47.7, 914.0, 47.4, 863.5, 47.1, 859.0, 48.1};
        vector<float> m_upperWall2 = {975.3, 477.9, 957.2, 495.7, 916.8, 531.1, 876.5, 566.5, 873.2, 569.3, 869.8, 572.0, 867.5, 572.0, 865.2, 572.0, 862.4, 569.7, 859.7, 567.5, 857.1, 564.5, 854.5, 561.6, 850.3, 557.6, 846.0, 553.6, 846.0, 551.5, 846.0, 549.3, 876.5, 520.6, 907.0, 491.8, 907.0, 489.6, 907.0, 487.4, 905.8, 486.2, 904.6, 485.0, 816.0, 485.0, 727.5, 485.0, 721.8, 489.6, 716.0, 494.2, 716.0, 495.5, 716.0, 496.8, 746.8, 525.7, 777.5, 554.7, 784.5, 560.9, 791.4, 567.0, 792.5, 567.0, 793.6, 567.0, 802.3, 575.4, 811.0, 583.9, 811.0, 588.8, 811.0, 593.8, 807.8, 596.5, 804.5, 599.1, 798.7, 603.4, 793.0, 607.7, 781.8, 611.0, 770.7, 614.3, 764.6, 613.7, 758.5, 613.1, 756.7, 612.5, 755.0, 611.8, 755.0, 608.7, 755.0, 605.7, 752.9, 599.9, 750.8, 594.2, 744.2, 588.3, 737.5, 582.5, 718.4, 563.8, 699.2, 545.0, 696.8, 545.0, 694.5, 545.0, 690.7, 548.1, 687.0, 551.1, 687.0, 555.3, 687.0, 559.4, 688.1, 565.4, 689.3, 571.5, 693.6, 589.5, 697.8, 607.5, 698.5, 610.9, 699.2, 614.3, 703.9, 618.9, 708.5, 623.6, 716.7, 626.8, 724.9, 630.1, 731.7, 631.6, 738.5, 633.2, 753.0, 633.7, 767.5, 634.2, 777.5, 633.2, 787.5, 632.1, 799.0, 628.5, 810.5, 625.0, 816.0, 623.1, 821.5, 621.2, 828.5, 618.5, 835.5, 615.9, 845.5, 611.3, 855.5, 606.7, 861.0, 603.1, 866.5, 599.6, 874.0, 595.3, 881.5, 591.0, 921.9, 553.2, 962.3, 515.5, 984.6, 492.6, 1007.0, 469.6, 1007.0, 468.0, 1007.0, 466.4, 1003.7, 463.2, 1000.4, 460.0, 997.0, 460.0, 993.5, 460.1, 975.3, 477.9};
        vector<float> m_upperWall3 = {967.4, 374.2, 960.5, 379.4, 935.5, 399.6, 910.5, 419.8, 907.1, 423.4, 903.6, 427.0, 841.0, 427.0, 778.3, 427.0, 770.4, 439.7, 762.6, 452.5, 762.5, 455.0, 762.5, 457.5, 847.3, 457.8, 932.2, 458.0, 935.4, 456.5, 938.7, 454.9, 973.1, 418.9, 1007.5, 383.0, 1007.8, 381.4, 1008.2, 379.8, 1002.9, 374.4, 997.6, 369.0, 985.9, 369.0, 974.3, 369.0, 967.4, 374.2};
        vector<float> m_upperWall4 = {786.1, 374.1, 783.0, 382.2, 783.0, 383.5, 783.0, 384.8, 786.1, 392.9, 789.2, 401.0, 838.5, 401.0, 887.8, 401.0, 906.5, 386.3, 925.2, 371.7, 925.7, 370.3, 926.2, 369.0, 925.0, 367.5, 923.8, 366.0, 917.1, 366.0, 910.5, 366.1, 894.6, 378.0, 878.7, 390.0, 856.6, 390.0, 834.5, 390.0, 822.5, 378.0, 810.5, 366.0, 799.9, 366.0, 789.2, 366.0, 786.1, 374.1};
        vector<float> m_upperWall5 = {788.7, 332.8, 787.0, 334.7, 787.0, 335.7, 787.0, 336.7, 788.8, 338.3, 790.7, 340.0, 797.2, 340.0, 803.7, 340.0, 805.3, 338.2, 807.0, 336.3, 807.0, 335.3, 807.0, 334.3, 805.2, 332.7, 803.3, 331.0, 796.8, 331.0, 790.3, 331.0, 788.7, 332.8};
        vector<float> m_upperWall6 = {788.7, 297.8, 787.0, 299.7, 787.0, 300.7, 787.0, 301.7, 788.8, 303.3, 790.7, 305.0, 796.7, 305.0, 802.7, 305.0, 804.3, 303.2, 806.0, 301.3, 806.0, 300.3, 806.0, 299.3, 804.2, 297.7, 802.3, 296.0, 796.3, 296.0, 790.3, 296.0, 788.7, 297.8};
        vector<float> m_leftSlide = {120.7, 46.0, 117.9, 47.8, 116.3, 50.0, 114.7, 52.3, 86.4, 126.4, 58.0, 200.4, 58.9, 201.3, 59.8, 202.2, 63.8, 200.9, 67.9, 199.7, 72.4, 201.0, 76.9, 202.2, 82.4, 207.7, 87.8, 213.3, 88.8, 212.6, 89.8, 212.0, 93.8, 202.3, 97.9, 192.5, 101.5, 183.0, 105.0, 173.5, 107.5, 167.0, 110.0, 160.5, 113.5, 151.0, 117.0, 141.5, 119.5, 135.0, 122.0, 128.5, 125.5, 119.3, 129.0, 110.0, 131.1, 103.3, 133.2, 96.5, 137.2, 84.5, 141.3, 72.5, 144.0, 66.4, 146.7, 60.3, 149.1, 58.1, 151.5, 55.8, 155.0, 54.1, 158.5, 52.5, 218.4, 52.0, 278.3, 51.5, 279.3, 49.8, 280.4, 48.1, 278.6, 46.1, 276.7, 44.0, 200.1, 44.1, 123.5, 44.1, 120.7, 46.0};
        vector<float> m_rightSlide = {82.2, 464.4, 77.0, 469.7, 72.4, 471.0, 67.9, 472.3, 63.8, 471.1, 59.8, 469.8, 58.9, 470.7, 58.0, 471.6, 85.5, 543.5, 112.9, 615.5, 115.1, 619.7, 117.3, 624.0, 120.7, 626.0, 124.1, 628.0, 200.4, 628.0, 276.7, 628.0, 278.6, 625.9, 280.4, 623.9, 279.3, 622.2, 278.3, 620.5, 218.4, 620.0, 158.5, 619.5, 155.0, 617.9, 151.5, 616.2, 149.1, 613.9, 146.7, 611.7, 144.0, 605.6, 141.2, 599.5, 136.6, 585.5, 132.0, 571.5, 129.0, 563.0, 126.1, 554.5, 122.5, 545.0, 118.9, 535.5, 116.5, 529.0, 114.1, 522.5, 110.5, 513.0, 106.9, 503.5, 104.5, 497.0, 102.1, 490.5, 99.7, 484.0, 97.2, 477.5, 93.3, 468.6, 89.5, 459.7, 88.5, 459.3, 87.5, 459.0, 82.2, 464.4};
        vector<float> m_leftSlideLine = {166.2, 79.2, 165.0, 80.4, 165.0, 82.1, 165.0, 83.8, 166.4, 84.9, 167.7, 86.0, 219.5, 85.8, 271.3, 85.5, 272.4, 83.7, 273.5, 82.0, 272.4, 80.2, 271.3, 78.5, 219.3, 78.2, 167.4, 78.0, 166.2, 79.2};
        vector<float> m_rightSlideLine = {166.2, 587.2, 165.0, 588.4, 165.0, 590.1, 165.0, 591.8, 166.4, 592.9, 167.7, 594.0, 219.5, 593.8, 271.3, 593.5, 272.4, 591.7, 273.5, 590.0, 272.4, 588.2, 271.3, 586.5, 219.3, 586.2, 167.4, 586.0, 166.2, 587.2};
        vector<float> m_leftBumper = {160.4, 113.9, 157.4, 115.7, 143.7, 147.1, 130.0, 178.5, 130.0, 181.6, 130.0, 184.7, 132.3, 186.8, 134.6, 189.0, 137.6, 189.0, 140.7, 189.0, 142.9, 186.6, 145.2, 184.2, 144.8, 180.5, 144.5, 176.7, 160.0, 168.8, 175.5, 160.9, 183.1, 156.5, 190.8, 152.1, 196.4, 149.6, 202.1, 147.1, 224.3, 135.0, 246.6, 123.0, 251.6, 125.5, 254.9, 128.0, 257.8, 128.0, 260.7, 128.0, 262.8, 125.7, 265.0, 123.4, 265.0, 120.3, 265.0, 117.2, 261.9, 114.6, 258.8, 112.0, 211.2, 112.0, 163.5, 112.0, 160.4, 113.9};
        vector<float> m_rightBumper = {132.2, 485.3, 130.0, 487.6, 130.0, 490.6, 130.0, 493.5, 143.7, 524.9, 157.4, 556.3, 160.4, 558.1, 163.5, 560.0, 211.2, 560.0, 258.8, 560.0, 261.9, 557.4, 265.0, 554.8, 265.0, 551.6, 265.0, 548.3, 262.7, 546.2, 260.4, 544.0, 257.6, 544.0, 254.9, 544.0, 251.6, 546.5, 248.3, 549.0, 224.3, 537.0, 202.1, 524.9, 196.4, 522.4, 190.8, 519.9, 183.1, 515.5, 175.5, 511.1, 160.0, 503.2, 144.5, 495.3, 144.8, 491.5, 145.2, 487.8, 142.9, 485.4, 140.7, 483.0, 137.5, 483.0, 134.3, 483.0, 132.2, 485.3};
        vector<float> m_backdoor = {422.0, 670.2, 422.0, 672.5, 427.5, 681.5, 433.0, 690.5, 433.0, 692.5, 433.0, 694.5, 435.0, 695.8, 437.0, 697.0, 437.0, 699.3, 437.0, 701.7, 439.4, 702.9, 441.8, 704.2, 442.8, 706.4, 443.8, 708.6, 448.6, 709.7, 453.5, 710.8, 462.8, 710.9, 472.0, 711.1, 472.0, 710.0, 472.0, 709.0, 474.5, 709.0, 477.0, 709.0, 477.0, 706.7, 477.0, 704.3, 467.7, 703.7, 458.3, 703.1, 453.9, 701.1, 449.5, 699.2, 445.5, 695.7, 441.4, 692.2, 434.1, 680.1, 426.8, 668.0, 424.4, 668.0, 422.0, 668.0, 422.0, 670.2};
        vector<vector<float>> m_layer1ShapeData = {
            m_tubeRight, m_tubeLeft, m_tubeLeftUpper, m_upperWall, m_upperWall2, m_upperWall3, m_upperWall4, m_upperWall5, m_upperWall6, m_leftSlide, m_rightSlide, m_rightSlideLine, m_leftSlideLine, m_leftBumper, m_rightBumper, m_backdoor
        };

        // Layer 3 shapes.
        vector<float> m_leftInnerRail = {271.1, 46.8, 270.2, 48.6, 271.1, 50.3, 272.1, 52.0, 417.3, 52.0, 562.4, 52.0, 568.0, 57.8, 573.5, 63.5, 660.6, 156.5, 747.8, 249.5, 757.3, 255.7, 766.7, 262.0, 776.1, 266.4, 785.5, 270.8, 794.5, 273.8, 803.5, 276.8, 811.5, 278.4, 819.5, 280.0, 829.0, 281.0, 838.5, 282.0, 914.7, 282.0, 990.9, 282.0, 998.6, 280.9, 1006.3, 279.8, 1011.9, 277.8, 1017.5, 275.8, 1025.5, 271.1, 1033.5, 266.5, 1041.3, 258.7, 1049.1, 251.0, 1053.6, 241.2, 1058.2, 231.5, 1059.0, 229.5, 1059.9, 227.5, 1061.1, 223.0, 1062.3, 218.5, 1062.4, 205.0, 1062.5, 191.5, 1059.4, 182.8, 1056.3, 174.1, 1050.5, 163.8, 1044.7, 153.5, 1040.4, 147.4, 1036.2, 141.4, 1030.2, 135.9, 1024.3, 130.4, 1018.6, 126.6, 1012.9, 122.9, 1005.2, 119.0, 997.4, 115.1, 988.2, 112.1, 979.1, 109.1, 968.5, 107.0, 957.9, 105.0, 933.5, 105.0, 909.1, 105.0, 906.5, 106.0, 903.8, 107.0, 844.1, 144.2, 784.5, 181.3, 782.8, 182.8, 781.0, 184.3, 781.0, 186.5, 781.0, 188.8, 782.5, 190.0, 784.0, 191.2, 786.3, 190.8, 788.6, 190.4, 848.5, 153.0, 908.5, 115.7, 910.2, 114.3, 911.8, 112.8, 937.7, 113.2, 963.5, 113.6, 969.5, 115.3, 975.5, 117.0, 984.9, 120.7, 994.3, 124.3, 996.1, 126.1, 998.0, 128.0, 999.3, 128.0, 1000.7, 128.0, 1008.1, 133.1, 1015.5, 138.3, 1025.0, 147.9, 1034.5, 157.6, 1042.2, 169.0, 1049.9, 180.5, 1051.6, 185.0, 1053.2, 189.5, 1053.7, 202.0, 1054.2, 214.5, 1053.2, 219.5, 1052.2, 224.5, 1049.5, 232.3, 1046.7, 240.1, 1039.2, 248.2, 1031.6, 256.2, 1022.8, 262.2, 1013.9, 268.1, 1008.7, 270.0, 1003.5, 271.8, 996.5, 273.4, 989.5, 275.0, 918.0, 275.0, 846.5, 275.0, 833.5, 273.5, 820.5, 272.0, 812.5, 270.4, 804.6, 268.8, 794.6, 265.3, 784.7, 261.9, 777.0, 258.0, 769.4, 254.2, 760.2, 248.0, 751.0, 241.9, 742.3, 233.7, 733.7, 225.5, 707.7, 196.5, 681.7, 167.5, 623.6, 106.2, 565.5, 45.0, 418.8, 45.0, 272.1, 45.0, 271.1, 46.8};
        vector<float> m_leftOuterRail = {839.5, 60.9, 833.5, 62.6, 829.0, 65.7, 824.5, 68.7, 782.0, 92.0, 739.5, 115.3, 737.8, 116.8, 736.0, 118.3, 736.0, 120.5, 736.0, 122.8, 737.5, 124.0, 739.0, 125.2, 741.3, 124.8, 743.7, 124.3, 790.4, 98.6, 837.0, 72.9, 842.3, 70.6, 847.6, 68.2, 854.5, 67.2, 861.5, 66.2, 914.0, 67.0, 966.5, 67.8, 978.0, 70.3, 989.5, 72.7, 997.5, 75.4, 1005.5, 78.1, 1013.9, 82.1, 1022.4, 86.1, 1032.4, 92.7, 1042.5, 99.4, 1053.0, 109.9, 1063.6, 120.5, 1069.2, 129.0, 1074.8, 137.5, 1079.4, 147.6, 1084.0, 157.7, 1086.1, 167.6, 1088.2, 177.5, 1089.0, 182.5, 1089.9, 187.5, 1089.9, 207.0, 1090.0, 226.5, 1087.6, 237.5, 1085.3, 248.5, 1082.2, 256.0, 1079.0, 263.5, 1072.7, 274.1, 1066.4, 284.7, 1060.5, 292.9, 1054.6, 301.1, 1051.2, 305.1, 1047.7, 309.2, 980.8, 363.8, 913.8, 418.5, 908.4, 422.7, 903.0, 427.0, 849.0, 427.0, 795.0, 427.0, 795.0, 414.0, 795.0, 401.0, 841.3, 401.0, 887.5, 401.0, 918.5, 376.9, 949.5, 352.8, 972.3, 333.3, 995.0, 313.9, 995.0, 312.6, 995.0, 311.4, 993.8, 310.2, 992.6, 309.0, 903.3, 309.0, 814.0, 309.0, 803.2, 305.5, 792.5, 302.0, 776.5, 293.9, 760.5, 285.8, 753.5, 282.2, 746.5, 278.7, 739.9, 273.8, 733.4, 269.0, 691.8, 225.2, 650.3, 181.5, 603.2, 132.0, 556.1, 82.5, 552.3, 80.3, 548.5, 78.0, 394.7, 78.0, 241.0, 78.0, 239.9, 80.4, 238.8, 82.7, 239.9, 84.9, 241.1, 87.0, 395.3, 87.0, 549.6, 87.0, 623.6, 164.1, 697.5, 241.2, 715.5, 260.1, 733.5, 279.1, 743.2, 284.4, 753.0, 289.8, 764.2, 295.3, 775.5, 300.9, 783.0, 304.0, 790.5, 307.2, 800.5, 311.2, 810.5, 315.2, 839.0, 316.0, 867.5, 316.8, 924.5, 317.0, 981.5, 317.1, 979.0, 319.1, 976.5, 321.1, 962.0, 333.5, 947.5, 345.8, 916.5, 369.9, 885.5, 394.0, 837.9, 394.0, 790.4, 394.0, 789.2, 395.2, 788.0, 396.4, 788.0, 414.0, 788.0, 431.6, 789.2, 432.8, 790.4, 434.0, 847.8, 434.0, 905.1, 434.0, 942.3, 403.7, 979.5, 373.4, 1014.5, 344.9, 1049.5, 316.3, 1056.2, 309.2, 1062.8, 302.2, 1071.3, 289.3, 1079.8, 276.5, 1084.8, 266.5, 1089.8, 256.5, 1093.6, 246.5, 1097.5, 236.5, 1097.4, 204.0, 1097.3, 171.5, 1095.6, 165.3, 1093.9, 159.0, 1086.5, 143.8, 1079.0, 128.5, 1072.6, 120.0, 1066.2, 111.5, 1056.4, 102.0, 1046.5, 92.4, 1037.1, 86.2, 1027.7, 79.9, 1018.6, 75.5, 1009.5, 71.2, 1000.6, 68.1, 991.7, 65.0, 979.6, 62.3, 967.5, 59.7, 906.5, 59.4, 845.5, 59.1, 839.5, 60.9};
        vector<float> m_rightOuterRail = {1063.5, 595.1, 1058.5, 602.1, 1047.4, 612.9, 1036.4, 623.7, 1024.9, 631.3, 1013.5, 638.9, 1003.0, 643.9, 992.5, 648.9, 981.7, 652.5, 970.9, 656.1, 959.2, 658.5, 947.5, 661.0, 675.9, 661.0, 404.3, 661.0, 375.2, 641.0, 346.2, 621.0, 291.3, 621.2, 236.5, 621.5, 236.5, 624.0, 236.5, 626.5, 288.7, 626.8, 340.9, 627.0, 370.6, 647.5, 400.3, 668.0, 677.2, 668.0, 954.0, 668.0, 963.3, 666.0, 972.5, 663.9, 984.5, 659.9, 996.5, 655.9, 1007.5, 650.6, 1018.5, 645.2, 1027.5, 639.3, 1036.5, 633.3, 1043.0, 628.0, 1049.5, 622.6, 1056.9, 615.1, 1064.2, 607.5, 1070.1, 599.7, 1076.0, 591.9, 1073.5, 589.2, 1070.9, 588.0, 1069.7, 588.1, 1068.5, 588.1, 1063.5, 595.1};
        vector<float> m_rightInnerRail = {660.8, 433.7, 655.4, 437.5, 627.7, 457.4, 600.0, 477.3, 599.5, 479.1, 598.9, 480.9, 600.0, 482.9, 601.0, 484.9, 633.1, 529.2, 665.2, 573.5, 666.8, 574.7, 668.4, 576.0, 669.7, 576.0, 671.0, 576.0, 681.8, 568.6, 692.7, 561.2, 695.5, 559.7, 698.4, 558.2, 720.7, 579.9, 742.9, 601.5, 745.5, 602.4, 748.0, 603.4, 748.0, 608.4, 748.0, 613.5, 744.9, 618.8, 741.9, 624.1, 739.4, 625.0, 736.9, 626.0, 574.2, 626.0, 411.5, 626.0, 381.8, 605.5, 352.1, 585.0, 296.3, 585.2, 240.5, 585.5, 240.5, 589.5, 240.5, 593.5, 295.8, 593.8, 351.2, 594.0, 380.2, 614.0, 409.1, 634.0, 574.5, 634.0, 739.9, 634.0, 743.7, 631.9, 747.5, 629.8, 748.8, 628.7, 750.2, 627.6, 752.6, 622.8, 755.0, 618.1, 755.0, 611.9, 755.0, 605.7, 752.8, 599.8, 750.7, 593.9, 730.1, 574.1, 709.5, 554.3, 704.2, 549.6, 698.9, 545.0, 696.7, 545.0, 694.5, 545.0, 682.5, 554.9, 670.5, 564.8, 669.9, 564.1, 669.2, 563.5, 640.1, 523.2, 611.0, 483.0, 610.7, 482.1, 610.5, 481.2, 638.5, 461.0, 666.5, 440.8, 667.6, 440.4, 668.6, 439.9, 713.5, 462.0, 758.4, 484.1, 752.5, 498.0, 745.9, 511.1, 738.9, 504.8, 731.8, 498.5, 726.8, 494.2, 721.8, 490.0, 720.0, 490.0, 718.1, 490.0, 716.6, 491.6, 715.0, 493.1, 715.0, 494.9, 715.0, 496.7, 740.8, 519.5, 766.5, 542.4, 795.1, 570.4, 823.7, 598.5, 829.6, 603.1, 835.5, 607.7, 841.6, 611.8, 847.6, 615.9, 856.1, 620.4, 864.5, 624.9, 875.5, 628.7, 886.5, 632.5, 909.9, 632.8, 933.4, 633.1, 939.9, 632.0, 946.5, 630.9, 956.6, 627.5, 966.8, 624.1, 976.1, 619.4, 985.5, 614.7, 996.0, 607.7, 1006.5, 600.6, 1022.3, 584.8, 1038.2, 569.1, 1037.8, 567.3, 1037.5, 565.6, 1034.8, 564.1, 1032.2, 562.6, 1029.4, 566.1, 1026.7, 569.5, 1015.6, 580.6, 1004.5, 591.6, 997.0, 597.2, 989.4, 602.8, 983.0, 606.9, 976.5, 611.0, 972.5, 612.9, 968.5, 614.9, 958.5, 618.6, 948.5, 622.3, 942.3, 624.6, 936.1, 626.9, 935.5, 626.0, 934.9, 625.0, 913.1, 625.0, 891.2, 625.0, 882.4, 622.4, 873.5, 619.9, 864.1, 615.4, 854.7, 611.0, 846.4, 605.5, 838.2, 600.0, 827.3, 589.3, 816.4, 578.5, 813.0, 574.5, 809.5, 570.5, 803.8, 566.5, 798.2, 562.6, 797.7, 560.0, 797.1, 557.5, 775.1, 537.6, 753.0, 517.7, 761.5, 499.9, 770.1, 482.8, 769.5, 481.1, 769.0, 479.3, 718.7, 454.6, 668.5, 429.9, 667.4, 430.0, 666.3, 430.0, 660.8, 433.7};
        vector<vector<float>> m_layer2ShapeData = {
            m_leftInnerRail, m_leftOuterRail, m_rightOuterRail, m_rightInnerRail
        };

        // All the layers
        vector<vector<vector<float>>> m_layerData = {m_underLayer, m_launchTubeLayer, m_layer1ShapeData, m_layer2ShapeData};
};
#endif