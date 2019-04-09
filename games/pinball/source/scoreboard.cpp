#include "scoreboard.h"

Scoreboard::Scoreboard(C2DRenderer* renderer) {
    m_font = new Font();
    m_font->loadFromFile("data/advanced_dot_digital-7.ttf");
    m_ballsLeftText = new C2DText("BALL 1/4");
    m_ballsLeftText->setFont(*m_font);
    m_ballsLeftText->setCharacterSize(40);
    m_ballsLeftText->setPosition(1200, 10);
    m_ballsLeftText->setRotation(90);
    renderer->add(m_ballsLeftText);

    m_scoreText = new C2DText("SCORE 0");
    m_scoreText->setFont(*m_font);
    m_scoreText->setCharacterSize(40);
    m_scoreText->setPosition(1268, 10);
    m_scoreText->setRotation(90);
    renderer->add(m_scoreText);
}

void Scoreboard::update(int currentBall, int score) {
    if (currentBall < 5)
        m_ballsLeftText->setString("BALL " + std::to_string(currentBall) + "/4");
    else
        m_ballsLeftText->setString("GAME OVER");

    // There is proabaly a cleaner way to do this zero padding.
    char buffer[255];
    sprintf(buffer, "%08d", score);
    std::string scoreString(buffer);
    m_scoreText->setString("SCORE " + scoreString);
}

Scoreboard::~Scoreboard() {
    delete m_font;
}