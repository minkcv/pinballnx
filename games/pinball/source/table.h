#ifndef TABLE_H_
#define TABLE_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace c2d;

class Table {
    public:
        Table(C2DRenderer* renderer, b2World& world);
    private:
        void loadShape(float* points, int numPoints, C2DRenderer* renderer, b2World& world);
        float m_leftWall[602] = {0.1, 144.2, 0.2, 288.5, 1.5, 285.5, 2.8, 282.5, 42.3, 168.5, 81.8, 54.5, 89.0, 35.2, 96.2, 16.0, 192.6, 16.0, 289.0, 16.0, 305.0, 32.0, 321.0, 48.0, 345.0, 48.0, 369.1, 48.0, 374.0, 53.0, 378.9, 58.0, 379.5, 58.0, 380.1, 58.0, 391.0, 69.0, 402.0, 80.1, 497.8, 79.8, 593.5, 79.5, 599.0, 77.3, 604.5, 75.0, 606.0, 75.0, 607.5, 75.0, 616.5, 71.6, 625.5, 68.2, 633.0, 66.1, 640.5, 63.9, 643.5, 63.0, 646.5, 62.2, 657.0, 60.5, 667.5, 58.9, 672.9, 57.9, 678.3, 57.0, 698.8, 57.0, 719.4, 57.0, 722.7, 58.2, 726.0, 59.4, 726.0, 60.1, 726.0, 60.9, 727.3, 62.2, 728.5, 63.5, 729.9, 68.0, 731.2, 72.5, 731.7, 77.3, 732.2, 82.2, 730.9, 88.1, 729.6, 94.0, 728.8, 94.0, 728.0, 94.0, 728.0, 95.5, 728.0, 96.9, 725.5, 99.4, 723.0, 101.9, 723.0, 102.9, 723.0, 104.0, 720.3, 104.6, 717.5, 105.1, 713.3, 106.7, 709.0, 108.2, 709.0, 109.1, 709.0, 110.0, 706.5, 110.0, 704.0, 110.0, 704.0, 110.8, 704.0, 111.5, 696.8, 114.1, 689.5, 116.7, 684.0, 118.3, 678.5, 119.9, 675.8, 120.5, 673.1, 121.0, 671.8, 122.4, 670.4, 123.7, 668.2, 124.4, 665.9, 125.2, 666.6, 127.2, 667.2, 129.3, 670.6, 132.6, 673.9, 136.0, 690.6, 136.0, 707.2, 136.0, 718.8, 134.1, 730.5, 132.1, 739.3, 131.0, 748.1, 129.9, 753.3, 127.9, 758.5, 125.8, 759.0, 125.1, 759.5, 124.4, 762.8, 123.1, 766.0, 121.8, 766.0, 120.9, 766.0, 120.1, 771.8, 119.0, 777.5, 117.9, 787.0, 114.6, 796.5, 111.2, 801.3, 110.0, 806.0, 108.7, 806.0, 108.0, 806.0, 107.3, 813.3, 104.5, 820.5, 101.7, 821.0, 100.9, 821.5, 100.1, 834.4, 95.1, 847.3, 90.0, 849.1, 90.0, 850.9, 90.0, 853.7, 88.8, 856.5, 87.5, 857.0, 87.0, 857.5, 86.5, 862.0, 85.2, 866.5, 83.9, 870.3, 82.9, 874.0, 82.0, 878.3, 80.9, 882.5, 79.8, 890.5, 78.4, 898.5, 77.0, 904.5, 76.0, 910.5, 75.0, 917.5, 74.0, 924.5, 73.1, 930.0, 71.9, 935.5, 70.7, 961.5, 71.4, 987.5, 72.0, 996.0, 73.6, 1004.5, 75.2, 1009.9, 76.6, 1015.4, 78.0, 1015.9, 78.8, 1016.5, 79.7, 1021.1, 81.4, 1025.7, 83.1, 1027.1, 85.2, 1028.5, 87.2, 1030.3, 89.2, 1032.0, 91.3, 1032.0, 92.6, 1032.0, 93.8, 1033.1, 94.2, 1034.1, 94.5, 1034.7, 102.1, 1035.3, 109.7, 1034.6, 113.2, 1034.0, 116.7, 1032.2, 118.7, 1030.5, 120.7, 1025.6, 121.3, 1020.7, 122.0, 1015.1, 120.4, 1009.5, 118.7, 1005.5, 117.2, 1001.5, 115.7, 987.7, 115.2, 973.8, 114.7, 970.2, 115.8, 966.5, 116.9, 960.0, 118.5, 953.5, 120.1, 947.2, 121.1, 940.9, 122.1, 925.2, 128.1, 909.6, 134.0, 909.0, 134.8, 908.5, 135.6, 905.3, 136.9, 902.0, 138.2, 902.0, 139.1, 902.0, 140.0, 900.9, 140.0, 899.8, 140.0, 897.2, 143.0, 894.5, 145.9, 892.0, 149.0, 889.5, 152.1, 888.3, 153.5, 887.0, 154.9, 887.0, 157.4, 887.0, 160.0, 886.0, 160.0, 885.0, 160.0, 885.0, 163.7, 885.0, 167.5, 886.4, 174.5, 887.8, 181.5, 889.0, 184.7, 890.2, 187.9, 892.0, 188.5, 893.8, 189.1, 896.1, 191.1, 898.5, 193.1, 906.0, 192.8, 913.5, 192.4, 920.0, 190.0, 926.5, 187.7, 932.6, 185.4, 938.8, 183.1, 947.6, 181.8, 956.5, 180.6, 981.5, 180.6, 1006.5, 180.6, 1014.0, 181.8, 1021.5, 182.9, 1027.0, 184.2, 1032.5, 185.4, 1033.7, 186.6, 1035.0, 187.8, 1040.2, 189.5, 1045.5, 191.2, 1051.0, 194.3, 1056.5, 197.4, 1057.0, 198.0, 1057.5, 198.7, 1059.8, 199.4, 1062.0, 200.1, 1062.0, 201.0, 1062.0, 201.8, 1065.8, 204.1, 1069.5, 206.4, 1070.8, 207.7, 1072.1, 209.0, 1073.1, 209.0, 1074.1, 209.0, 1075.3, 210.0, 1076.5, 211.0, 1078.9, 213.0, 1081.3, 215.0, 1082.6, 215.0, 1083.9, 215.0, 1084.5, 217.0, 1085.1, 219.0, 1086.2, 219.0, 1087.3, 219.0, 1089.0, 221.0, 1090.8, 223.1, 1093.9, 226.9, 1097.0, 230.7, 1102.0, 239.0, 1107.1, 247.4, 1107.8, 248.0, 1108.6, 248.5, 1109.9, 251.7, 1111.2, 255.0, 1112.1, 255.0, 1113.0, 255.0, 1113.0, 256.1, 1113.0, 257.3, 1117.0, 265.6, 1121.0, 274.0, 1124.9, 283.8, 1128.9, 293.7, 1130.5, 304.1, 1132.0, 314.5, 1133.4, 325.5, 1134.8, 336.5, 1135.5, 429.0, 1136.1, 521.5, 1135.0, 531.0, 1134.0, 540.5, 1131.9, 550.9, 1129.8, 561.3, 1126.3, 571.9, 1122.9, 582.5, 1117.0, 594.8, 1111.1, 607.1, 1105.4, 615.8, 1099.8, 624.5, 1094.2, 631.5, 1088.6, 638.5, 1082.5, 644.9, 1076.5, 651.3, 1067.5, 658.8, 1058.5, 666.4, 1048.9, 672.7, 1039.2, 679.0, 1026.9, 684.9, 1014.5, 690.9, 1003.9, 694.3, 993.3, 697.8, 982.9, 699.9, 972.5, 702.0, 963.5, 703.0, 954.5, 704.0, 477.3, 704.0, -3.41060513165e-13, 704.0, -3.41060513165e-13, 712.0, -3.41060513165e-13, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 360.0, 1152.0, -2.27373675443e-13, 576.0, -2.27373675443e-13, -4.54747350886e-13, -2.27373675443e-13, 0.0999999999995, 144.2};
        float m_innerWall[150] = {0.1, 527.7, 0.0, 672.0, 426.0, 672.0, 852.1, 672.0, 856.0, 670.0, 860.0, 668.0, 862.0, 664.0, 864.0, 660.1, 864.0, 656.0, 864.0, 651.9, 862.1, 648.2, 860.2, 644.5, 857.6, 642.3, 855.0, 640.0, 855.0, 638.5, 855.0, 637.0, 854.1, 637.0, 853.2, 637.0, 852.0, 634.0, 850.8, 631.0, 849.9, 631.0, 849.0, 631.0, 849.0, 629.7, 849.0, 628.3, 847.0, 626.0, 845.0, 623.7, 845.0, 622.3, 845.0, 621.0, 843.6, 621.0, 842.2, 621.0, 841.7, 617.8, 841.1, 614.5, 840.2, 610.5, 839.2, 606.5, 837.8, 601.5, 836.4, 596.5, 834.5, 594.2, 832.6, 592.0, 825.9, 592.0, 819.3, 592.0, 817.8, 593.7, 816.2, 595.5, 814.6, 598.7, 813.0, 601.9, 813.0, 611.9, 813.0, 622.0, 811.4, 626.0, 809.8, 630.0, 809.0, 630.0, 808.1, 630.0, 807.5, 631.9, 806.9, 633.9, 804.7, 634.6, 802.6, 635.3, 801.3, 636.4, 800.1, 637.5, 798.6, 638.7, 797.1, 640.0, 598.5, 640.0, 400.0, 640.0, 400.0, 632.0, 400.0, 624.0, 360.5, 624.0, 321.0, 624.0, 305.0, 640.0, 289.0, 656.0, 192.6, 656.0, 96.2, 656.0, 94.7, 651.7, 93.2, 647.5, 48.0, 518.5, 2.8, 389.5, 1.5, 386.5, 0.2, 383.5, 0.0999999999999, 527.7};
        float m_upperWall[490] = {982.5, 227.6, 981.5, 228.0, 971.0, 230.0, 960.5, 232.1, 951.0, 234.0, 941.5, 235.9, 936.5, 237.4, 931.5, 238.8, 922.5, 242.0, 913.5, 245.1, 901.0, 250.0, 888.5, 254.8, 882.0, 256.5, 875.5, 258.2, 868.0, 260.7, 860.5, 263.2, 855.0, 264.6, 849.5, 266.1, 846.1, 267.7, 842.7, 269.3, 835.9, 270.7, 829.1, 272.1, 823.6, 274.5, 818.2, 276.9, 809.8, 279.0, 801.5, 281.2, 797.5, 282.1, 793.5, 283.0, 786.6, 283.9, 779.7, 284.8, 779.1, 285.8, 778.5, 286.8, 773.5, 287.5, 768.5, 288.1, 762.0, 289.5, 755.5, 290.9, 749.5, 292.1, 743.5, 293.4, 741.8, 295.3, 740.0, 297.3, 740.0, 301.0, 740.0, 304.8, 741.6, 305.4, 743.2, 306.0, 750.5, 306.0, 757.8, 306.0, 762.2, 304.1, 766.5, 302.3, 780.0, 299.2, 793.5, 296.0, 803.3, 294.1, 813.1, 292.1, 819.0, 293.2, 824.9, 294.3, 826.1, 297.4, 827.4, 300.5, 828.4, 301.2, 829.4, 301.9, 829.8, 314.2, 830.2, 326.6, 828.8, 328.1, 827.4, 329.5, 826.1, 332.7, 824.8, 336.0, 823.8, 336.0, 822.9, 336.0, 821.5, 337.2, 820.1, 338.5, 818.8, 339.5, 817.5, 340.5, 810.7, 343.4, 803.9, 346.3, 802.7, 347.4, 801.5, 348.6, 790.5, 352.9, 779.5, 357.3, 779.0, 357.9, 778.5, 358.5, 774.6, 360.5, 770.6, 362.5, 769.6, 363.6, 768.5, 364.6, 764.1, 366.3, 759.8, 368.1, 758.4, 369.4, 757.0, 370.8, 755.8, 371.2, 754.5, 371.7, 754.7, 376.9, 754.9, 382.1, 756.5, 383.6, 758.0, 385.1, 758.0, 386.1, 758.0, 387.0, 759.3, 387.0, 760.5, 387.1, 763.0, 390.1, 765.5, 393.1, 769.8, 397.6, 774.1, 402.0, 775.1, 402.0, 776.2, 402.0, 780.6, 406.5, 784.9, 411.0, 785.5, 411.0, 786.1, 411.0, 787.5, 412.2, 788.9, 413.5, 790.2, 414.6, 791.5, 415.6, 793.3, 416.3, 795.0, 416.9, 795.0, 418.0, 795.0, 419.0, 796.0, 419.0, 797.1, 419.0, 798.6, 420.2, 800.0, 421.5, 803.0, 424.0, 806.0, 426.5, 807.2, 427.7, 808.5, 428.9, 809.8, 430.5, 811.1, 432.0, 816.9, 432.0, 822.7, 432.0, 826.2, 428.7, 829.7, 425.5, 830.3, 422.5, 830.9, 419.5, 831.9, 415.5, 832.9, 411.5, 834.4, 405.5, 836.0, 399.5, 838.1, 392.5, 840.1, 385.5, 842.2, 379.5, 844.3, 373.5, 845.0, 368.5, 845.8, 363.5, 846.5, 361.2, 847.2, 359.0, 848.0, 359.0, 848.7, 359.0, 850.4, 354.5, 852.2, 350.0, 853.1, 350.0, 854.0, 350.0, 854.0, 348.9, 854.0, 347.9, 855.3, 346.5, 856.5, 345.1, 859.0, 342.0, 861.5, 338.9, 865.8, 334.4, 870.1, 330.0, 871.0, 330.0, 872.0, 330.0, 872.0, 328.7, 872.0, 327.5, 875.3, 325.3, 878.5, 323.1, 881.5, 321.8, 884.5, 320.5, 885.7, 319.5, 886.9, 318.5, 888.3, 317.4, 889.7, 316.2, 891.8, 315.6, 894.0, 314.9, 895.2, 313.6, 896.5, 312.4, 906.0, 308.6, 915.5, 304.7, 919.5, 303.8, 923.5, 302.9, 931.9, 301.5, 940.4, 300.1, 947.8, 298.5, 955.2, 297.0, 968.4, 297.0, 981.6, 297.0, 986.5, 298.4, 991.5, 299.8, 997.4, 301.9, 1003.2, 304.1, 1004.6, 305.3, 1005.9, 306.5, 1007.4, 307.7, 1008.9, 309.0, 1009.9, 309.0, 1010.8, 309.0, 1014.0, 312.0, 1017.2, 315.0, 1018.4, 315.0, 1019.5, 315.0, 1022.5, 318.6, 1025.5, 322.2, 1038.2, 335.0, 1050.8, 347.8, 1052.8, 348.9, 1054.9, 350.0, 1058.4, 350.0, 1061.9, 350.0, 1064.5, 348.8, 1067.0, 347.7, 1067.0, 346.8, 1067.0, 345.8, 1071.2, 341.8, 1075.5, 337.7, 1076.2, 332.1, 1076.8, 326.5, 1077.9, 322.0, 1078.9, 317.5, 1079.0, 303.3, 1079.0, 289.1, 1077.9, 284.0, 1076.8, 278.9, 1074.5, 276.6, 1072.1, 274.2, 1070.5, 268.6, 1068.9, 263.0, 1068.1, 263.0, 1067.2, 263.0, 1066.0, 260.0, 1064.8, 257.0, 1063.9, 257.0, 1063.0, 257.0, 1063.0, 255.9, 1063.0, 254.8, 1056.5, 248.7, 1050.1, 242.5, 1046.8, 239.6, 1043.5, 236.7, 1039.0, 234.7, 1034.5, 232.7, 1034.0, 232.0, 1033.5, 231.3, 1031.0, 230.8, 1028.5, 230.2, 1022.5, 228.6, 1016.6, 227.0, 1000.0, 227.1, 983.5, 227.2, 982.5, 227.6};
};

#endif