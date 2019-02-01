#include "flipper.h"

Flipper::Flipper(C2DRenderer* renderer, b2World& world, bool rightFlipper) {
    if (rightFlipper) {
        m_key = Input::Key::Fire6;
        m_x = m_rightX;
        m_y = m_rightY;
        m_lowerLimit = m_rightLowerLimit;
        m_upperLimit = m_rightUpperLimit;
        m_rotateDirection = -1.0f;
    }
    else {
        m_key = Input::Key::Fire5;
        m_x = m_leftX;
        m_y = m_leftY;
        m_lowerLimit = m_leftLowerLimit;
        m_upperLimit = m_leftUpperLimit;
        m_rotateDirection = 1.0f;
    }
    b2BodyDef bd;
    if (rightFlipper)
        bd.position.Set(m_x - 16 / g_graphicsScale, m_y - 16 / g_graphicsScale);
    else
        bd.position.Set(m_x + 16 / g_graphicsScale, m_y + 16 / g_graphicsScale);
    m_pivot = world.CreateBody(&bd);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.16f;

    b2FixtureDef fd;
    fd.friction = 0.6f;
    fd.density = 1.0f;
    fd.shape = &circleShape;
    m_pivot->CreateFixture(&fd);

    bd.type = b2_dynamicBody;
    bd.position.Set(m_x, m_y);
    m_body = world.CreateBody(&bd);

    if (rightFlipper)
        m_body->SetTransform(bd.position, -M_PI);

    size_t numValues = sizeof(m_points) / sizeof(m_points[0]);
    size_t numPoints = numValues / 2;
    b2Vec2* vs = getVertexArray(m_points, numPoints);
    fd.density = 1.0f;
    b2PolygonShape shape;
    shape.Set(vs, 8);
    fd.shape = &shape;
    m_body->CreateFixture(&fd);

    b2RevoluteJointDef jd;
    jd.Initialize(m_pivot, m_body, m_pivot->GetWorldCenter());
    jd.enableMotor = true;
    jd.maxMotorTorque = 1000.0f;
    jd.motorSpeed = 0.0f;
    jd.lowerAngle = m_lowerLimit;
    jd.upperAngle = m_upperLimit;
    jd.enableLimit = true;
    m_joint = (b2RevoluteJoint*)world.CreateJoint(&jd);

    m_cshape = new ConvexShape();
    m_cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    addPointsToShape(m_cshape, m_points, numPoints);
    renderer->add(m_cshape);
}

void Flipper::update(unsigned int keys) {
    float jointAngle = m_joint->GetJointAngle();
    if (keys & m_key) {
        if (jointAngle * m_rotateDirection < m_lowerLimit)
            m_joint->SetMotorSpeed(0.0f);
        else
            m_joint->SetMotorSpeed(-15.0f * m_rotateDirection);
    }
    else if (jointAngle * m_rotateDirection < m_upperLimit) {
        m_joint->SetMotorSpeed(15.0f * m_rotateDirection);
    }
    else {
        m_joint->SetMotorSpeed(0.0f);
    }

    b2Vec2 position = m_body->GetPosition();
    float32 angle = m_body->GetAngle();
    m_cshape->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
    m_cshape->setRotation(angle * 180 / M_PI);
}
