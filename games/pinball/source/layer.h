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

        // Launch tube layer
        vector<float> m_tubeLeft = {0.0, 527.8, 0.0, 672.0, 463.8, 671.7, 927.5, 671.4, 939.0, 669.7, 950.5, 667.9, 962.0, 665.4, 973.5, 662.8, 985.5, 658.8, 997.5, 654.8, 1009.0, 649.4, 1020.4, 643.9, 1031.5, 636.6, 1042.5, 629.2, 1051.3, 621.0, 1060.1, 612.7, 1066.3, 604.6, 1072.6, 596.5, 1075.3, 592.3, 1078.0, 588.0, 1074.6, 584.6, 1071.2, 583.0, 1070.2, 583.0, 1069.2, 583.0, 1066.9, 586.7, 1064.6, 590.5, 1058.4, 598.6, 1052.1, 606.8, 1044.3, 614.0, 1036.5, 621.2, 1026.1, 628.1, 1015.8, 635.1, 1005.4, 640.0, 995.1, 645.0, 981.8, 649.4, 968.5, 653.8, 955.9, 656.4, 943.3, 659.0, 940.6, 659.0, 938.0, 659.0, 938.0, 660.0, 938.0, 661.0, 926.5, 661.0, 915.0, 661.0, 915.0, 645.5, 915.0, 630.0, 920.3, 630.0, 925.6, 630.0, 935.1, 628.4, 944.5, 626.8, 954.0, 623.8, 963.5, 620.8, 973.7, 616.0, 983.9, 611.2, 992.7, 605.4, 1001.5, 599.7, 1007.5, 595.2, 1013.5, 590.6, 1025.3, 579.1, 1037.0, 567.7, 1037.0, 566.6, 1037.0, 565.5, 1018.1, 547.2, 999.1, 529.0, 994.3, 534.7, 989.5, 540.5, 983.5, 546.5, 977.5, 552.6, 942.0, 584.0, 906.5, 615.4, 896.5, 621.8, 886.5, 628.1, 868.5, 637.0, 850.5, 645.9, 840.5, 649.6, 830.5, 653.3, 819.0, 656.9, 807.5, 660.5, 706.2, 660.8, 604.9, 661.0, 589.0, 658.6, 573.0, 656.1, 561.3, 653.4, 549.5, 650.8, 538.0, 647.3, 526.5, 643.9, 519.0, 640.5, 511.5, 637.2, 496.0, 630.2, 480.5, 623.2, 470.5, 619.9, 460.5, 616.5, 418.3, 616.5, 376.0, 616.5, 356.3, 636.2, 336.5, 656.0, 181.7, 656.0, 27.0, 656.0, 27.0, 638.5, 27.0, 621.0, 55.4, 620.8, 83.7, 620.5, 42.4, 502.6, 1.1, 384.7, 0.5, 384.2, 2.35922392733e-13, 383.7, 2.35922392733e-13, 527.8};
        vector<float> m_tubeRight = {0.1, 144.2, 0.2, 288.5, 1.5, 285.5, 2.8, 282.5, 42.3, 168.5, 81.8, 54.5, 82.5, 52.7, 83.2, 51.0, 55.1, 51.0, 27.0, 51.0, 27.0, 33.5, 27.0, 16.0, 182.0, 16.0, 337.0, 16.0, 337.0, 17.0, 337.0, 18.0, 364.0, 45.0, 391.0, 72.0, 397.9, 72.0, 404.9, 72.0, 411.2, 68.6, 417.5, 65.2, 429.5, 58.6, 441.5, 52.0, 456.5, 45.6, 471.5, 39.2, 485.0, 34.7, 498.5, 30.2, 513.0, 26.6, 527.5, 23.0, 540.6, 21.0, 553.6, 19.0, 567.6, 18.0, 581.5, 17.0, 603.3, 17.0, 625.0, 17.0, 625.0, 33.4, 625.0, 49.9, 623.3, 50.4, 621.5, 50.9, 614.0, 52.5, 606.5, 54.1, 603.5, 55.7, 600.5, 57.3, 598.0, 58.6, 595.5, 59.9, 588.1, 66.8, 580.6, 73.6, 584.7, 79.5, 588.8, 85.5, 591.9, 88.7, 594.9, 92.0, 596.5, 92.0, 598.1, 92.0, 615.3, 83.4, 632.5, 74.7, 645.5, 67.0, 658.5, 59.3, 683.0, 47.2, 707.5, 35.2, 714.0, 32.2, 720.5, 29.2, 733.0, 25.2, 745.5, 21.2, 753.0, 20.0, 760.5, 18.9, 765.0, 17.8, 769.5, 16.7, 860.5, 16.3, 951.5, 15.9, 962.5, 17.0, 973.5, 18.1, 984.5, 20.5, 995.5, 22.8, 1005.0, 26.0, 1014.5, 29.1, 1026.9, 35.1, 1039.2, 41.0, 1048.9, 47.3, 1058.5, 53.6, 1067.5, 61.2, 1076.5, 68.7, 1082.5, 75.1, 1088.6, 81.5, 1094.2, 88.5, 1099.8, 95.5, 1105.4, 104.2, 1111.1, 112.9, 1117.0, 125.2, 1122.9, 137.5, 1126.0, 147.0, 1129.2, 156.5, 1131.6, 167.8, 1134.0, 179.0, 1135.6, 194.8, 1137.1, 210.5, 1136.5, 366.0, 1135.9, 521.5, 1134.9, 531.0, 1134.0, 540.5, 1131.9, 550.9, 1129.8, 561.3, 1126.3, 571.9, 1122.9, 582.5, 1117.0, 594.8, 1111.1, 607.1, 1105.4, 615.8, 1099.8, 624.5, 1094.2, 631.5, 1088.6, 638.5, 1082.5, 644.9, 1076.5, 651.3, 1067.5, 658.8, 1058.5, 666.4, 1048.9, 672.7, 1039.2, 679.0, 1026.9, 684.9, 1014.5, 690.9, 1003.9, 694.3, 993.3, 697.8, 982.9, 699.9, 972.5, 702.0, 963.5, 703.0, 954.5, 704.0, 477.3, 704.0, 5.68434188608e-13, 704.0, 5.68434188608e-13, 712.0, 5.68434188608e-13, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 360.0, 1152.0, -1.13686837722e-13, 576.0, -1.13686837722e-13, 4.54747350886e-13, -1.13686837722e-13, 0.1, 144.2};
        vector<vector<float>> m_launchTubeLayer = {
            m_tubeLeft, m_tubeRight
        };

        // Main table layer
        vector<float> m_launchExitLock = {1068.0, 585.4, 1066.8, 586.9, 1067.2, 589.2, 1067.5, 591.5, 1087.9, 606.2, 1108.4, 621.0, 1110.6, 621.0, 1112.8, 621.0, 1114.0, 619.6, 1115.2, 618.1, 1114.8, 615.8, 1114.5, 613.5, 1094.1, 598.8, 1073.6, 584.0, 1071.4, 584.0, 1069.2, 584.0, 1068.0, 585.4};
        vector<float> m_upperWall = {786.0, 60.6, 777.5, 62.1, 765.8, 66.0, 754.2, 69.9, 744.5, 74.6, 734.9, 79.2, 723.2, 87.1, 711.5, 95.0, 708.1, 98.0, 704.6, 101.0, 707.4, 103.9, 710.3, 106.9, 714.7, 103.1, 719.0, 99.2, 727.8, 93.4, 736.5, 87.6, 746.8, 82.4, 757.1, 77.2, 767.8, 73.7, 778.5, 70.1, 788.0, 68.5, 797.5, 66.9, 881.5, 67.3, 965.5, 67.6, 977.6, 70.3, 989.7, 73.0, 998.6, 76.1, 1007.5, 79.2, 1015.7, 83.1, 1023.8, 87.0, 1032.7, 92.9, 1041.6, 98.9, 1048.7, 105.4, 1055.7, 111.9, 1061.3, 118.8, 1067.0, 125.7, 1068.8, 129.0, 1070.5, 130.9, 1072.4, 134.5, 1074.4, 138.1, 1073.4, 138.8, 1072.4, 139.5, 1064.4, 145.6, 1056.5, 151.7, 1050.7, 155.5, 1045.0, 159.3, 1039.7, 152.0, 1035.1, 145.5, 1031.3, 141.5, 1027.4, 137.5, 1021.3, 132.0, 1015.2, 126.5, 1007.3, 121.8, 999.4, 117.1, 991.6, 114.0, 983.9, 110.9, 976.4, 109.0, 968.9, 107.1, 958.9, 106.0, 948.8, 105.0, 920.1, 105.0, 891.4, 105.0, 883.2, 106.0, 875.0, 107.1, 866.3, 109.6, 857.5, 112.1, 849.2, 116.0, 840.8, 120.0, 833.7, 124.7, 826.6, 129.5, 817.8, 137.9, 809.0, 146.3, 804.0, 152.5, 799.1, 158.7, 794.5, 166.0, 790.0, 173.4, 790.0, 175.2, 790.0, 177.0, 792.6, 178.2, 795.3, 179.4, 796.6, 177.5, 798.0, 175.5, 803.9, 166.5, 809.8, 157.5, 817.5, 149.3, 825.1, 141.1, 833.1, 135.1, 841.1, 129.1, 851.3, 124.0, 861.5, 119.0, 871.5, 116.3, 881.5, 113.7, 914.0, 113.2, 946.5, 112.8, 957.1, 113.9, 967.8, 115.0, 975.6, 117.1, 983.5, 119.1, 991.1, 122.4, 998.7, 125.7, 1005.7, 130.3, 1012.7, 134.8, 1019.8, 141.4, 1026.8, 148.0, 1030.8, 153.3, 1034.9, 158.5, 1038.2, 164.1, 1041.6, 169.8, 1044.8, 168.5, 1047.9, 167.1, 1054.2, 162.9, 1060.5, 158.7, 1072.3, 149.7, 1084.0, 140.7, 1084.0, 139.5, 1084.0, 138.3, 1079.1, 130.2, 1074.3, 122.1, 1069.2, 115.8, 1064.2, 109.5, 1055.4, 101.0, 1046.5, 92.4, 1037.5, 86.4, 1028.5, 80.4, 1020.0, 76.3, 1011.5, 72.2, 1001.1, 68.6, 990.6, 64.9, 978.6, 62.3, 966.5, 59.6, 880.5, 59.4, 794.5, 59.1, 786.0, 60.6};
        vector<float> m_upperWall2 = {971.5, 482.0, 957.5, 495.1, 917.1, 530.8, 876.6, 566.5, 873.2, 569.2, 869.7, 572.0, 867.4, 572.0, 865.2, 572.0, 862.4, 569.7, 859.7, 567.5, 857.1, 564.5, 854.5, 561.6, 850.3, 557.6, 846.0, 553.6, 846.0, 551.5, 846.0, 549.3, 876.5, 520.6, 907.0, 491.8, 907.0, 489.6, 907.0, 487.4, 905.8, 486.2, 904.6, 485.0, 816.1, 485.0, 727.5, 485.0, 721.8, 489.6, 716.0, 494.2, 716.0, 495.5, 716.0, 496.8, 746.8, 525.7, 777.5, 554.7, 784.5, 560.9, 791.4, 567.0, 792.5, 567.0, 793.6, 567.0, 802.3, 575.4, 811.0, 583.9, 811.0, 588.8, 811.0, 593.8, 807.8, 596.5, 804.5, 599.1, 798.7, 603.4, 793.0, 607.7, 781.8, 611.0, 770.7, 614.3, 764.6, 613.7, 758.5, 613.1, 756.7, 612.5, 755.0, 611.8, 755.0, 608.7, 755.0, 605.7, 752.9, 599.9, 750.8, 594.2, 744.2, 588.3, 737.5, 582.5, 718.4, 563.7, 699.2, 545.0, 696.8, 545.0, 694.5, 545.0, 690.7, 548.1, 687.0, 551.1, 687.0, 554.4, 687.0, 557.6, 694.4, 589.5, 701.9, 621.5, 704.2, 623.3, 706.5, 625.2, 744.0, 624.7, 781.5, 624.2, 793.0, 622.1, 804.5, 620.0, 816.0, 616.4, 827.5, 612.9, 841.5, 606.1, 855.5, 599.2, 863.5, 593.3, 871.5, 587.3, 917.0, 545.5, 962.5, 503.7, 972.0, 494.5, 981.5, 485.3, 986.8, 480.5, 992.0, 475.7, 992.0, 473.6, 992.0, 471.4, 990.8, 470.2, 989.6, 469.0, 987.6, 469.0, 985.5, 469.0, 971.5, 482.0};
        vector<float> m_upperWall3 = {963.8, 419.4, 950.5, 429.8, 939.0, 438.9, 927.5, 448.0, 862.0, 448.2, 796.5, 448.5, 796.5, 453.0, 796.5, 457.5, 863.5, 457.7, 930.5, 458.0, 951.0, 440.8, 971.5, 423.7, 976.8, 419.7, 982.0, 415.8, 982.0, 413.6, 982.0, 411.4, 980.8, 410.2, 979.6, 409.0, 978.4, 409.0, 977.2, 409.0, 963.8, 419.4};
        vector<float> m_upperWall4 = {928.9, 391.6, 911.5, 405.3, 906.0, 408.9, 900.5, 412.5, 848.5, 413.0, 796.5, 413.5, 796.5, 417.5, 796.5, 421.5, 849.8, 421.8, 903.2, 422.0, 927.2, 403.3, 951.3, 384.5, 951.8, 383.1, 952.3, 381.7, 951.3, 380.1, 950.3, 378.5, 948.3, 378.2, 946.3, 377.9, 928.9, 391.6};
        vector<float> m_upperWall5 = {852.4, 333.7, 850.7, 336.5, 844.1, 343.4, 837.5, 350.2, 829.5, 356.5, 821.5, 362.7, 813.5, 368.0, 805.6, 373.4, 801.0, 375.1, 796.5, 376.8, 796.5, 380.1, 796.5, 383.5, 845.5, 383.8, 894.5, 384.1, 897.5, 383.5, 900.6, 383.0, 908.5, 376.4, 916.5, 369.8, 916.5, 368.1, 916.5, 366.5, 904.0, 366.0, 891.5, 365.5, 887.0, 363.2, 882.5, 360.8, 879.6, 358.2, 876.8, 355.5, 868.7, 345.5, 860.7, 335.5, 859.2, 333.2, 857.8, 331.0, 856.0, 331.0, 854.2, 331.0, 852.4, 333.7};
        vector<float> m_leftSlide = {120.5, 46.1, 118.4, 47.1, 117.1, 49.2, 115.8, 51.3, 113.3, 57.9, 110.9, 64.5, 107.9, 72.5, 104.9, 80.5, 103.6, 84.0, 102.3, 87.5, 97.1, 101.5, 91.9, 115.5, 89.9, 121.0, 87.8, 126.5, 86.5, 130.0, 85.1, 133.5, 82.6, 140.0, 80.2, 146.5, 76.4, 156.5, 72.7, 166.5, 70.3, 173.0, 67.9, 179.5, 66.6, 183.0, 65.3, 186.5, 62.6, 193.8, 59.8, 201.2, 64.2, 200.8, 67.9, 199.7, 72.4, 201.0, 76.9, 202.2, 80.3, 205.7, 83.8, 209.1, 87.6, 208.8, 91.3, 208.5, 94.6, 200.5, 97.9, 192.5, 101.5, 183.0, 105.0, 173.5, 107.5, 167.0, 110.0, 160.5, 113.5, 151.0, 117.0, 141.5, 119.5, 135.0, 122.0, 128.5, 125.5, 119.3, 129.0, 110.0, 131.1, 103.3, 133.2, 96.5, 137.2, 84.5, 141.3, 72.5, 144.0, 66.4, 146.7, 60.3, 149.1, 58.1, 151.5, 55.8, 155.0, 54.1, 158.5, 52.5, 218.4, 52.0, 278.3, 51.5, 279.3, 49.8, 280.4, 48.2, 279.1, 46.6, 277.8, 45.0, 200.1, 45.1, 122.5, 45.1, 120.5, 46.1};
        vector<float> m_rightSlide = {80.2, 466.4, 77.0, 469.8, 72.4, 471.0, 67.9, 472.3, 64.2, 471.2, 60.6, 470.1, 62.4, 477.7, 64.9, 484.5, 67.5, 491.5, 70.1, 498.5, 71.4, 502.0, 72.7, 505.5, 76.4, 515.5, 80.1, 525.5, 81.5, 529.0, 82.9, 532.5, 85.5, 539.5, 88.2, 546.5, 90.0, 551.5, 91.9, 556.5, 97.1, 570.5, 102.3, 584.5, 103.6, 588.0, 104.9, 591.5, 107.9, 599.5, 110.9, 607.5, 113.3, 614.1, 115.8, 620.7, 117.1, 622.8, 118.4, 624.9, 120.7, 625.9, 123.1, 627.0, 200.4, 627.0, 277.8, 627.0, 279.1, 625.4, 280.4, 623.8, 279.3, 622.2, 278.3, 620.5, 218.4, 620.0, 158.5, 619.5, 155.0, 617.9, 151.5, 616.2, 149.1, 613.9, 146.7, 611.7, 144.0, 605.6, 141.3, 599.5, 137.2, 587.5, 133.2, 575.5, 131.1, 568.7, 129.0, 562.0, 125.5, 552.7, 122.0, 543.5, 119.5, 537.0, 117.0, 530.5, 113.5, 521.0, 110.0, 511.5, 107.5, 505.0, 105.0, 498.5, 101.5, 489.0, 97.9, 479.5, 94.6, 471.5, 91.3, 463.5, 87.4, 463.2, 83.5, 463.0, 80.2, 466.4};
        vector<float> m_leftSlideLine = {163.9, 81.6, 162.6, 83.2, 163.7, 84.8, 164.7, 86.5, 204.5, 86.5, 244.3, 86.5, 245.3, 84.8, 246.4, 83.2, 245.1, 81.6, 243.8, 80.0, 204.5, 80.0, 165.2, 80.0, 163.9, 81.6};
        vector<float> m_rightSlideLine = {163.9, 586.6, 162.6, 588.2, 163.7, 589.8, 164.7, 591.5, 204.5, 591.5, 244.3, 591.5, 245.3, 589.8, 246.4, 588.2, 245.1, 586.6, 243.8, 585.0, 204.5, 585.0, 165.2, 585.0, 163.9, 586.6};
        vector<float> m_leftBumper = {156.9, 116.0, 155.3, 117.0, 154.0, 120.2, 152.8, 123.5, 151.0, 127.5, 149.2, 131.5, 146.5, 138.0, 143.7, 144.5, 142.0, 148.5, 140.2, 152.5, 137.6, 159.0, 134.9, 165.5, 133.3, 168.4, 131.8, 171.2, 131.6, 176.6, 131.5, 181.9, 132.8, 183.2, 134.1, 184.5, 138.3, 184.5, 142.5, 184.5, 150.0, 180.0, 157.5, 175.5, 160.0, 174.1, 162.5, 172.7, 166.0, 170.8, 169.5, 168.9, 172.5, 167.1, 175.5, 165.3, 180.0, 162.6, 184.5, 159.9, 187.3, 158.9, 190.0, 157.8, 192.8, 155.1, 195.5, 154.1, 200.5, 151.0, 205.5, 147.9, 208.3, 146.9, 211.0, 145.8, 213.3, 143.5, 215.5, 142.8, 218.5, 140.5, 221.5, 138.3, 223.7, 137.6, 225.8, 136.9, 227.0, 135.5, 228.2, 134.0, 229.7, 134.0, 231.1, 134.0, 233.2, 132.0, 235.4, 130.0, 236.9, 130.0, 238.4, 130.0, 241.2, 127.3, 244.0, 124.6, 244.0, 122.0, 244.0, 119.3, 241.7, 117.2, 239.4, 115.0, 198.9, 115.0, 158.5, 115.1, 156.9, 116.0};
        vector<float> m_rightBumper = {134.4, 487.9, 132.3, 488.8, 131.6, 491.5, 130.9, 494.1, 131.6, 497.8, 132.3, 501.5, 133.6, 504.0, 134.9, 506.5, 137.6, 513.0, 140.2, 519.5, 142.0, 523.5, 143.7, 527.5, 146.5, 534.0, 149.2, 540.5, 151.0, 544.5, 152.8, 548.5, 154.0, 551.8, 155.3, 555.1, 157.1, 556.0, 158.9, 557.0, 199.3, 557.0, 239.7, 557.0, 241.8, 554.7, 244.0, 552.4, 244.0, 550.0, 244.0, 547.6, 241.3, 544.8, 238.6, 542.0, 237.0, 542.0, 235.4, 542.0, 233.2, 540.0, 231.1, 538.0, 229.7, 538.0, 228.2, 538.0, 227.0, 536.5, 225.8, 535.1, 223.7, 534.4, 221.5, 533.7, 218.5, 531.5, 215.5, 529.2, 213.3, 528.5, 211.0, 527.9, 208.3, 525.1, 205.5, 524.1, 200.5, 521.0, 195.5, 517.9, 192.8, 516.9, 190.0, 515.8, 187.3, 513.1, 184.5, 512.1, 180.0, 509.4, 175.5, 506.7, 172.5, 504.9, 169.5, 503.1, 166.0, 501.2, 162.5, 499.3, 160.0, 497.9, 157.5, 496.5, 150.4, 492.2, 143.2, 487.9, 139.9, 487.5, 136.5, 487.0, 134.4, 487.9};
        vector<vector<float>> m_layer1ShapeData = {
            m_tubeRight, m_tubeLeft, m_launchExitLock, m_upperWall, m_upperWall2, m_upperWall3, m_upperWall4, m_upperWall5, m_leftSlide, m_rightSlide, m_rightSlideLine, m_leftSlideLine, m_leftBumper, m_rightBumper
        };

        // Layer 2 shapes.
        vector<float> m_leftInnerRail = {271.1, 46.8, 270.2, 48.6, 271.1, 50.3, 272.1, 52.0, 416.9, 52.0, 561.7, 52.0, 644.7, 141.2, 727.7, 230.5, 737.3, 239.7, 746.9, 248.8, 756.7, 255.4, 766.6, 261.9, 776.0, 266.4, 785.5, 270.8, 793.4, 273.5, 801.3, 276.1, 809.9, 278.0, 818.5, 279.9, 830.5, 281.1, 842.5, 282.3, 908.5, 281.7, 974.5, 281.1, 983.5, 280.0, 992.5, 278.8, 1001.6, 276.5, 1010.6, 274.2, 1018.3, 271.0, 1025.9, 267.8, 1032.2, 263.8, 1038.5, 259.7, 1044.1, 253.9, 1049.8, 248.0, 1054.8, 237.8, 1059.9, 227.5, 1061.1, 223.0, 1062.3, 218.5, 1062.4, 205.0, 1062.5, 191.5, 1059.4, 182.8, 1056.3, 174.1, 1050.5, 163.8, 1044.7, 153.5, 1040.4, 147.4, 1036.2, 141.4, 1030.2, 135.9, 1024.3, 130.4, 1018.6, 126.6, 1012.9, 122.9, 1005.2, 119.0, 997.4, 115.1, 988.2, 112.1, 979.1, 109.1, 968.5, 107.0, 957.9, 105.0, 931.4, 105.0, 905.0, 105.0, 905.0, 108.9, 905.0, 112.9, 934.3, 113.2, 963.5, 113.6, 969.5, 115.3, 975.5, 117.0, 984.9, 120.7, 994.3, 124.3, 996.1, 126.1, 998.0, 128.0, 999.3, 128.0, 1000.7, 128.0, 1008.1, 133.1, 1015.5, 138.3, 1025.0, 147.9, 1034.5, 157.6, 1042.2, 169.0, 1049.9, 180.5, 1051.6, 185.0, 1053.2, 189.5, 1053.7, 201.5, 1054.2, 213.5, 1051.0, 221.0, 1047.8, 228.5, 1046.3, 232.5, 1044.8, 236.5, 1040.3, 243.7, 1035.8, 250.9, 1029.5, 255.5, 1023.1, 260.0, 1017.6, 263.0, 1013.6, 266.0, 1012.2, 266.0, 1010.8, 266.0, 1007.7, 267.4, 1004.5, 268.8, 1000.5, 269.4, 996.5, 270.0, 986.1, 271.0, 975.6, 272.0, 974.1, 272.4, 972.5, 272.9, 900.5, 273.1, 828.5, 273.3, 818.5, 271.6, 808.5, 269.8, 796.9, 266.0, 785.3, 262.2, 777.3, 258.2, 769.4, 254.2, 760.2, 248.0, 751.0, 241.9, 742.3, 233.7, 733.7, 225.5, 726.1, 216.0, 718.6, 206.5, 706.6, 192.0, 694.6, 177.5, 678.3, 158.3, 662.0, 139.1, 662.0, 137.8, 662.0, 136.4, 650.8, 125.3, 639.5, 114.2, 617.1, 92.8, 594.8, 71.5, 584.6, 61.5, 574.5, 51.5, 572.0, 48.2, 569.6, 45.0, 420.8, 45.0, 272.1, 45.0, 271.1, 46.8};
        vector<float> m_leftOuterRail = {831.0, 61.9, 831.0, 66.0, 847.3, 66.1, 863.5, 66.2, 914.5, 66.9, 965.5, 67.7, 976.3, 69.9, 987.1, 72.1, 996.2, 75.1, 1005.3, 78.0, 1013.8, 82.0, 1022.4, 86.1, 1032.4, 92.7, 1042.5, 99.4, 1053.0, 109.9, 1063.6, 120.5, 1069.2, 129.0, 1074.8, 137.5, 1079.4, 147.6, 1084.0, 157.7, 1086.1, 167.6, 1088.2, 177.5, 1089.0, 182.5, 1089.9, 187.5, 1089.9, 206.6, 1090.0, 225.6, 1088.9, 231.6, 1087.8, 237.5, 1087.1, 238.5, 1086.4, 239.5, 1085.0, 244.0, 1083.7, 248.5, 1080.9, 254.1, 1078.2, 259.7, 1070.2, 269.6, 1062.2, 279.5, 1053.7, 288.1, 1045.2, 296.8, 1024.7, 313.9, 1004.1, 331.0, 985.8, 345.3, 967.5, 359.5, 948.3, 373.9, 929.0, 388.2, 929.0, 390.8, 929.0, 393.3, 907.8, 392.6, 886.6, 391.9, 885.5, 354.2, 884.7, 317.0, 924.8, 317.0, 964.8, 317.0, 966.0, 318.5, 967.2, 320.0, 966.7, 321.3, 966.2, 322.7, 952.0, 333.1, 937.8, 343.5, 933.6, 346.5, 929.4, 349.5, 920.6, 356.3, 911.9, 363.2, 912.2, 365.8, 912.5, 368.5, 914.2, 368.8, 915.9, 369.1, 923.8, 363.6, 931.7, 358.0, 938.1, 352.3, 944.5, 346.6, 961.7, 333.8, 978.9, 321.1, 979.6, 318.4, 980.3, 315.8, 978.9, 314.5, 977.5, 313.1, 899.0, 312.0, 820.5, 310.9, 806.5, 306.5, 792.5, 302.1, 776.5, 293.9, 760.5, 285.8, 753.5, 282.2, 746.5, 278.7, 739.9, 273.9, 733.4, 269.0, 709.4, 243.8, 685.5, 218.6, 624.7, 154.5, 563.8, 90.5, 558.5, 85.2, 553.2, 80.0, 397.1, 80.0, 241.1, 80.0, 240.1, 81.8, 239.2, 83.6, 240.1, 85.3, 241.1, 87.0, 395.4, 87.0, 549.6, 87.0, 622.0, 162.5, 694.3, 238.0, 702.3, 245.2, 709.5, 253.2, 710.5, 254.9, 711.5, 256.6, 713.5, 259.2, 715.6, 261.7, 717.8, 262.4, 720.0, 263.1, 722.7, 266.8, 725.4, 270.5, 729.9, 275.0, 734.5, 279.6, 744.5, 285.1, 754.5, 290.6, 765.0, 295.7, 775.5, 300.9, 783.0, 304.0, 790.5, 307.2, 800.5, 311.2, 810.5, 315.2, 839.0, 316.0, 867.5, 316.8, 871.6, 316.9, 875.7, 317.0, 876.5, 358.0, 877.2, 398.9, 878.4, 399.9, 879.6, 400.9, 919.8, 402.0, 960.1, 403.2, 961.5, 402.0, 963.0, 400.8, 963.0, 388.0, 963.0, 375.3, 1005.0, 340.5, 1047.0, 305.8, 1047.0, 304.5, 1047.0, 303.2, 1054.8, 296.3, 1062.7, 289.5, 1065.1, 287.4, 1067.5, 285.2, 1072.4, 280.0, 1077.2, 274.7, 1082.9, 265.8, 1088.5, 256.9, 1090.7, 252.7, 1092.9, 248.5, 1095.6, 240.1, 1098.3, 231.8, 1097.7, 201.1, 1097.0, 170.5, 1095.5, 164.7, 1093.9, 159.0, 1086.4, 143.7, 1079.0, 128.5, 1072.6, 120.0, 1066.2, 111.5, 1056.4, 102.0, 1046.5, 92.4, 1037.1, 86.2, 1027.7, 79.9, 1018.6, 75.5, 1009.5, 71.2, 1000.6, 68.1, 991.7, 65.0, 979.6, 62.5, 967.5, 60.1, 956.5, 59.6, 945.5, 59.0, 888.3, 58.4, 831.0, 57.9, 831.0, 61.9};
        vector<float> m_rightOuterRail = {1063.5, 595.1, 1057.7, 603.1, 1047.0, 613.4, 1036.3, 623.7, 1024.9, 631.3, 1013.5, 638.9, 1002.9, 643.9, 992.4, 649.0, 980.4, 652.9, 968.5, 656.8, 957.5, 658.9, 946.5, 661.0, 937.5, 662.0, 928.5, 663.0, 667.8, 663.0, 407.2, 663.0, 375.9, 641.5, 344.7, 620.0, 290.6, 620.2, 236.5, 620.5, 236.5, 623.5, 236.5, 626.5, 288.7, 626.8, 340.9, 627.0, 372.7, 649.0, 404.5, 671.0, 667.0, 671.0, 929.5, 671.0, 938.5, 670.0, 947.5, 669.0, 958.5, 666.9, 969.5, 664.8, 983.0, 660.4, 996.5, 656.0, 1007.5, 650.6, 1018.5, 645.2, 1027.5, 639.3, 1036.5, 633.3, 1043.0, 628.0, 1049.5, 622.6, 1056.9, 615.1, 1064.2, 607.5, 1070.1, 599.7, 1076.0, 591.9, 1072.7, 588.8, 1069.4, 587.2, 1063.5, 595.1};
        vector<float> m_rightInnerRail = {660.8, 433.7, 655.4, 437.5, 627.7, 457.4, 600.0, 477.3, 599.5, 479.1, 598.9, 480.9, 600.0, 482.9, 601.0, 484.9, 633.1, 529.2, 665.2, 573.5, 666.8, 574.7, 668.4, 576.0, 669.7, 576.0, 671.0, 576.0, 681.8, 568.6, 692.7, 561.2, 695.5, 559.7, 698.4, 558.2, 720.7, 579.9, 742.9, 601.5, 745.5, 602.4, 748.0, 603.4, 748.0, 608.4, 748.0, 613.5, 744.9, 618.8, 741.9, 624.1, 739.4, 625.0, 736.9, 626.0, 574.2, 626.0, 411.5, 626.0, 381.8, 605.5, 352.1, 585.0, 296.3, 585.2, 240.5, 585.5, 240.5, 588.5, 240.5, 591.5, 294.4, 591.8, 348.2, 592.0, 378.7, 613.0, 409.2, 634.0, 574.6, 634.0, 739.9, 634.0, 743.7, 631.9, 747.5, 629.8, 748.8, 628.7, 750.2, 627.6, 752.6, 622.8, 755.0, 618.1, 755.0, 611.9, 755.0, 605.7, 752.8, 599.8, 750.7, 593.9, 730.1, 574.1, 709.5, 554.3, 704.2, 549.6, 698.9, 545.0, 696.7, 545.0, 694.5, 545.0, 682.5, 554.9, 670.5, 564.8, 669.9, 564.1, 669.2, 563.5, 640.1, 523.2, 611.0, 483.0, 610.7, 482.1, 610.5, 481.2, 638.5, 461.0, 666.5, 440.8, 667.6, 440.4, 668.6, 439.9, 713.5, 462.0, 758.4, 484.1, 752.5, 498.0, 745.9, 511.1, 738.9, 504.8, 731.8, 498.5, 726.8, 494.2, 721.8, 490.0, 720.0, 490.0, 718.1, 490.0, 716.6, 491.6, 715.0, 493.1, 715.0, 494.9, 715.0, 496.7, 740.8, 519.5, 766.5, 542.4, 795.1, 570.4, 823.7, 598.5, 829.6, 603.1, 835.5, 607.7, 841.6, 611.8, 847.6, 615.9, 856.1, 620.4, 864.5, 624.9, 875.5, 628.7, 886.5, 632.5, 909.9, 632.8, 933.4, 633.1, 939.9, 632.0, 946.5, 630.9, 956.6, 627.5, 966.8, 624.1, 976.1, 619.4, 985.5, 614.7, 995.9, 607.7, 1006.3, 600.6, 1017.8, 589.6, 1029.3, 578.5, 1034.2, 572.6, 1039.1, 566.8, 1035.8, 564.5, 1032.5, 562.2, 1029.6, 565.9, 1026.7, 569.5, 1015.6, 580.6, 1004.5, 591.6, 997.0, 597.2, 989.4, 602.8, 983.0, 606.9, 976.5, 611.0, 972.5, 612.9, 968.5, 614.9, 958.5, 618.6, 948.5, 622.3, 942.3, 624.6, 936.1, 626.9, 935.5, 626.0, 934.9, 625.0, 913.1, 625.0, 891.2, 625.0, 882.4, 622.4, 873.5, 619.9, 864.1, 615.4, 854.7, 611.0, 846.4, 605.5, 838.2, 600.0, 827.3, 589.3, 816.4, 578.5, 813.0, 574.5, 809.5, 570.5, 803.8, 566.5, 798.2, 562.6, 797.7, 560.0, 797.1, 557.5, 775.1, 537.6, 753.0, 517.7, 761.5, 499.9, 770.1, 482.8, 769.5, 481.1, 769.0, 479.3, 718.7, 454.6, 668.5, 429.9, 667.4, 430.0, 666.3, 430.0, 660.8, 433.7};
        vector<vector<float>> m_layer2ShapeData = {
            m_leftInnerRail, m_leftOuterRail, m_rightOuterRail, m_rightInnerRail
        };

        // All the layers
        vector<vector<vector<float>>> m_layerData = {m_launchTubeLayer, m_layer1ShapeData, m_layer2ShapeData};
};
#endif