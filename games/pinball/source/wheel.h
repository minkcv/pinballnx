#ifndef WHEEL_H_
#define WHEEL_H_

#include <vector>
#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"

using namespace std;

class Wheel {
    public:
        Wheel(C2DRenderer* renderer, b2World& world, int wheelID);
        void update();
        bool changedSection();
        void reset();
        b2Fixture* getFixture();
        void pinballContact();
        void pinballEndContact();
    private:
        float m_x;
        float m_y;
        vector<float> m_shape1 = {29.4, 10.3, 28.9, 11.6, 36.8, 25.1, 44.6, 38.5, 48.3, 45.1, 52.0, 51.7, 50.5, 54.6, 49.0, 57.5, 49.0, 60.5, 49.0, 63.5, 50.5, 66.4, 52.1, 69.4, 41.4, 87.9, 30.7, 106.5, 29.6, 108.2, 28.6, 110.0, 29.8, 111.2, 31.1, 112.5, 32.6, 111.5, 34.2, 110.5, 45.3, 91.2, 56.4, 72.0, 59.7, 72.0, 63.1, 72.0, 66.0, 70.5, 69.0, 69.0, 70.5, 66.0, 72.0, 63.0, 95.8, 62.8, 119.5, 62.5, 119.5, 60.5, 119.5, 58.5, 95.8, 58.2, 72.0, 58.0, 70.5, 55.0, 69.0, 52.0, 66.0, 50.5, 63.1, 49.0, 59.7, 49.0, 56.4, 49.0, 47.0, 32.7, 37.7, 16.5, 35.3, 12.7, 33.0, 9.0, 31.5, 9.0, 29.9, 9.0, 29.4, 10.3};
        vector<vector<float>> m_shapes = {
            m_shape1
        };
        vector<float> m_positions = {
            10.68, 2.65
        };
        vector<float> m_radii = {
            60
        };
        float m_radius;
        b2RevoluteJoint* m_joint;
        ConvexShape* m_cshape;
        C2DTexture* m_texture;
        b2Body* m_body;
        b2Body* m_pivot;
        b2Fixture* m_fixture;
        CircleShape* m_pivotShape;
        float m_anglePrev;
        int m_angleSection = 30;
        bool m_sectionChanged;
        int m_pinballsTouching = 0;
};

#endif