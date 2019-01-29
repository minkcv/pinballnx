#include "flipper.h"

Flipper::Flipper(C2DRenderer* renderer, b2World& world, bool rightFlipper) {
    if (rightFlipper) {
        m_key = Input::Key::Right;
        m_x = m_rightX;
        m_y = m_rightY;
        m_lowerLimit = m_rightLowerLimit;
        m_upperLimit = m_rightUpperLimit;
        m_rotateDirection = -1.0f;
    }
    else {
        m_key = Input::Key::Left;
        m_x = m_leftX;
        m_y = m_leftY;
        m_lowerLimit = m_leftLowerLimit;
        m_upperLimit = m_leftUpperLimit;
        m_rotateDirection = 1.0f;
    }
    b2BodyDef bd;
    bd.position.Set(m_x, m_y);
    m_pivot = world.CreateBody(&bd);

    b2CircleShape shape;
    shape.m_radius = 0.1f;

    b2FixtureDef fd;
    fd.shape = &shape;
    fd.density = 1.0f;
    m_pivot->CreateFixture(&fd);

    bd.type = b2_dynamicBody;
    bd.position.Set(m_x, m_y);
    m_body = world.CreateBody(&bd);

    if (rightFlipper)
        m_body->SetTransform(bd.position, -M_PI);

    size_t numValues = sizeof(m_points) / sizeof(m_points[0]);
    size_t numPoints = numValues / 2;
    createFixturesFromPoints(m_body, m_points, numPoints);

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
            m_joint->SetMotorSpeed(-10.0f * m_rotateDirection);
    }
    else if (jointAngle * m_rotateDirection < m_upperLimit) {
        m_joint->SetMotorSpeed(10.0f * m_rotateDirection);
    }
    else {
        m_joint->SetMotorSpeed(0.0f);
    }

    Vector2<float> vTopLeft(-16 / g_graphicsScale, -16 / g_graphicsScale);
    b2Vec2 position = m_body->GetPosition();
    float32 angle = m_body->GetAngle();
    Vector2<float> transform = rotateVector(vTopLeft, -angle);
    m_cshape->setPosition((position.x + transform.x) * g_graphicsScale, (position.y - transform.y) * g_graphicsScale);
    m_cshape->setRotation(angle * 180 / M_PI);
}