#include "flipper.h"

Flipper::Flipper(C2DRenderer* renderer, b2World& world, bool rightFlipper) {
    float yOffset = rightFlipper ? 0.02: -0.02;
    if (rightFlipper) {
        m_key = Input::Key::Fire6;
        m_x = m_rightX;
        m_y = m_rightY;
        m_rotateDirection = -1.0f;
    }
    else {
        m_key = Input::Key::Fire5;
        m_x = m_leftX;
        m_y = m_leftY;
        m_rotateDirection = 1.0f;
    }
    b2BodyDef bd;
    bd.position.Set(m_x, m_y + yOffset);
    m_pivot = world.CreateBody(&bd);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.18f;

#if DEBUG
    m_pivotShape = new CircleShape(0.18f * g_graphicsScale);
    m_pivotShape->setOrigin(Origin::Center);
    renderer->add(m_pivotShape);
#endif

    b2FixtureDef fd;
    fd.friction = 0.6f;
    fd.density = 1.0f;
    fd.shape = &circleShape;
    fd.filter.maskBits = 0xFFFF;
    fd.filter.categoryBits = 0xFFFF;
    m_pivot->CreateFixture(&fd);

    // Flipper body
    bd.type = b2_dynamicBody;
    bd.position.Set(m_x, m_y);
    m_body = world.CreateBody(&bd);

    if (rightFlipper)
        m_body->SetTransform(bd.position, -M_PI);

    b2Vec2* vs = getVertexArray(m_points);
    fd.density = 10.0f;
    b2PolygonShape shape;
    shape.Set(vs, 8);
    fd.shape = &shape;
    m_body->CreateFixture(&fd);

    b2RevoluteJointDef jd;
    jd.Initialize(m_pivot, m_body, m_pivot->GetWorldCenter());
    jd.enableMotor = true;
    jd.maxMotorTorque = 2000.0f;
    jd.motorSpeed = 0.0f;
    jd.lowerAngle = m_lowerLimit;
    jd.upperAngle = m_upperLimit;
    jd.enableLimit = true;
    m_joint = (b2RevoluteJoint*)world.CreateJoint(&jd);

#if DEBUG
    m_cshape = new ConvexShape();
    m_cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    addPointsToShape(m_cshape, m_points);
    renderer->add(m_cshape);
#else
    m_texture = new C2DTexture(renderer->getIo()->getDataReadPath() + "flipper.png");
    m_texture->setOrigin(Origin::Top);
    m_texture->setLayer(6);
    renderer->add(m_texture);
#endif
}

void Flipper::update(unsigned int keys) {
    float jointAngle = m_joint->GetJointAngle();
    if (keys & m_key) {
        if (jointAngle * m_rotateDirection < m_lowerLimit)
            m_joint->SetMotorSpeed(0.0f);
        else
            m_joint->SetMotorSpeed(-20.0f * m_rotateDirection);
    }
    else if (jointAngle * m_rotateDirection < m_upperLimit) {
        m_joint->SetMotorSpeed(20.0f * m_rotateDirection);
    }
    else {
        m_joint->SetMotorSpeed(0.0f);
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
    m_texture->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
    m_texture->setRotation(angle * 180 / M_PI);
#endif
}
