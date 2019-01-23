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
        b2Body* m_body;
        float m_rightWall[64] = {-569.5, 224, -548.5, 285, -544.5, 295, -543, 295.5, -351, 295.5, -319, 263.5, -241, 263.5, -240.5, 279, -239, 279.5, 157, 279.5, 161.5, 275, 166, 273.5, 171.5, 265, 172.5, 241, 175.5, 235, 180, 231.5, 192, 231.5, 196.5, 237, 199.5, 252, 201.5, 255, 201.5, 260, 204, 260.5, 215.5, 281, 220, 284.5, 223.5, 291, 223.5, 300, 220.5, 306, 212, 311.5, -640, 311.5, -640.5, 24, -635.5, 34, -569.5, 223 };
};

#endif