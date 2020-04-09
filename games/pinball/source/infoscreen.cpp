#include "infoscreen.h"

InfoScreen::InfoScreen(C2DRenderer* renderer) {
    m_shape = new C2DRectangle(Vector2f(500, 600));
    m_shape->setPosition(440, 60);
    m_shape->setLayer(-99);
    m_shape->setFillColor(Color::Black);
    renderer->add(m_shape);
    m_controlsImage = new C2DTexture(renderer->getIo()->getRomFsPath() + "pinballnx/controls.png");
    m_controlsImage->setPosition(480, 80);
    m_controlsImage->setScale(3.0, 3.0);
    m_controlsImage->setLayer(-99);
    renderer->add(m_controlsImage);
    vector<string> infoText = {
        "PINBALLNX BY MINKCV - VERSION 0.9"};
    for (size_t t = 0; t < infoText.size(); t++) {
        C2DText* m_text = new C2DText(infoText.at(t));
        m_text->setCharacterSize(30);
        m_text->setPosition(910 - t * 35, 120);
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
    m_controlsImage->setLayer(99);
    m_shape->setLayer(99);
}

void InfoScreen::hide() {
    for (size_t t = 0; t < m_textLines.size(); t++) {
        m_textLines.at(t)->setLayer(-100);
    }
    m_shape->setLayer(-99);
    m_controlsImage->setLayer(-100);
}
