#ifndef TRIGGER_H_
#define TRIGGER_H_

#include "cross2d/c2d.h"
#include "Box2D/Box2D.h"
#include "util.h"
#include "optwall.h"

class Trigger {
    public:
        Trigger(C2DRenderer* renderer, b2World& world, int triggerID, int layerID, OptWall* wallToChange);
        b2Fixture* getFixture();
        void update();
        void press();
        void reset();
    private:
        int m_layerID;
        b2Fixture* m_fixture;
        bool m_isPressed;
        OptWall* m_wallToChange;
        C2DTexture* m_textureEnabled;
        C2DTexture* m_textureDisabled;
        int m_hitFrames = 4;
        int m_hitFrameCurrent = m_hitFrames;

        vector<float> m_leftInletTrigger = {610.6, 8.6, 605.6, 9.9, 604.1, 11.4, 602.6, 12.9, 603.9, 29.2, 605.1, 45.5, 605.7, 50.3, 606.3, 55.1, 608.5, 56.6, 610.8, 58.1, 618.8, 55.5, 626.8, 52.9, 627.8, 51.7, 628.7, 50.5, 629.3, 33.5, 630.0, 16.5, 628.0, 13.2, 626.0, 9.9, 622.5, 8.4, 619.1, 7.0, 617.3, 7.1, 615.5, 7.2, 610.6, 8.6};
        vector<vector<float>> m_triggerShapes = {
            m_leftInletTrigger
        };
};
#endif