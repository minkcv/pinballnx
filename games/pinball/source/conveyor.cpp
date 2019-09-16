#include "conveyor.h"

Conveyor::Conveyor(C2DRenderer* renderer, b2World& world, int conveyorID, int layerID) {
    m_layerID = layerID;
    resetDirection();
    vector<float> points = m_shapes.at(conveyorID);

    b2Vec2* vs = getVertexArray(points);
    b2PolygonShape poly;
    poly.Set(vs, 4);

    b2BodyDef bodyDef;
    b2Body* body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &poly;
    fixtureDef.density = 0.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.isSensor = true;
    fixtureDef.filter.maskBits = 1 << layerID;
    fixtureDef.filter.categoryBits = 1 << layerID;
    m_fixture = body->CreateFixture(&fixtureDef);

#if DEBUG
    m_shape = new ConvexShape();
    addPointsToShape(m_shape, points);
    m_shape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    m_shape->setFillColor(Color::Green);
    renderer->add(m_shape);
    m_shape->setLayer(layerID * 2 + 1);
#else
    for (int f = 0; f < m_frames; f++) {
        m_textureEnabled[f] = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/conveyor" + std::to_string(conveyorID) + "enabled" + std::to_string(f) + ".png");
        m_textureEnabled[f]->setLayer(-99);
        m_textureEnabled[f]->setPosition(m_positions.at(conveyorID * 2), m_positions.at(conveyorID * 2 + 1));
        renderer->add(m_textureEnabled[f]);
        m_textureDisabled[f] = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/conveyor" + std::to_string(conveyorID) + "disabled" + std::to_string(f) + ".png");
        m_textureDisabled[f]->setLayer(-99);
        m_textureDisabled[f]->setPosition(m_positions.at(conveyorID * 2), m_positions.at(conveyorID * 2 + 1));
        renderer->add(m_textureDisabled[f]);
    }
    m_textureEnabled[m_currentFrame]->setLayer(layerID * 2);
#endif
}

void Conveyor::update(unsigned int keys) {
    if (Input::Key::Fire5 & keys) {
        m_direction = b2Vec2(0, -1.0);
    }
    if (Input::Key::Fire6 & keys) {
        m_direction = b2Vec2(0, 1.0);
    }
#if !DEBUG
    if (m_frameTimer < m_frameDuration) {
        m_frameTimer++;
    }
    else {
        m_currentFrame++;
        if (m_currentFrame >= m_frames)
            m_currentFrame = 0;
        m_frameTimer = 0;
    }
    for (int f = 0; f < m_frames; f++) {
        m_textureEnabled[f]->setLayer(-99);
        m_textureDisabled[f]->setLayer(-99);
    }
    if (m_direction.y > 0) {
        m_textureDisabled[m_currentFrame]->setLayer(m_layerID * 2);
    }
    else {
        m_textureEnabled[m_currentFrame]->setLayer(m_layerID * 2);
    }
#endif
}

b2Fixture* Conveyor::getFixture() {
    return m_fixture;
}

b2Vec2 Conveyor::getDirection() {
    return m_direction;
}

void Conveyor::resetDirection() {
    m_direction = b2Vec2(0, -1.0);
}

