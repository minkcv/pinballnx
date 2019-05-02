#include "infoscreen.h"

InfoScreen::InfoScreen(C2DRenderer* renderer) {
    m_font = new Font();
    m_font->loadFromFile("data/advanced_dot_digital-7.ttf");
    m_shape = new C2DRectangle(Vector2f(1152, 768));
    m_shape->setLayer(-99);
    m_shape->setFillColor(Color::Black);
    renderer->add(m_shape);
    vector<string> infoText = {
        "PINBALLNX","BY MINKCV", "", "CONTROLS:", 
        "+ QUIT", "- PAUSE", "B NEW GAME", "JOYSTICK PLUNGER", "LR FLIPPERS", "",
        "VERSION: 0.3"};
    for (size_t t = 0; t < infoText.size(); t++) {
        C2DText* m_text = new C2DText(infoText.at(t));
        m_text->setFont(*m_font);
        m_text->setCharacterSize(40);
        m_text->setPosition(1100 - t * 60, 80);
        m_text->setRotation(90);
        renderer->add(m_text);
        m_text->setLayer(-100);
        m_textLines.push_back(m_text);
    }
}

void InfoScreen::show() {
    for (size_t t = 0; t < m_textLines.size(); t++) {
        m_textLines.at(t)->setLayer(100);
    }
    m_shape->setLayer(99);
}

void InfoScreen::hide() {
    for (size_t t = 0; t < m_textLines.size(); t++) {
        m_textLines.at(t)->setLayer(-100);
    }
    m_shape->setLayer(-99);
}