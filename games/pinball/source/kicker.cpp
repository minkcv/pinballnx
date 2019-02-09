#include "kicker.h"

Kicker::Kicker(C2DRenderer* renderer, b2World& world, bool right) {
    b2BodyDef bd;
    if (right)
        bd.position.Set(m_rightX, m_rightY);
    else
        bd.position.Set(m_leftX, m_leftY);
    bd.type = b2_dynamicBody;
    m_body = world.CreateBody(&bd);

    // This constraint body is way off screen and just for the purpose of constraining the moving body.
    if (right)
        bd.position.Set(-10.0f, m_rightY);
    else
        bd.position.Set(-10.0f, m_leftY);
    bd.type = b2_staticBody;
    b2Body* constraint = world.CreateBody(&bd);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(m_halfWidth, m_halfHeight);

    b2FixtureDef fd;
    fd.shape = &boxShape;
    fd.density = 1.0f;
    fd.filter.maskBits = 0xFFFF;
    fd.filter.categoryBits = 0xFFFF;
    m_fixture = m_body->CreateFixture(&fd);

    // Give the constraint the same box and fixture, not that it matters.
    constraint->CreateFixture(&fd);

    b2PrismaticJointDef jd;
    b2Vec2 axis(1.0f, 0.0f);
    jd.Initialize(constraint, m_body, constraint->GetWorldCenter(), axis);
    jd.lowerTranslation = -10.0f;
    jd.upperTranslation = 10.0f;
    jd.enableLimit = true;
    jd.maxMotorForce = 15.0f;
    jd.motorSpeed = 0.0f;
    jd.enableMotor = true;

    m_joint = (b2PrismaticJoint*)world.CreateJoint(&jd);

#if DEBUG
    m_shape = new RectangleShape(Vector2f(m_halfWidth * 2 * g_graphicsScale, m_halfHeight * 2 * g_graphicsScale));
    m_shape->setOrigin(Origin::TopRight);
    renderer->add(m_shape);
#else
    m_texture = new C2DTexture(renderer->getIo()->getDataReadPath() + "kicker.png");
    m_texture->setLayer(0);
    m_texture->setOrigin(Origin::Top);
    renderer->add(m_texture);
#endif
}

void Kicker::update() {
    b2Vec2 position = m_body->GetPosition();
#if DEBUG
    m_shape->setPosition((position.x - m_halfWidth) * g_graphicsScale, (position.y - m_halfHeight) * g_graphicsScale);
#else
    m_texture->setPosition((position.x - m_halfWidth) * g_graphicsScale, (position.y - m_halfHeight) * g_graphicsScale);
#endif

    if (m_hitFrameCurrent < m_hitFrames) {
        m_joint->SetMotorSpeed(10.0f);
        m_hitFrameCurrent++;
    }
    else
        m_joint->SetMotorSpeed(-2.0f);
}

b2Fixture* Kicker::getFixture() {
    return m_fixture;
}

void Kicker::setHit() {
    m_hitFrameCurrent = 0;
}