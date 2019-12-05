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
        vector<float> m_underOuter = {693.0, 6.9, 691.5, 7.8, 682.4, 11.0, 673.2, 14.2, 665.9, 17.9, 658.5, 21.7, 649.9, 26.2, 641.2, 30.7, 636.4, 34.1, 631.5, 37.4, 626.0, 42.0, 620.5, 46.6, 615.8, 49.6, 611.1, 52.5, 607.6, 60.0, 604.1, 67.5, 603.4, 72.0, 602.8, 76.5, 590.8, 110.5, 578.8, 144.5, 577.4, 146.7, 576.0, 148.9, 576.0, 150.4, 576.0, 151.8, 574.5, 154.6, 573.0, 157.5, 442.8, 158.0, 312.5, 158.5, 312.5, 178.5, 312.5, 198.5, 350.1, 199.0, 387.8, 199.5, 374.4, 221.0, 361.1, 242.5, 291.8, 243.0, 222.5, 243.5, 222.5, 332.0, 222.5, 420.5, 297.3, 421.0, 372.1, 421.5, 379.5, 433.5, 387.0, 445.5, 388.6, 447.7, 390.3, 450.0, 421.1, 450.0, 452.0, 450.0, 452.0, 464.5, 452.0, 479.0, 418.8, 479.2, 385.5, 479.5, 385.5, 499.0, 385.5, 518.5, 460.1, 518.8, 534.7, 519.0, 537.2, 517.0, 539.7, 515.1, 549.4, 499.6, 559.1, 484.1, 597.4, 483.8, 635.8, 483.5, 637.9, 481.0, 640.0, 478.5, 656.7, 452.0, 673.4, 425.5, 678.5, 418.0, 683.7, 410.5, 690.8, 398.9, 698.0, 387.4, 698.0, 318.9, 698.0, 250.5, 668.6, 203.8, 639.3, 157.1, 639.8, 151.8, 640.2, 146.5, 642.1, 138.2, 644.0, 129.9, 644.0, 127.2, 644.0, 124.4, 645.6, 118.5, 647.2, 112.5, 648.1, 105.5, 649.0, 98.5, 652.1, 87.7, 655.3, 76.9, 661.3, 72.4, 667.3, 67.8, 678.9, 61.7, 690.5, 55.7, 696.5, 54.3, 702.5, 53.0, 707.5, 51.8, 712.5, 50.6, 931.4, 50.1, 1150.3, 49.5, 1151.3, 47.8, 1152.4, 46.2, 1151.1, 44.6, 1149.8, 43.0, 923.1, 43.0, 696.3, 43.0, 676.3, 52.9, 656.3, 62.8, 652.5, 67.4, 648.7, 72.1, 645.8, 80.8, 643.0, 89.5, 641.0, 99.5, 639.0, 109.5, 634.4, 133.3, 629.8, 157.0, 637.1, 168.8, 644.4, 180.5, 667.7, 217.5, 691.0, 254.5, 691.0, 319.0, 691.0, 383.5, 683.6, 395.0, 676.2, 406.5, 654.6, 440.5, 633.1, 474.6, 630.7, 476.8, 628.4, 479.0, 590.4, 479.0, 552.3, 479.0, 546.2, 489.3, 540.1, 499.5, 535.8, 506.0, 531.5, 512.5, 460.8, 512.8, 390.0, 513.0, 390.0, 498.5, 390.0, 484.0, 448.3, 483.8, 506.5, 483.5, 506.5, 481.0, 506.5, 478.5, 481.8, 478.2, 457.0, 478.0, 457.0, 464.0, 457.0, 450.0, 532.6, 449.8, 608.3, 449.5, 609.3, 447.8, 610.4, 446.2, 609.1, 444.6, 607.8, 443.0, 520.8, 443.0, 433.8, 443.0, 419.1, 441.9, 404.5, 440.8, 398.9, 437.8, 393.3, 434.9, 387.8, 429.2, 382.3, 423.5, 376.7, 414.3, 371.1, 405.2, 369.6, 401.5, 368.0, 397.8, 366.3, 398.2, 364.5, 398.5, 364.0, 406.0, 363.5, 413.5, 296.3, 413.8, 229.0, 414.0, 229.0, 332.0, 229.0, 250.0, 297.4, 250.0, 365.9, 250.0, 382.5, 223.3, 399.1, 196.6, 398.8, 194.6, 398.5, 192.5, 358.8, 192.2, 319.0, 192.0, 319.0, 178.5, 319.0, 165.0, 404.8, 165.0, 490.6, 165.0, 523.5, 189.5, 556.4, 214.0, 558.8, 214.0, 561.1, 214.0, 562.4, 210.7, 563.8, 207.5, 572.5, 183.0, 581.2, 158.5, 584.0, 152.0, 586.8, 145.5, 597.4, 115.8, 608.0, 86.1, 611.5, 76.8, 615.1, 67.5, 617.2, 63.5, 619.3, 59.5, 623.9, 54.7, 628.5, 50.0, 659.0, 34.1, 689.5, 18.2, 694.0, 15.9, 698.5, 13.5, 923.4, 13.0, 1148.3, 12.5, 1149.3, 10.8, 1150.4, 9.2, 1149.1, 7.6, 1147.8, 6.0, 921.1, 6.0, 694.5, 6.1, 693.0, 6.9};
        vector<float> m_under1 = {440.0, 378.2, 439.0, 380.5, 434.4, 396.2, 429.9, 411.9, 430.2, 414.2, 430.5, 416.5, 491.5, 416.5, 552.5, 416.5, 552.8, 413.8, 553.1, 411.1, 551.3, 410.2, 549.5, 409.3, 497.9, 392.6, 446.4, 376.0, 443.7, 376.0, 441.0, 376.0, 440.0, 378.2};
        vector<float> m_under2 = {632.1, 155.4, 630.9, 156.9, 621.8, 219.7, 612.8, 282.5, 613.8, 284.0, 614.7, 285.5, 616.3, 285.8, 617.8, 286.1, 647.7, 249.3, 677.6, 212.5, 679.9, 209.2, 682.2, 206.0, 681.8, 205.0, 681.5, 203.9, 658.6, 179.0, 635.8, 154.0, 634.5, 154.0, 633.2, 154.0, 632.1, 155.4};
        vector<vector<float>> m_underLayer = {
            m_underOuter, m_under1/*, m_under2*/
        };

        // Launch tube layer
        vector<float> m_tubeLeft = {0.0, 540.8, 0.0, 675.0, 210.3, 675.0, 420.7, 675.0, 423.0, 672.5, 425.3, 670.0, 418.5, 655.4, 411.6, 640.8, 397.1, 630.4, 382.5, 620.1, 377.5, 620.0, 372.5, 620.0, 355.5, 637.0, 338.5, 654.0, 174.3, 654.0, 10.0, 654.0, 10.0, 641.0, 10.0, 628.0, 42.3, 628.0, 74.7, 628.0, 76.5, 626.0, 78.3, 624.1, 39.5, 515.8, 0.8, 407.5, 3.97459842816e-14, 540.8};
        vector<float> m_tubeLeftUpper = {988.0, 542.3, 977.5, 552.6, 942.0, 584.0, 906.5, 615.4, 897.0, 621.4, 887.5, 627.4, 873.5, 634.6, 859.5, 641.8, 850.5, 645.6, 841.5, 649.3, 830.0, 653.2, 818.5, 657.1, 803.5, 659.1, 788.5, 661.0, 696.5, 661.0, 604.5, 661.0, 588.7, 658.5, 573.0, 656.1, 561.2, 653.4, 549.5, 650.8, 538.2, 647.4, 526.9, 643.9, 519.0, 640.0, 511.1, 636.0, 498.8, 628.0, 486.5, 620.0, 461.3, 620.0, 436.1, 620.0, 435.5, 621.9, 434.9, 623.8, 436.2, 626.6, 437.4, 629.5, 444.0, 641.5, 450.6, 653.5, 454.1, 660.4, 457.5, 667.2, 460.8, 671.1, 464.2, 675.0, 705.3, 674.7, 946.5, 674.5, 958.6, 671.8, 970.6, 669.1, 980.6, 665.6, 990.5, 662.1, 997.5, 659.0, 1004.5, 655.9, 1013.3, 650.8, 1022.1, 645.8, 1030.3, 639.7, 1038.5, 633.6, 1048.9, 623.6, 1059.2, 613.5, 1065.2, 606.2, 1071.2, 598.9, 1067.9, 595.4, 1064.6, 592.0, 1058.3, 598.7, 1053.2, 605.5, 1038.8, 619.5, 1024.5, 633.5, 1013.2, 639.9, 1001.8, 646.3, 992.5, 650.1, 983.1, 653.9, 972.3, 656.9, 961.5, 659.9, 951.2, 660.9, 940.9, 662.0, 928.0, 662.0, 915.0, 662.0, 915.0, 646.0, 915.0, 630.0, 920.3, 630.0, 925.6, 630.0, 935.1, 628.4, 944.5, 626.8, 954.0, 623.8, 963.5, 620.8, 973.7, 616.0, 983.9, 611.2, 992.7, 605.4, 1001.5, 599.7, 1007.5, 595.2, 1013.5, 590.6, 1025.3, 579.1, 1037.0, 567.7, 1037.0, 566.5, 1037.0, 565.4, 1019.6, 548.7, 1002.2, 532.0, 1000.3, 532.0, 998.5, 532.0, 988.0, 542.3};
        vector<float> m_tubeRight = {0, 132.7, 0, 265.3, 39.5, 156.2, 78.3, 47.9, 76.5, 46.0, 74.7, 44.0, 42.3, 44.0, 10.0, 44.0, 10.0, 31.0, 10.0, 18.0, 173.5, 18.0, 337.0, 18.0, 366.0, 47.0, 395.0, 76.0, 401.0, 76.0, 407.0, 76.0, 414.7, 70.4, 422.5, 64.8, 430.6, 59.9, 438.7, 55.0, 453.1, 48.1, 467.5, 41.1, 479.5, 36.7, 491.5, 32.3, 505.0, 28.7, 518.5, 25.1, 528.5, 23.1, 538.5, 21.1, 551.5, 19.6, 564.5, 18.0, 584.2, 17.0, 603.8, 16.0, 614.4, 16.0, 625.0, 16.0, 625.0, 31.3, 625.0, 46.6, 617.3, 48.4, 609.5, 50.2, 603.8, 52.5, 598.2, 54.8, 593.5, 58.0, 588.9, 61.2, 589.2, 62.8, 589.5, 64.3, 592.5, 65.3, 595.5, 66.2, 598.6, 69.2, 601.7, 72.1, 602.8, 75.8, 603.8, 79.5, 604.5, 84.7, 605.2, 90.0, 606.8, 90.0, 608.3, 90.0, 614.9, 87.1, 621.5, 84.1, 632.0, 79.7, 642.5, 75.2, 669.5, 63.5, 696.5, 51.8, 703.0, 49.0, 709.5, 46.2, 709.5, 44.8, 709.5, 43.5, 680.3, 43.2, 651.0, 43.0, 651.0, 28.5, 651.0, 14.0, 872.3, 14.0, 1093.6, 14.0, 1094.8, 15.2, 1096.0, 16.4, 1096.0, 28.0, 1096.0, 39.6, 1094.8, 40.8, 1093.6, 42.0, 1077.4, 42.0, 1061.1, 42.0, 1060.4, 43.2, 1059.6, 44.4, 1060.7, 44.7, 1061.8, 45.1, 1070.7, 50.9, 1079.5, 56.8, 1087.6, 63.8, 1095.7, 70.8, 1102.2, 78.7, 1108.7, 86.5, 1113.5, 93.8, 1118.2, 101.2, 1121.5, 108.3, 1124.8, 115.5, 1127.3, 124.5, 1129.9, 133.5, 1132.7, 146.0, 1135.5, 158.5, 1135.8, 339.0, 1136.1, 519.5, 1135.0, 530.5, 1133.9, 541.5, 1131.5, 552.5, 1129.2, 563.5, 1126.0, 573.0, 1122.9, 582.5, 1117.0, 594.8, 1111.1, 607.1, 1105.4, 615.8, 1099.8, 624.5, 1094.2, 631.5, 1088.6, 638.5, 1082.5, 644.9, 1076.5, 651.3, 1067.5, 658.8, 1058.5, 666.4, 1048.9, 672.7, 1039.2, 679.0, 1026.9, 684.9, 1014.5, 690.9, 1005.0, 694.0, 995.5, 697.2, 984.5, 699.8, 973.5, 702.4, 486.8, 702.7, 0, 703.0, 0, 711.5, 0, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 360.0, 1152.0, 0, 576.0, 0, 0, 0, 0, 132.7};
        vector<float> m_tubeRightLaunch = {1136.0, 402.7, 1136.0, 522.5, 1135.0, 531.5, 1134.0, 540.5, 1131.9, 550.9, 1129.8, 561.3, 1126.3, 571.9, 1122.9, 582.5, 1116.9, 594.9, 1111.0, 607.2, 1104.7, 616.9, 1098.4, 626.5, 1090.8, 635.5, 1083.3, 644.5, 1076.9, 650.5, 1070.5, 656.6, 1063.5, 662.2, 1056.5, 667.8, 1047.8, 673.4, 1039.1, 679.1, 1026.8, 685.0, 1014.5, 690.9, 1005.0, 694.0, 995.5, 697.2, 984.5, 699.8, 973.5, 702.4, 486.7, 702.7, 0.0, 703.0, 0.0, 711.5, 0.0, 720.0, 576.0, 720.0, 1152.0, 720.0, 1152.0, 501.5, 1152.0, 283.0, 1144.0, 283.0, 1136.0, 283.0, 1136.0, 402.7};
        vector<vector<float>> m_launchTubeLayer = {
            m_tubeLeft, m_tubeRightLaunch, m_tubeLeftUpper
        };

        // Main table layer
        vector<float> m_upperWall = {859.0, 44.1, 854.5, 45.0, 849.1, 46.1, 843.8, 47.2, 822.1, 58.0, 800.5, 68.8, 766.0, 87.8, 731.5, 106.8, 731.2, 108.5, 730.8, 110.1, 732.0, 111.5, 733.2, 113.0, 734.8, 113.0, 736.4, 113.0, 789.3, 84.9, 842.1, 56.7, 848.8, 54.3, 855.4, 51.9, 910.0, 52.3, 964.5, 52.7, 971.4, 54.4, 978.4, 56.0, 992.9, 60.6, 1007.5, 65.2, 1017.5, 70.2, 1027.5, 75.2, 1035.2, 80.7, 1042.9, 86.1, 1049.0, 92.8, 1055.0, 99.5, 1055.0, 101.0, 1054.9, 102.5, 1045.7, 112.2, 1036.5, 122.0, 1023.0, 116.4, 1009.6, 110.8, 1000.0, 108.5, 990.5, 106.2, 979.7, 104.6, 968.9, 103.0, 945.2, 103.0, 921.5, 103.0, 915.0, 104.9, 908.4, 106.7, 904.5, 108.8, 900.5, 110.9, 826.5, 156.3, 752.6, 201.7, 751.6, 203.3, 750.6, 204.8, 751.9, 206.4, 753.2, 208.0, 774.5, 208.0, 795.8, 208.0, 805.2, 194.8, 814.5, 181.6, 863.0, 153.0, 911.4, 124.5, 935.5, 124.2, 959.5, 123.9, 969.0, 125.0, 978.5, 126.2, 988.0, 130.2, 997.5, 134.2, 1002.5, 136.7, 1007.5, 139.2, 1013.7, 145.1, 1019.8, 151.0, 1023.4, 151.0, 1026.9, 151.0, 1037.2, 138.2, 1047.4, 125.5, 1053.7, 118.8, 1060.0, 112.1, 1063.0, 107.4, 1066.0, 102.6, 1066.0, 98.5, 1066.0, 94.4, 1062.6, 90.3, 1059.1, 86.3, 1052.3, 80.8, 1045.5, 75.3, 1036.0, 69.7, 1026.5, 64.1, 1017.8, 60.1, 1009.1, 56.1, 998.9, 52.5, 988.6, 48.9, 976.6, 46.3, 964.5, 43.7, 914.0, 43.4, 863.5, 43.1, 859.0, 44.1};
        vector<float> m_upperWall2 = {975.3, 477.9, 957.2, 495.7, 916.8, 531.1, 876.5, 566.5, 873.2, 569.3, 869.8, 572.0, 867.5, 572.0, 865.2, 572.0, 862.4, 569.7, 859.7, 567.5, 857.1, 564.5, 854.5, 561.6, 850.3, 557.6, 846.0, 553.6, 846.0, 551.5, 846.0, 549.3, 875.0, 522.0, 904.1, 494.7, 903.7, 493.6, 903.3, 492.5, 899.9, 492.6, 896.5, 492.6, 870.9, 498.3, 845.2, 504.0, 838.9, 504.0, 832.7, 504.0, 826.2, 502.9, 819.8, 501.8, 779.7, 482.4, 739.6, 463.0, 729.7, 474.7, 721.3, 486.5, 718.6, 490.4, 716.0, 494.3, 716.0, 495.5, 716.0, 496.8, 746.8, 525.7, 777.5, 554.7, 784.5, 560.9, 791.4, 567.0, 792.5, 567.0, 793.6, 567.0, 802.3, 575.4, 811.0, 583.9, 811.0, 588.8, 811.0, 593.8, 807.8, 596.5, 804.5, 599.1, 798.7, 603.4, 793.0, 607.7, 781.8, 611.0, 770.7, 614.3, 764.6, 613.7, 758.5, 613.1, 756.7, 612.5, 755.0, 611.8, 755.0, 608.7, 755.0, 605.7, 752.9, 599.9, 750.8, 594.2, 744.2, 588.3, 737.5, 582.5, 718.4, 563.8, 699.2, 545.0, 696.8, 545.0, 694.5, 545.0, 690.7, 548.1, 687.0, 551.1, 687.0, 555.3, 687.0, 559.4, 688.1, 565.4, 689.3, 571.5, 693.6, 589.5, 697.8, 607.5, 698.5, 610.9, 699.2, 614.3, 703.9, 618.9, 708.5, 623.6, 716.7, 626.8, 724.9, 630.1, 731.7, 631.6, 738.5, 633.2, 753.0, 633.7, 767.5, 634.2, 777.5, 633.2, 787.5, 632.1, 799.0, 628.5, 810.5, 625.0, 816.0, 623.1, 821.5, 621.2, 828.5, 618.5, 835.5, 615.9, 845.5, 611.3, 855.5, 606.7, 861.0, 603.1, 866.5, 599.6, 874.0, 595.3, 881.5, 591.0, 921.9, 553.2, 962.3, 515.5, 984.6, 492.6, 1007.0, 469.6, 1007.0, 468.0, 1007.0, 466.4, 1003.7, 463.2, 1000.4, 460.0, 997.0, 460.0, 993.5, 460.1, 975.3, 477.9};
        vector<float> m_upperWall3 = {961.4, 378.8, 958.3, 381.5, 938.9, 397.9, 919.5, 414.3, 908.5, 425.0, 897.5, 435.6, 890.3, 441.9, 883.0, 448.3, 883.0, 449.6, 883.0, 450.9, 883.9, 451.5, 884.9, 452.1, 906.5, 456.6, 928.2, 461.2, 929.9, 459.6, 931.7, 458.0, 949.9, 418.5, 968.2, 379.0, 967.6, 377.5, 967.1, 376.0, 965.8, 376.0, 964.5, 376.1, 961.4, 378.8};
        vector<float> m_upperWall4 = {760.6, 302.2, 759.2, 304.5, 755.5, 316.5, 751.8, 328.5, 745.9, 346.9, 740.0, 365.3, 740.0, 368.5, 740.0, 371.7, 742.3, 373.8, 744.6, 376.0, 749.9, 376.0, 755.2, 376.0, 757.7, 374.0, 760.3, 372.0, 765.3, 372.0, 770.2, 372.0, 774.1, 375.9, 778.0, 379.8, 778.0, 384.7, 778.0, 389.6, 776.4, 391.8, 774.8, 394.1, 770.9, 396.5, 767.0, 399.0, 763.5, 406.0, 760.0, 413.0, 793.8, 432.4, 827.7, 450.0, 835.4, 444.7, 841.7, 439.5, 883.9, 405.2, 926.0, 370.8, 926.0, 369.6, 926.0, 368.4, 924.8, 367.2, 923.6, 366.0, 910.6, 366.0, 897.5, 366.0, 870.0, 388.0, 842.5, 409.9, 823.0, 409.9, 803.5, 410.0, 799.4, 408.1, 795.3, 406.3, 793.2, 403.5, 791.0, 400.7, 791.0, 396.3, 791.0, 391.8, 794.4, 388.4, 797.8, 385.0, 802.3, 385.0, 806.8, 385.0, 808.8, 383.2, 810.9, 381.5, 817.5, 369.9, 824.0, 358.2, 809.9, 330.1, 795.7, 303.5, 794.2, 301.7, 792.7, 300.0, 777.4, 300.0, 762.0, 300.0, 760.6, 302.2};
        vector<float> m_upperWall5 = {759.9, 268.6, 758.6, 270.2, 759.7, 271.8, 760.7, 273.5, 776.5, 273.5, 792.3, 273.5, 793.3, 271.8, 794.4, 270.2, 793.1, 268.6, 791.8, 267.0, 776.5, 267.0, 761.2, 267.0, 759.9, 268.6};
        vector<float> m_upperWall6 = {756.9, 235.6, 755.6, 237.2, 756.7, 238.8, 757.7, 240.5, 773.5, 240.5, 789.3, 240.5, 790.3, 238.8, 791.4, 237.2, 790.1, 235.6, 788.8, 234.0, 773.5, 234.0, 758.2, 234.0, 756.9, 235.6};
        vector<float> m_upperWall7 = {490.0, 74.5, 474.5, 84.0, 474.2, 85.0, 473.8, 86.0, 506.6, 119.6, 539.4, 153.1, 540.8, 152.8, 542.3, 152.5, 543.3, 150.9, 544.3, 149.3, 527.6, 109.4, 510.8, 69.5, 509.4, 67.2, 508.0, 65.0, 506.7, 65.0, 505.5, 65.1, 490.0, 74.5};
        vector<float> m_leftSlide = {120.7, 46.0, 117.9, 47.8, 116.3, 50.0, 114.7, 52.3, 86.4, 126.4, 58.0, 200.4, 58.9, 201.3, 59.8, 202.2, 63.8, 200.9, 67.9, 199.7, 72.4, 201.0, 76.9, 202.2, 82.4, 207.7, 87.8, 213.3, 88.8, 212.6, 89.8, 212.0, 93.8, 202.3, 97.9, 192.5, 101.5, 183.0, 105.0, 173.5, 107.5, 167.0, 110.0, 160.5, 113.5, 151.0, 117.0, 141.5, 119.5, 135.0, 122.0, 128.5, 125.5, 119.3, 129.0, 110.0, 131.1, 103.3, 133.2, 96.5, 137.2, 84.5, 141.3, 72.5, 144.0, 66.4, 146.7, 60.3, 149.1, 58.1, 151.5, 55.8, 155.0, 54.1, 158.5, 52.5, 218.4, 52.0, 278.3, 51.5, 279.3, 49.8, 280.4, 48.1, 278.6, 46.1, 276.7, 44.0, 200.1, 44.1, 123.5, 44.1, 120.7, 46.0};
        vector<float> m_rightSlide = {82.2, 464.4, 77.0, 469.7, 72.4, 471.0, 67.9, 472.3, 63.8, 471.1, 59.8, 469.8, 58.9, 470.7, 58.0, 471.6, 85.5, 543.5, 112.9, 615.5, 115.1, 619.7, 117.3, 624.0, 120.7, 626.0, 124.1, 628.0, 200.4, 628.0, 276.7, 628.0, 278.6, 625.9, 280.4, 623.9, 279.3, 622.2, 278.3, 620.5, 218.4, 620.0, 158.5, 619.5, 155.0, 617.9, 151.5, 616.2, 149.1, 613.9, 146.7, 611.7, 144.0, 605.6, 141.2, 599.5, 136.6, 585.5, 132.0, 571.5, 129.0, 563.0, 126.1, 554.5, 122.5, 545.0, 118.9, 535.5, 116.5, 529.0, 114.1, 522.5, 110.5, 513.0, 106.9, 503.5, 104.5, 497.0, 102.1, 490.5, 99.7, 484.0, 97.2, 477.5, 93.3, 468.6, 89.5, 459.7, 88.5, 459.3, 87.5, 459.0, 82.2, 464.4};
        vector<float> m_leftSlideLine = {166.2, 79.2, 165.0, 80.4, 165.0, 82.1, 165.0, 83.8, 166.4, 84.9, 167.7, 86.0, 219.5, 85.8, 271.3, 85.5, 272.4, 83.7, 273.5, 82.0, 272.4, 80.2, 271.3, 78.5, 219.3, 78.2, 167.4, 78.0, 166.2, 79.2};
        vector<float> m_rightSlideLine = {166.2, 587.2, 165.0, 588.4, 165.0, 590.1, 165.0, 591.8, 166.4, 592.9, 167.7, 594.0, 219.5, 593.8, 271.3, 593.5, 272.4, 591.7, 273.5, 590.0, 272.4, 588.2, 271.3, 586.5, 219.3, 586.2, 167.4, 586.0, 166.2, 587.2};
        vector<float> m_leftBumper = {160.4, 113.9, 157.4, 115.7, 143.7, 147.1, 130.0, 178.5, 130.0, 181.6, 130.0, 184.7, 132.3, 186.8, 134.6, 189.0, 137.6, 189.0, 140.7, 189.0, 142.9, 186.6, 145.2, 184.2, 144.8, 180.5, 144.5, 176.7, 160.0, 168.8, 175.5, 160.9, 183.1, 156.5, 190.8, 152.1, 196.4, 149.6, 202.1, 147.1, 224.3, 135.0, 246.6, 123.0, 251.6, 125.5, 254.9, 128.0, 257.8, 128.0, 260.7, 128.0, 262.8, 125.7, 265.0, 123.4, 265.0, 120.3, 265.0, 117.2, 261.9, 114.6, 258.8, 112.0, 211.2, 112.0, 163.5, 112.0, 160.4, 113.9};
        vector<float> m_rightBumper = {132.2, 485.3, 130.0, 487.6, 130.0, 490.6, 130.0, 493.5, 143.7, 524.9, 157.4, 556.3, 160.4, 558.1, 163.5, 560.0, 211.2, 560.0, 258.8, 560.0, 261.9, 557.4, 265.0, 554.8, 265.0, 551.6, 265.0, 548.3, 262.7, 546.2, 260.4, 544.0, 257.6, 544.0, 254.9, 544.0, 251.6, 546.5, 248.3, 549.0, 224.3, 537.0, 202.1, 524.9, 196.4, 522.4, 190.8, 519.9, 183.1, 515.5, 175.5, 511.1, 160.0, 503.2, 144.5, 495.3, 144.8, 491.5, 145.2, 487.8, 142.9, 485.4, 140.7, 483.0, 137.5, 483.0, 134.3, 483.0, 132.2, 485.3};
        vector<float> m_backdoor = {422.0, 670.2, 422.0, 672.5, 427.5, 681.5, 433.0, 690.5, 433.0, 692.5, 433.0, 694.5, 435.0, 695.8, 437.0, 697.0, 437.0, 699.3, 437.0, 701.7, 439.4, 702.9, 441.8, 704.2, 442.8, 706.4, 443.8, 708.6, 448.6, 709.7, 453.5, 710.8, 462.8, 710.9, 472.0, 711.1, 472.0, 710.0, 472.0, 709.0, 474.5, 709.0, 477.0, 709.0, 477.0, 706.7, 477.0, 704.3, 467.7, 703.7, 458.3, 703.1, 453.9, 701.1, 449.5, 699.2, 445.5, 695.7, 441.4, 692.2, 434.1, 680.1, 426.8, 668.0, 424.4, 668.0, 422.0, 668.0, 422.0, 670.2};
        vector<vector<float>> m_layer1ShapeData = {
            m_tubeRight, m_tubeLeft, m_tubeLeftUpper, m_upperWall, m_upperWall2, m_upperWall3, m_upperWall4, m_upperWall5, m_upperWall6, /*m_upperWall7,*/ m_leftSlide, m_rightSlide, m_rightSlideLine, m_leftSlideLine, m_leftBumper, m_rightBumper, m_backdoor
        };

        // Layer 3 shapes.
        vector<float> m_leftInnerRail = {271.1, 46.8, 270.2, 48.6, 271.1, 50.3, 272.1, 52.0, 448.3, 52.0, 624.5, 52.0, 741.2, 148.7, 857.8, 245.5, 872.6, 257.0, 887.3, 268.5, 898.3, 277.2, 909.4, 286.0, 947.9, 286.0, 986.5, 286.0, 996.0, 284.6, 1005.6, 283.1, 1012.9, 280.5, 1020.2, 277.8, 1025.3, 274.8, 1030.5, 271.8, 1035.8, 267.8, 1041.1, 263.7, 1046.0, 257.5, 1050.9, 251.3, 1054.9, 243.9, 1058.9, 236.5, 1061.4, 228.9, 1063.9, 221.3, 1065.5, 211.9, 1067.0, 202.5, 1067.0, 194.5, 1067.0, 186.5, 1065.5, 177.1, 1063.9, 167.7, 1061.4, 160.1, 1058.9, 152.5, 1054.7, 144.5, 1050.5, 136.5, 1043.0, 129.0, 1035.5, 121.4, 1022.5, 116.1, 1009.5, 110.8, 1000.0, 108.5, 990.5, 106.2, 979.7, 104.6, 968.9, 103.0, 945.2, 103.0, 921.5, 103.0, 914.9, 104.9, 908.4, 106.7, 905.4, 108.3, 902.5, 109.8, 852.5, 140.5, 802.5, 171.1, 800.5, 173.1, 798.5, 175.0, 799.6, 176.8, 800.7, 178.5, 803.6, 178.5, 806.5, 178.4, 856.3, 147.2, 906.1, 115.9, 912.8, 113.7, 919.5, 111.5, 951.0, 111.5, 982.5, 111.5, 993.2, 114.3, 1004.0, 117.0, 1005.5, 117.0, 1007.0, 117.0, 1016.5, 121.0, 1026.1, 124.9, 1031.9, 129.4, 1037.7, 133.9, 1042.8, 139.5, 1048.0, 145.2, 1051.5, 152.4, 1054.9, 159.6, 1057.2, 168.5, 1059.4, 177.5, 1059.4, 194.5, 1059.5, 211.5, 1057.6, 219.5, 1055.8, 227.5, 1053.3, 233.5, 1050.8, 239.5, 1047.3, 244.8, 1043.8, 250.0, 1035.7, 256.5, 1027.6, 263.0, 1019.7, 267.1, 1011.9, 271.2, 1003.3, 274.1, 994.7, 277.0, 986.7, 278.5, 978.8, 280.0, 946.1, 280.0, 913.5, 280.0, 910.8, 278.2, 908.1, 276.5, 886.8, 259.8, 865.5, 243.0, 860.0, 238.5, 854.5, 234.0, 740.5, 139.5, 626.5, 45.0, 449.3, 45.0, 272.1, 45.0, 271.1, 46.8};
        vector<float> m_leftOuterRail = {859.0, 44.1, 854.5, 45.0, 849.1, 46.1, 843.8, 47.2, 822.1, 58.0, 800.5, 68.8, 766.0, 87.8, 731.5, 106.8, 731.2, 108.5, 730.8, 110.1, 732.0, 111.5, 733.2, 113.0, 734.8, 113.0, 736.4, 113.0, 789.3, 84.9, 842.1, 56.7, 848.8, 54.3, 855.4, 51.9, 910.0, 52.3, 964.5, 52.7, 971.4, 54.4, 978.4, 56.0, 992.9, 60.6, 1007.5, 65.2, 1017.5, 70.2, 1027.5, 75.2, 1035.1, 80.6, 1042.6, 85.9, 1053.9, 98.2, 1065.3, 110.4, 1070.2, 117.5, 1075.2, 124.5, 1079.0, 132.0, 1082.7, 139.5, 1084.9, 145.9, 1087.1, 152.3, 1089.0, 160.4, 1091.0, 168.5, 1092.2, 181.6, 1093.3, 194.8, 1092.1, 207.6, 1091.0, 220.5, 1089.0, 228.6, 1087.1, 236.7, 1084.9, 243.1, 1082.7, 249.5, 1079.2, 256.5, 1075.7, 263.5, 1071.8, 269.3, 1067.8, 275.2, 1061.9, 282.1, 1055.9, 289.0, 1044.2, 301.1, 1032.5, 313.3, 998.0, 345.5, 963.5, 377.7, 938.7, 398.1, 913.8, 418.5, 908.4, 422.7, 903.0, 427.0, 849.0, 427.0, 795.0, 427.0, 795.0, 414.0, 795.0, 401.0, 841.3, 401.0, 887.5, 401.0, 915.5, 379.2, 943.5, 357.5, 953.0, 348.5, 962.5, 339.5, 976.3, 328.2, 990.0, 316.9, 990.0, 315.6, 990.0, 314.4, 988.8, 313.2, 987.6, 312.0, 942.7, 312.0, 897.8, 312.0, 892.6, 308.2, 887.5, 304.5, 878.5, 297.1, 869.5, 289.7, 863.5, 284.0, 857.5, 278.2, 738.0, 178.1, 618.5, 78.0, 429.7, 78.0, 241.0, 78.0, 239.9, 80.4, 238.8, 82.7, 239.9, 84.9, 241.1, 87.0, 429.0, 87.0, 616.9, 87.0, 737.0, 188.0, 857.1, 289.0, 859.1, 290.0, 861.1, 291.1, 873.3, 301.3, 885.5, 311.5, 890.6, 315.2, 895.7, 319.0, 936.0, 319.2, 976.4, 319.5, 930.9, 356.7, 885.5, 394.0, 838.0, 394.0, 790.4, 394.0, 789.2, 395.2, 788.0, 396.4, 788.0, 414.0, 788.0, 431.6, 789.2, 432.8, 790.4, 434.0, 847.8, 434.0, 905.1, 434.0, 937.3, 407.9, 969.5, 381.8, 973.0, 378.0, 976.5, 374.2, 1014.0, 339.3, 1051.5, 304.3, 1061.7, 293.6, 1072.0, 282.9, 1077.5, 274.6, 1083.0, 266.3, 1086.4, 258.9, 1089.8, 251.5, 1092.0, 245.0, 1094.2, 238.5, 1096.0, 230.0, 1097.9, 221.5, 1099.1, 210.5, 1100.3, 199.5, 1099.7, 187.5, 1099.1, 175.5, 1097.5, 166.5, 1095.9, 157.5, 1093.8, 150.0, 1091.8, 142.5, 1088.0, 133.8, 1084.3, 125.1, 1079.7, 117.8, 1075.1, 110.5, 1070.5, 105.0, 1066.0, 99.5, 1066.0, 96.6, 1066.0, 93.7, 1058.5, 86.4, 1051.0, 79.1, 1042.6, 73.6, 1034.3, 68.0, 1021.9, 62.1, 1009.5, 56.2, 999.1, 52.6, 988.6, 48.9, 976.6, 46.3, 964.5, 43.7, 914.0, 43.4, 863.5, 43.1, 859.0, 44.1};
        vector<float> m_rightOuterRail = {1063.5, 595.1, 1058.5, 602.1, 1047.4, 612.9, 1036.4, 623.7, 1024.9, 631.3, 1013.5, 638.9, 1003.0, 643.9, 992.5, 648.9, 981.7, 652.5, 970.9, 656.1, 959.2, 658.5, 947.5, 661.0, 675.9, 661.0, 404.3, 661.0, 375.2, 641.0, 346.2, 621.0, 291.3, 621.2, 236.5, 621.5, 236.5, 624.0, 236.5, 626.5, 288.7, 626.8, 340.9, 627.0, 370.6, 647.5, 400.3, 668.0, 677.2, 668.0, 954.0, 668.0, 963.3, 666.0, 972.5, 663.9, 984.5, 659.9, 996.5, 655.9, 1007.5, 650.6, 1018.5, 645.2, 1027.5, 639.3, 1036.5, 633.3, 1043.0, 628.0, 1049.5, 622.6, 1056.9, 615.1, 1064.2, 607.5, 1070.1, 599.7, 1076.0, 591.9, 1073.5, 589.2, 1070.9, 588.0, 1069.7, 588.1, 1068.5, 588.1, 1063.5, 595.1};
        vector<float> m_rightInnerRail = {660.8, 433.7, 655.4, 437.5, 627.7, 457.4, 600.0, 477.3, 599.5, 479.1, 598.9, 480.9, 600.0, 482.9, 601.0, 484.9, 633.1, 529.2, 665.2, 573.5, 666.8, 574.7, 668.4, 576.0, 669.7, 576.0, 671.0, 576.0, 681.8, 568.6, 692.7, 561.2, 695.5, 559.7, 698.4, 558.2, 720.7, 579.9, 742.9, 601.5, 745.5, 602.4, 748.0, 603.4, 748.0, 608.4, 748.0, 613.5, 744.9, 618.8, 741.9, 624.1, 739.4, 625.0, 736.9, 626.0, 574.2, 626.0, 411.5, 626.0, 381.8, 605.5, 352.1, 585.0, 296.3, 585.2, 240.5, 585.5, 240.5, 589.5, 240.5, 593.5, 295.8, 593.8, 351.2, 594.0, 380.2, 614.0, 409.1, 634.0, 574.5, 634.0, 739.9, 634.0, 743.7, 631.9, 747.5, 629.8, 748.8, 628.7, 750.2, 627.6, 752.6, 622.8, 755.0, 618.1, 755.0, 611.9, 755.0, 605.7, 752.8, 599.8, 750.7, 593.9, 730.1, 574.1, 709.5, 554.3, 704.2, 549.6, 698.9, 545.0, 696.7, 545.0, 694.5, 545.0, 682.5, 554.9, 670.5, 564.8, 669.9, 564.1, 669.2, 563.5, 640.1, 523.2, 611.0, 483.0, 610.7, 482.1, 610.5, 481.2, 638.5, 461.0, 666.5, 440.8, 667.6, 440.4, 668.6, 439.9, 713.5, 462.0, 758.4, 484.1, 752.5, 498.0, 745.9, 511.1, 738.9, 504.8, 731.8, 498.5, 726.8, 494.2, 721.8, 490.0, 720.0, 490.0, 718.1, 490.0, 716.6, 491.6, 715.0, 493.1, 715.0, 494.9, 715.0, 496.7, 740.8, 519.5, 766.5, 542.4, 795.1, 570.4, 823.7, 598.5, 829.6, 603.1, 835.5, 607.7, 841.6, 611.8, 847.6, 615.9, 856.1, 620.4, 864.5, 624.9, 875.5, 628.7, 886.5, 632.5, 909.9, 632.8, 933.4, 633.1, 939.9, 632.0, 946.5, 630.9, 956.6, 627.5, 966.8, 624.1, 976.1, 619.4, 985.5, 614.7, 996.0, 607.7, 1006.5, 600.6, 1022.3, 584.8, 1038.2, 569.1, 1037.8, 567.3, 1037.5, 565.6, 1034.8, 564.1, 1032.2, 562.6, 1029.4, 566.1, 1026.7, 569.5, 1015.6, 580.6, 1004.5, 591.6, 997.0, 597.2, 989.4, 602.8, 983.0, 606.9, 976.5, 611.0, 972.5, 612.9, 968.5, 614.9, 958.5, 618.6, 948.5, 622.3, 942.3, 624.6, 936.1, 626.9, 935.5, 626.0, 934.9, 625.0, 913.1, 625.0, 891.2, 625.0, 882.4, 622.4, 873.5, 619.9, 864.1, 615.4, 854.7, 611.0, 846.4, 605.5, 838.2, 600.0, 827.3, 589.3, 816.4, 578.5, 813.0, 574.5, 809.5, 570.5, 803.8, 566.5, 798.2, 562.6, 797.7, 560.0, 797.1, 557.5, 775.1, 537.6, 753.0, 517.7, 761.5, 499.9, 770.1, 482.8, 769.5, 481.1, 769.0, 479.3, 718.7, 454.6, 668.5, 429.9, 667.4, 430.0, 666.3, 430.0, 660.8, 433.7};
        vector<vector<float>> m_layer2ShapeData = {
            m_leftInnerRail, m_leftOuterRail, m_rightOuterRail, m_rightInnerRail
        };

        // All the layers
        vector<vector<vector<float>>> m_layerData = {m_underLayer, m_launchTubeLayer, m_layer1ShapeData, m_layer2ShapeData};
};
#endif