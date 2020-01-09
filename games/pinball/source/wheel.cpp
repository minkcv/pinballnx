#include "wheel.h"

Wheel::Wheel(C2DRenderer* renderer, b2World& world, int wheelID) {
    m_radius = m_radii.at(wheelID);
    m_x = m_positions.at(wheelID * 2);
    m_y = m_positions.at(wheelID * 2 + 1);
    b2BodyDef bd;
    bd.position.Set(m_x, m_y);
    m_pivot = world.CreateBody(&bd);

    b2CircleShape circleShape;
    circleShape.m_radius = 0.1f;

#if DEBUG
    m_pivotShape = new CircleShape(0.1f * g_graphicsScale);
    m_pivotShape->setOrigin(Origin::Center);
    renderer->add(m_pivotShape);
#endif

    b2FixtureDef fd;
    fd.friction = 1.0f;
    fd.density = 1.0f;
    fd.shape = &circleShape;
    //fd.filter.maskBits = 1 << 2;
    //fd.filter.categoryBits = 1 << 2;
    fd.filter.maskBits = 1 << 3 | 1 << 2;
    fd.filter.categoryBits = 1 << 3 | 1 << 2;
    m_pivot->CreateFixture(&fd);

    bd.type = b2_dynamicBody;
    bd.position.Set(m_x, m_y);
    bd.bullet = true;
    m_body = world.CreateBody(&bd);

    b2Vec2* vs;
    vs = getVertexArray(m_shapes.at(wheelID), m_radius, m_radius);
    b2ChainShape shape;
    shape.CreateChain(vs, m_shapes.at(wheelID).size() / 2);
    fd.shape = &shape;
    m_fixture = m_body->CreateFixture(&fd);
    free(vs);

    // Chain shape has no mass so create
    // a box that doesn't collide and add it to the body
    fd.density = 0.001f;
    fd.friction = 1.0f;
    fd.filter.maskBits = 0;
    fd.filter.categoryBits = 0;
    b2PolygonShape box;
    box.SetAsBox(1.0, 1.0);
    fd.shape = &box;
    m_body->CreateFixture(&fd);

    b2RevoluteJointDef jd;
    jd.bodyA = m_pivot;
    jd.bodyB = m_body;
    jd.collideConnected = true;
    m_joint = (b2RevoluteJoint*)world.CreateJoint(&jd);

#if DEBUG
    m_cshape = new ConvexShape();
    m_cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    addPointsToShape(m_cshape, m_shapes.at(wheelID), m_radius, m_radius);
    renderer->add(m_cshape);
#else
    m_texture = new C2DTexture(renderer->getIo()->getDataReadPath() + "pinballnx/wheel" + to_string(wheelID) + ".png");
    m_texture->setLayer(6);
    m_texture->setOriginVector(m_radius, m_radius);
    m_texture->setPosition(m_x * g_graphicsScale, m_y * g_graphicsScale);
    renderer->add(m_texture);
#endif
    m_anglePrev = m_body->GetAngle();
    m_sectionChanged = false;
}

void Wheel::update() {
    //float jointAngle = m_joint->GetJointAngle();
    //printf("%f %f %f\n", jointAngle, m_lowerLimit, m_upperLimit);

    b2Vec2 position = m_body->GetPosition();
    float32 angle = m_body->GetAngle();

    // Only apply a slow to the wheel when no pinballs are on it.
    if (m_pinballsTouching == 0)
        m_body->ApplyTorque(- m_body->GetAngularVelocity() / 1000, true);
    else
        m_body->ApplyTorque(m_body->GetAngularVelocity() / 1000, true);
#if DEBUG
    m_cshape->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
    m_cshape->setRotation(angle * 180 / M_PI);
    // Pivot graphics
    b2Vec2 pivotPosition = m_pivot->GetPosition();
    m_pivotShape->setPosition(pivotPosition.x * g_graphicsScale, pivotPosition.y * g_graphicsScale);
#else
    m_texture->setOriginVector(m_radius, m_radius);
    m_texture->setPosition(position.x * g_graphicsScale, position.y * g_graphicsScale);
    m_texture->setRotation(angle * 180 / M_PI);
#endif
    if ((int)angle % m_angleSection != (int)m_anglePrev % m_angleSection)
        m_sectionChanged = true;
    else
        m_sectionChanged = false;
    m_anglePrev = angle;
}

bool Wheel::changedSection() {
    return m_sectionChanged;
}

void Wheel::stop() {
    m_body->SetAngularVelocity(0);
}

b2Fixture* Wheel::getFixture() {
    return m_fixture;
}

void Wheel::pinballContact() {
    m_pinballsTouching++;
}

void Wheel::pinballEndContact() {
    m_pinballsTouching--;
}
