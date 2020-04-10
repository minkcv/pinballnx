#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "cross2d/c2d.h"
#include "util.h"
#include <string.h>

using namespace std;
using namespace c2d;

class Scoreboard {
    public:
        Scoreboard(C2DRenderer* renderer);
        void update(int currentBall, int maxBalls, uint64_t score, bool paused, string announce, string announceFlash);
        ~Scoreboard();
    private:
        C2DText* m_ballsLeftText;
        C2DText* m_scoreText;
        C2DText* m_announce;
        C2DRectangle* m_background;
        string m_announceStr;
        int m_flashDelay = 6 * g_displayFrameRate / 60;
        int m_flashTimer;
        Font* m_font;
};
#endif