#include "bumper.h"

Bumper::Bumper(C2DRenderer* renderer, b2World& world, int layerID, int shapeID, float x, float y) {
    m_layerID = layerID;
    string inactiveTextureName;
    string activeTextureName;
    m_bumpForce = 10.0;
    if (shapeID == -1) {
        inactiveTextureName = "bumper1.png";
        activeTextureName = "bumper2.png";
        b2CircleShape circle;
        circle.m_radius = m_radius;
        b2BodyDef circleBodyDef;
        circleBodyDef.type = b2_staticBody;
        circleBodyDef.position.Set(x, y);
        circleBodyDef.bullet = true;
        m_body = world.CreateBody(&circleBodyDef);
        b2FixtureDef circleFixtureDef;
        circleFixtureDef.shape = &circle;
        circleFixtureDef.density = 1.0f;
        circleFixtureDef.friction = 0.3f;
        circleFixtureDef.filter.maskBits = 1 << layerID;
        circleFixtureDef.filter.categoryBits = 1 << layerID;
        m_fixture = m_body->CreateFixture(&circleFixtureDef);
    }
    else {
        float startX = m_centers.at(shapeID).at(0);
        float startY = m_centers.at(shapeID).at(1);
        if (shapeID > 1) // kickers
            m_bumpForce = 15.0;
        inactiveTextureName = "bumpershape" + std::to_string(shapeID) + "off.png";
        activeTextureName = "bumpershape" + std::to_string(shapeID) + "on.png";
        vector<float> points = m_shapes.at(shapeID);
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
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.filter.maskBits = 1 << layerID;
        fixtureDef.filter.categoryBits = 1 << layerID;
        m_fixture = m_body->CreateFixture(&fixtureDef);
    }

#if DEBUG
    if (shapeID == -1) {
        CircleShape* shape = new CircleShape(m_radius * g_graphicsScale);
        shape->setOrigin(Origin::Center);
        shape->setPosition(x * g_graphicsScale, y * g_graphicsScale);
        if (layerID == 0)
            shape->setFillColor(Color::Cyan);
        renderer->add(shape);
    }
    else {
        float startX = m_centers.at(shapeID).at(0);
        float startY = m_centers.at(shapeID).at(1);
        vector<float> points = m_shapes.at(shapeID);
        ConvexShape* cshape = new ConvexShape();
        addPointsToShape(cshape, points, startX, startY);
        cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
        cshape->setPosition(startX, startY);
        renderer->add(cshape);
    }
#else
    m_texture1 = new C2DTexture(renderer->getIo()->getDataReadPath() + inactiveTextureName);
    if (shapeID == -1)
        m_texture1->setOrigin(Origin::Center);
    m_texture1->setLayer(layerID * 2 + 1);
    m_texture1->setPosition(x * g_graphicsScale, y * g_graphicsScale);
    renderer->add(m_texture1);

    m_texture2 = new C2DTexture(renderer->getIo()->getDataReadPath() + activeTextureName);
    if (shapeID == -1)
        m_texture2->setOrigin(Origin::Center);
    m_texture2->setLayer(-99);
    m_texture2->setPosition(x * g_graphicsScale, y * g_graphicsScale);
    renderer->add(m_texture2);
#endif
}

void Bumper::update() {
    if (m_flashFrameCurrent < m_flashFrames) {
        m_flashFrameCurrent++;
    }
    else {
#if !DEBUG
        m_texture1->setLayer(m_layerID * 2 + 1);
        m_texture2->setLayer(-99);
#endif
    }
}

b2Fixture* Bumper::getFixture() {
    return m_fixture;
}

b2Body* Bumper::getBody() {
    return m_body;
}

void Bumper::setHit() {
#if !DEBUG
    m_texture1->setLayer(-99);
    m_texture2->setLayer(m_layerID * 2 + 1);
    m_flashFrameCurrent = 0;
#endif
}

float Bumper::getBumpForce() {
    return m_bumpForce;
}
