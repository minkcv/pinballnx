#ifndef PINBALL_H_
#define PINBALL_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include <vector>

using namespace c2d;
using namespace std;

class Pinball {
    public:
        Pinball(C2DRenderer* renderer, b2World* world, int iStartPos = 0);
        void update(C2DRenderer* renderer, b2World* world);
        b2Fixture* getFixture();
        b2Body* getBody();
        int getLayerID();
        void setLayerID(int layerID);
        void removeFromWorld();
        void setBumpVelocity(float x, float y);
        b2Vec2 getStartVelocity(int iSpawnPos);
        bool cleanupDone();
        bool isOut();
    private:
        b2Body* m_body;
        b2Fixture* m_fixture;
        CircleShape* m_shape;
        C2DTexture* m_texture;
        int m_currentLayerID = 1;

        // Box2D works best with objects between 0.1m and 10m in size.
        // A pinball is normally 0.027 meters in diameter, but this is too small for Box2D.
        // We simulate a pinball with a diameter of 0.22m and scale the pinball machine around this.
        float m_radius = 0.11;
        vector<float> m_startPositions = {
            2.0f, 6.9f, // Launch tube
            7.1f, 6.03f, // Right most lock ball ejector
            7.67f, 3.67f, // Middle lock ball ejector
            10.9f, 0.28f, // Left lock ball ejector
            7.10f, 4.60f // Second to right lock ball ejector
        };
        vector<float> m_startVelocities = {
            0.0f, 0.0f,
            -10.0f, 0.0f,
            -10.0f, -8.5f,
            -10.0f, 0.0f,
            -10.0f, -10.0f
        };
        bool m_ballOut = false;
        bool m_removed = false;
        float m_bumpX = 0;
        float m_bumpY = 0;
};
#endif
