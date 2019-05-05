#include "scoreboard.h"

Scoreboard::Scoreboard(C2DRenderer* renderer) {
    int backgroundHeight = 1280 - 1152;
    m_background = new C2DRectangle(Vector2f(backgroundHeight, 768));
    m_background->setFillColor(Color::Black);
    m_background->setPosition(1152, 0);
    renderer->add(m_background);
    m_background->setLayer(-99);

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

    m_multiBallText = new C2DText("LOCKED 0/3");
    m_multiBallText->setFont(*m_font);
    m_multiBallText->setCharacterSize(40);
    m_multiBallText->setPosition(1200, 350);
    m_multiBallText->setRotation(90);
    renderer->add(m_multiBallText);
    m_multiBallText->setLayer(-100);
}

void Scoreboard::update(int currentBall, int score, int lockedBalls, bool paused) {
    if (lockedBalls == 0) {
        m_multiBallText->setLayer(-100);
    }
    else if (lockedBalls < 0) {
        m_multiBallText->setLayer(0);
        m_multiBallText->setString("MULTIBALL");
    }
    else {
        m_multiBallText->setLayer(0);
        m_multiBallText->setString("LOCKED " + std::to_string(lockedBalls) + "/3");
    }

    if (paused) 
        m_ballsLeftText->setString("PAUSED");
    else {
        if (currentBall < 5)
            m_ballsLeftText->setString("BALL " + std::to_string(currentBall) + "/4");
        else {
            m_ballsLeftText->setString("GAME OVER");
            m_multiBallText->setLayer(-100);
        }
    }

    // There is proabaly a cleaner way to do this zero padding.
    char buffer[255];
    sprintf(buffer, "%08d", score);
    std::string scoreString(buffer);
    m_scoreText->setString("SCORE " + scoreString);
}

Scoreboard::~Scoreboard() {
    delete m_font;
}