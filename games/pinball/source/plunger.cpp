#include "plunger.h"

Plunger::Plunger(C2DRenderer* renderer, b2World& world) {
    b2BodyDef bd;
    bd.position.Set(m_startX, m_startY);
    bd.type = b2_dynamicBody;
    m_body = world.CreateBody(&bd);

    // This constraint body is way off screen and just for the purpose of constraining the moving body.
    bd.position.Set(-100.0f, m_startY);
    bd.type = b2_staticBody;
    m_constraint = world.CreateBody(&bd);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(m_halfWidth, m_halfHeight);

    b2FixtureDef fd;
    fd.shape = &boxShape;
    fd.density = 1.0f;
    m_body->CreateFixture(&fd);

    // Give the constraint the same box and fixture, not that it matters.
    m_constraint->CreateFixture(&fd);

    b2PrismaticJointDef jd;
    b2Vec2 axis(1.0f, 0.0f);
    jd.Initialize(m_constraint, m_body, m_constraint->GetWorldCenter(), axis);
    jd.lowerTranslation = -1.0f;
    jd.upperTranslation = 0.0f;
    jd.enableLimit = true;
    jd.maxMotorForce = 15.0f;
    jd.motorSpeed = 0.0f;
    jd.enableMotor = true;

    m_joint = (b2PrismaticJoint*)world.CreateJoint(&jd);

#if DEBUG
    m_shape = new RectangleShape(Vector2f(m_halfWidth * 2 * g_graphicsScale, m_halfHeight * 2 * g_graphicsScale));
    renderer->add(m_shape);
#else
    m_texture = new C2DTexture(renderer->getIo()->getDataReadPath() + "plunger.png");
    m_texture->setLayer(99);
    renderer->add(m_texture);
#endif
}

void Plunger::update(unsigned int keys) {
    if (keys & Input::Key::Down) {
        m_joint->SetMotorSpeed(-5.0f);
    }
    else {
        m_joint->SetMotorSpeed(15.0f);
    }

    b2Vec2 position = m_body->GetPosition();
#if DEBUG
    m_shape->setPosition((position.x - m_halfWidth) * g_graphicsScale, (position.y - m_halfHeight) * g_graphicsScale);
#else
    m_texture->setPosition((position.x - m_halfWidth) * g_graphicsScale, (position.y - m_halfHeight) * g_graphicsScale);
#endif
}