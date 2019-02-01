#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "cross2d/c2d.h"

using namespace c2d;

class Scoreboard {
    public:
        Scoreboard(C2DRenderer* renderer);
        void update(int currentBall);
    private:
        C2DText m_ballsLeftText;
};
#endif