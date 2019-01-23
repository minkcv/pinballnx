#ifndef TABLE_H_
#define TABLE_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"

using namespace c2d;

class Table {
    public:
        Table(C2DRenderer* renderer, b2World& world);
    private:
        b2Body* m_body;
};

#endif