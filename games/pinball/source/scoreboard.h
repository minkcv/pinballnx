#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "cross2d/c2d.h"

using namespace c2d;

class Scoreboard {
    public:
        Scoreboard(C2DRenderer* renderer);
        void update(int currentBall, int score, bool paused);
        ~Scoreboard();
    private:
        C2DText* m_ballsLeftText;
        C2DText* m_scoreText;
        Font* m_font;
};
#endif