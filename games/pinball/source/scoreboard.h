#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "cross2d/c2d.h"
#include <string.h>

using namespace std;
using namespace c2d;

class Scoreboard {
    public:
        Scoreboard(C2DRenderer* renderer);
        void update(int currentBall, int maxBalls, uint64_t score, bool paused, string announce);
        ~Scoreboard();
    private:
        C2DText* m_ballsLeftText;
        C2DText* m_scoreText;
        C2DText* m_announce;
        C2DRectangle* m_background;
        Font* m_font;
};
#endif