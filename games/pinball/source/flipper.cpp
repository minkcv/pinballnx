#include "flipper.h"

Flipper::Flipper(C2DRenderer* renderer, b2World& world, int flipperID) {
    float yOffset = flipperID ? 0.02: -0.02;
    if (flipperID % 2 == 0) {
        m_key = Input::Key::Fire5;
        m_rotateDirection = 1.0f;
    }
    else {
        m_key = Input::Key::Fire6;
        m_rotateDirection = -1.0f;
    }
    m_x = m_positions.at(flipperID * 2);
    m_y = m_positions.at(flipperID * 2 + 1);
    b2BodyDef bd;
    bd.position.Set(m_x, m_y + yOffset);
    m_pivot = world.CreateBody(&bd);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.18f;

#if DEBUG
    m_pivotShape = new CircleShape(0.18f * g_graphicsScale);
    m_pivotShape->setOrigin(Origin::Center);
    if (flipperID > 2)
        m_pivotShape->setFillColor(Color::Cyan);
    renderer->add(m_pivotShape);
#endif

    b2FixtureDef fd;
    fd.friction = 0.6f;
    fd.density = 1.0f;
    fd.shape = &circleShape;
    if (flipperID > 2) {
        fd.filter.maskBits = 1;
        fd.filter.categoryBits = 1;
    }
    else {
        fd.filter.maskBits = 1 << 2;
        fd.filter.categoryBits = 1 << 2;
    }
    m_pivot->CreateFixture(&fd);

    // Flipper body
    bd.type = b2_dynamicBody;
    bd.position.Set(m_x, m_y);
    bd.bullet = true;
    m_body = world.CreateBody(&bd);

    b2Vec2* vs;
    if (flipperID % 2 == 1)
        vs = getVertexArray(m_rightPoints);
    else
        vs = getVertexArray(m_leftPoints);
    fd.density = 10.0f;
    b2PolygonShape shape;
    shape.Set(vs, 8);
    fd.shape = &shape;
    m_body->CreateFixture(&fd);

    b2RevoluteJointDef jd;
    jd.bodyA = m_pivot;
    jd.bodyB = m_body;
    jd.referenceAngle = 0;
    jd.enableMotor = true;
    jd.maxMotorTorque = 2000.0f;
    jd.motorSpeed = 0.0f;
    if (flipperID == 2) {
        m_lowerLimit += M_PI * 3 / 16;
        m_upperLimit += M_PI * 3 / 16;
    }
    else if (flipperID == 3) {
        m_lowerLimit -= M_PI * 1 / 16;
        m_upperLimit -= M_PI * 1 / 16;
    }
    jd.lowerAngle = m_lowerLimit;
    jd.upperAngle = m_upperLimit;
    jd.enableLimit = true;
    m_joint = (b2RevoluteJoint*)world.CreateJoint(&jd);

#if DEBUG
    m_cshape = new ConvexShape();
    m_cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    if (flipperID % 2 == 1)
        addPointsToShape(m_cshape, m_rightPoints);
    else
        addPointsToShape(m_cshape, m_leftPoints);
    if (flipperID > 2)
        m_cshape->setFillColor(Color::Cyan);
    renderer->add(m_cshape);
#else
    m_texture = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/flipper.png");
    if (flipperID > 2)
        m_texture->setLayer(2);
    else
        m_texture->setLayer(6);
    renderer->add(m_texture);
#endif
}

void Flipper::update(unsigned int keys) {
    //float jointAngle = m_joint->GetJointAngle();
    //printf("%f %f %f\n", jointAngle, m_lowerLimit, m_upperLimit);
        
    if (keys & m_key) {
        m_joint->SetMotorSpeed(-20.0f * m_rotateDirection);
    }
    else {
        m_joint->SetMotorSpeed(20.0f * m_rotateDirection);
    }

    b2Vec2 position = m_body->GetPosition();
    float32 angle = m_body->GetAngle();
#if DEBUG
    m_cshape->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
    m_cshape->setRotation(angle * 180 / M_PI);
    // Pivot graphics
    b2Vec2 pivotPosition = m_pivot->GetPosition();
    m_pivotShape->setPosition(pivotPosition.x * g_graphicsScale, pivotPosition.y * g_graphicsScale);
#else
    m_texture->setOriginVector(16.0f, 16.0f);
    m_texture->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
    m_texture->setRotation(angle * 180 / M_PI);
#endif
}
