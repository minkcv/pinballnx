#include "scoreboard.h"

Scoreboard::Scoreboard(C2DRenderer* renderer) {
    m_ballsLeftText = new C2DText("Balls: 1/4");
    m_ballsLeftText->setPosition(1280, 0);
    m_ballsLeftText->setRotation(90);
    renderer->add(m_ballsLeftText);
}

void Scoreboard::update(int currentBall) {
    if (currentBall < 5)
        m_ballsLeftText->setString("Ball: " + std::to_string(currentBall) + "/4");
    else
        m_ballsLeftText->setString("Game Over");
}