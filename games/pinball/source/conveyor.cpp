#include "conveyor.h"

Conveyor::Conveyor(C2DRenderer* renderer, b2World& world, int conveyorID, int layerID) {
    m_layerID = layerID;
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
    m_textureEnabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/conveyor" + std::to_string(conveyorID) + "enabled.png");
    m_textureEnabled->setLayer(layerID * 2);
    m_textureEnabled->setPosition(m_positions.at(conveyorID * 2), m_positions.at(conveyorID * 2 + 1));
    renderer->add(m_textureEnabled);
    m_textureDisabled = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/conveyor" + std::to_string(conveyorID) + "disabled.png");
    m_textureDisabled->setLayer(-99);
    m_textureDisabled->setPosition(m_positions.at(conveyorID * 2), m_positions.at(conveyorID * 2 + 1));
    renderer->add(m_textureDisabled);
#endif
}

b2Fixture* Conveyor::getFixture() {
    return m_fixture;
}

void Conveyor::setDirection(b2Vec2 vec) {
    m_direction = vec;
#if !DEBUG
    // Change graphics.
    if (vec.y > 0) {
        m_textureEnabled->setLayer(-99);
        m_textureDisabled->setLayer(m_layerID * 2);
    }
    else {
        m_textureEnabled->setLayer(m_layerID * 2);
        m_textureDisabled->setLayer(-99);
    }
#endif
}

b2Vec2 Conveyor::getDirection() {
    return m_direction;
}

