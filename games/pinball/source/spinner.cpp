#include "spinner.h"

Spinner::Spinner(C2DRenderer* renderer, b2World& world, int layerID, int spinnerID) {
    m_layerID = layerID;

    float startX = m_positions.at(spinnerID * 2);
    float startY = m_positions.at(spinnerID * 2 + 1);
    vector<float> points = m_shapes.at(spinnerID);
    b2Vec2* vs = getVertexArray(points, startX, startY);
    b2ChainShape chain;
    chain.CreateChain(vs, points.size() / 2);
    free(vs);
    vs = NULL;
    b2BodyDef bodyDef;
    bodyDef.position.Set(startX / g_graphicsScale, startY / g_graphicsScale);
    m_body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.isSensor = true;
    fixtureDef.filter.maskBits = 1 << layerID;
    fixtureDef.filter.categoryBits = 1 << layerID;
    m_fixture = m_body->CreateFixture(&fixtureDef);
#if DEBUG
        // Debug graphics
        m_shape = new ConvexShape();
        addPointsToShape(m_shape, points);
        m_shape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
        m_shape->setFillColor(Color::Blue);
        renderer->add(m_shape);
#else
        for (int f = 0; f < m_frames; f++) {
            m_textures[f] = new C2DTexture(renderer->getIo()->getRomFsPath() + "pinballnx/spinner" + std::to_string(spinnerID) + "-" + std::to_string(f) + ".png");
            m_textures[f]->setLayer(-99);
            m_textures[f]->setPosition(startX, startY);
            renderer->add(m_textures[f]);
        }
        m_textures[m_currentFrame]->setLayer(m_layerID  * 2 + 2);
#endif
}

void Spinner::update() {
    if (m_push > 0) {
        m_push -= ceil(m_push + 1) / 10;
        m_frameDuration = 2 * g_displayFrameRate / (m_push);
        if (m_frameTimer < m_frameDuration) {
            m_frameTimer++;
        }
        else {
            m_currentFrame++;
            m_frameTimer = 0;
        }
    }
    else if (m_push < 0) {
        m_push -= floor(m_push - 1) / 10;
        m_frameDuration = 2 * g_displayFrameRate / (-m_push);
        if (m_frameTimer < m_frameDuration) {
            m_frameTimer++;
        }
        else {
            m_currentFrame--;
            m_frameTimer = 0;
        }
    }
    if (m_currentFrame >= m_frames)
        m_currentFrame = 0;
    if (m_currentFrame < 0)
        m_currentFrame = m_frames - 1;
#if !DEBUG
    for (int f = 0; f < m_frames; f++) {
        m_textures[f]->setLayer(-99);
    }
    m_textures[m_currentFrame]->setLayer(m_layerID * 2 + 2);
#endif
}

int Spinner::getPush() {
    return m_push;
}

void Spinner::push(b2Vec2 ballVelocity) {
    m_push = 400 * ballVelocity.x;
    m_frameDuration = 2 * g_displayFrameRate / (m_push);
}

b2Fixture* Spinner::getFixture() {
    return m_fixture;
}