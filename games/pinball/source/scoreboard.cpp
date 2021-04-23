#include "scoreboard.h"

Scoreboard::Scoreboard(C2DRenderer* renderer) {
    int backgroundHeight = 1280 - 1152;
    m_background = new C2DRectangle(Vector2f(backgroundHeight, 768));
    m_background->setFillColor(Color::Black);
    m_background->setPosition(1152, 0);
    renderer->add(m_background);
    m_background->setLayer(-99);

    m_font = new Font();
    m_font->loadFromFile(renderer->getIo()->getRomFsPath() + "pinballnx/advanced_dot_digital-7.ttf");
    m_ballsLeftText = new C2DText("BALL 1");
    m_ballsLeftText->setFont(m_font);
    m_ballsLeftText->setCharacterSize(40);
    m_ballsLeftText->setPosition(1268, 5);
    m_ballsLeftText->setRotation(90);
    renderer->add(m_ballsLeftText);

    m_scoreText = new C2DText("");
    m_scoreText->setFont(m_font);
    m_scoreText->setCharacterSize(40);
    m_scoreText->setPosition(1268, 0);
    m_scoreText->setRotation(90);
    renderer->add(m_scoreText);

    m_announce = new C2DText("");
    m_announce->setFont(m_font);
    m_announce->setCharacterSize(40);
    m_announce->setPosition(1200, 350);
    m_announce->setRotation(90);
    renderer->add(m_announce);
    m_announce->setLayer(-100);
}

void Scoreboard::update(int currentBall, int maxBalls, uint64_t score, bool paused, string announce, string announceFlash) {
    int announceWidth = 0;
    if (announceFlash.length() < 1) {
        m_announceStr = announce;
    }
    else {
        if (m_flashTimer < 0) {
            if (m_announceStr.compare(announce) == 0)
                m_announceStr = announceFlash;
            else
                m_announceStr = announce;
            m_flashTimer = m_flashDelay;
        }
        else
            m_flashTimer--;
    }
    m_announce->setString(m_announceStr);
    if (m_announceStr.length() > 0) {
        int oneWidth = 0;
        for (size_t c = 0; c < m_announceStr.length(); c++) {
            if (oneWidth == 0)
                oneWidth = m_font->getGlyph(m_announceStr.at(c), 40, 0).advance;
            announceWidth += m_font->getGlyph(m_announceStr.at(c), 40, 0).advance;
        }
        int leftMargin = 768 / 2 - announceWidth / 2;
        // Align the characters with the above ones for the ball text
        leftMargin -= leftMargin % oneWidth;
        m_announce->setLayer(0);
        m_announce->setPosition(1200, leftMargin);
    }
    else {
        m_announce->setLayer(-100);
    }

    if (paused) {
        m_announce->setLayer(0);
    }
    
    if (currentBall < maxBalls + 1)
        m_ballsLeftText->setString("BALL " + std::to_string(currentBall));
    else {
        m_ballsLeftText->setString("");
    }

    // Format score as "123,456,789" or "      1,234"
    std::string numWithCommas = std::to_string(score);
    int numCommas = 0;
    int insertPosition = numWithCommas.length() - 3;
    while (insertPosition > 0) {
        numWithCommas.insert(insertPosition, ",");
        insertPosition-=3;
        numCommas++;
    }
    int totalKerning = 0;
    for (size_t c = 0; c < numWithCommas.length() - 1; c++) {
        totalKerning += m_font->getKerning((Uint32)numWithCommas.at(c), numWithCommas.at(c + 1), 40);
    }
    int characterWidths = 0;
    for (size_t c = 0; c < numWithCommas.length(); c++) {
        characterWidths += m_font->getGlyph(numWithCommas.at(c), 40, 0).advance;
    }
    int width = totalKerning + characterWidths;
    m_scoreText->setPosition(1268, 720 - width);
    m_scoreText->setString(numWithCommas);
}

Scoreboard::~Scoreboard() {
    delete m_font;
}
