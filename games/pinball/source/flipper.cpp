#include "flipper.h"

Flipper::Flipper(C2DRenderer* renderer, b2World& world) {
    b2BodyDef bd;
    bd.position.Set(m_x, m_y);
    m_pivot = world.CreateBody(&bd);

    b2CircleShape shape;
    shape.m_radius = 0.2f;

    b2FixtureDef fd;
    fd.shape = &shape;
    fd.density = 1.0f;
    m_pivot->CreateFixture(&fd);

    bd.type = b2_dynamicBody;
    bd.position.Set(m_x, m_y);
    m_body = world.CreateBody(&bd);

    size_t numValues = sizeof(m_points) / sizeof(m_points[0]);
    size_t numPoints = numValues / 2;
    createFixturesFromPoints(m_body, m_points, numPoints);

    b2RevoluteJointDef jd;
    jd.Initialize(m_pivot, m_body, m_pivot->GetWorldCenter());
    jd.enableMotor = true;
    jd.maxMotorTorque = 1000.0f;
    jd.motorSpeed = 0.0f;
    jd.lowerAngle = -M_PI / 8;
    jd.upperAngle = M_PI / 8;
    jd.enableLimit = true;
    m_joint = (b2RevoluteJoint*)world.CreateJoint(&jd);

    m_cshape = new ConvexShape();
    m_cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    addPointsToShape(m_cshape, m_points, numPoints);
    renderer->add(m_cshape);
}

void Flipper::update(unsigned int keys) {
    float jointAngle = m_joint->GetJointAngle();
    if (keys & Input::Key::Left) {
        if (jointAngle < -M_PI / 8)
            m_joint->SetMotorSpeed(0.0f);
        else
            m_joint->SetMotorSpeed(-10.0f);
    }
    else if (jointAngle < M_PI / 8) {
        m_joint->SetMotorSpeed(10.0f);
    }
    else {
        m_joint->SetMotorSpeed(0.0f);
    }

    Vector2<float> vTopLeft(-16 / g_graphicsScale, -16 / g_graphicsScale);
    b2Vec2 position = m_body->GetPosition();
    float32 angle = m_body->GetAngle();
    //float32 angle = m_joint->GetJointAngle();
    //printf("%f\n", angle);
    Vector2<float> transform = rotateVector(vTopLeft, -angle);
    m_cshape->setPosition((position.x + transform.x) * g_graphicsScale, (position.y - transform.y) * g_graphicsScale);
    m_cshape->setRotation(angle * 180 / M_PI);
}