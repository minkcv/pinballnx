#include "table.h"

Table::Table(C2DRenderer* renderer, b2World& world) {
    b2Vec2 vs[242];
    int i = 0;
    vs[i++].Set(-638 / g_graphicsScale, -360.5 / g_graphicsScale);
    vs[i++].Set(511 / g_graphicsScale, -360.5 / g_graphicsScale);
    vs[i++].Set(511.5 / g_graphicsScale, 359 / g_graphicsScale);
    vs[i++].Set(-640 / g_graphicsScale, 359.5 / g_graphicsScale);
    vs[i++].Set(-640.5 / g_graphicsScale, 344 / g_graphicsScale);
    vs[i++].Set(-639 / g_graphicsScale, 343.5 / g_graphicsScale);
    vs[i++].Set(317 / g_graphicsScale, 343.5 / g_graphicsScale);
    vs[i++].Set(334 / g_graphicsScale, 341.5 / g_graphicsScale);
    vs[i++].Set(366 / g_graphicsScale, 333.5 / g_graphicsScale);
    vs[i++].Set(399 / g_graphicsScale, 318.5 / g_graphicsScale);
    vs[i++].Set(425 / g_graphicsScale, 300.5 / g_graphicsScale);
    vs[i++].Set(447 / g_graphicsScale, 279.5 / g_graphicsScale);
    vs[i++].Set(467.5 / g_graphicsScale, 252 / g_graphicsScale);
    vs[i++].Set(480.5 / g_graphicsScale, 227 / g_graphicsScale);
    vs[i++].Set(490.5 / g_graphicsScale, 197 / g_graphicsScale);
    vs[i++].Set(495.5 / g_graphicsScale, 165 / g_graphicsScale);
    vs[i++].Set(494.5 / g_graphicsScale, -27 / g_graphicsScale);
    vs[i++].Set(492.5 / g_graphicsScale, -43 / g_graphicsScale);
    vs[i++].Set(488.5 / g_graphicsScale, -67 / g_graphicsScale);
    vs[i++].Set(479.5 / g_graphicsScale, -90 / g_graphicsScale);
    vs[i++].Set(474.5 / g_graphicsScale, -98 / g_graphicsScale);
    vs[i++].Set(472.5 / g_graphicsScale, -105 / g_graphicsScale);
    vs[i++].Set(462.5 / g_graphicsScale, -119 / g_graphicsScale);
    vs[i++].Set(457.5 / g_graphicsScale, -129 / g_graphicsScale);
    vs[i++].Set(449.5 / g_graphicsScale, -139 / g_graphicsScale);
    vs[i++].Set(445 / g_graphicsScale, -141.5 / g_graphicsScale);
    vs[i++].Set(443.5 / g_graphicsScale, -145 / g_graphicsScale);
    vs[i++].Set(430 / g_graphicsScale, -152.5 / g_graphicsScale);
    vs[i++].Set(421.5 / g_graphicsScale, -160 / g_graphicsScale);
    vs[i++].Set(405 / g_graphicsScale, -169.5 / g_graphicsScale);
    vs[i++].Set(384 / g_graphicsScale, -177.5 / g_graphicsScale);
    vs[i++].Set(368 / g_graphicsScale, -178.5 / g_graphicsScale);
    vs[i++].Set(365 / g_graphicsScale, -180.5 / g_graphicsScale);
    vs[i++].Set(323 / g_graphicsScale, -180.5 / g_graphicsScale);
    vs[i++].Set(298 / g_graphicsScale, -177.5 / g_graphicsScale);
    vs[i++].Set(272 / g_graphicsScale, -167.5 / g_graphicsScale);
    vs[i++].Set(258 / g_graphicsScale, -167.5 / g_graphicsScale);
    vs[i++].Set(250 / g_graphicsScale, -172.5 / g_graphicsScale);
    vs[i++].Set(246.5 / g_graphicsScale, -180 / g_graphicsScale);
    vs[i++].Set(244.5 / g_graphicsScale, -191 / g_graphicsScale);
    vs[i++].Set(244.5 / g_graphicsScale, -200 / g_graphicsScale);
    vs[i++].Set(246 / g_graphicsScale, -200.5 / g_graphicsScale);
    vs[i++].Set(246.5 / g_graphicsScale, -206 / g_graphicsScale);
    vs[i++].Set(258.5 / g_graphicsScale, -220 / g_graphicsScale);
    vs[i++].Set(268 / g_graphicsScale, -224.5 / g_graphicsScale);
    vs[i++].Set(271 / g_graphicsScale, -227.5 / g_graphicsScale);
    vs[i++].Set(300 / g_graphicsScale, -238.5 / g_graphicsScale);
    vs[i++].Set(312 / g_graphicsScale, -239.5 / g_graphicsScale);
    vs[i++].Set(318 / g_graphicsScale, -242.5 / g_graphicsScale);
    vs[i++].Set(328 / g_graphicsScale, -243.5 / g_graphicsScale);
    vs[i++].Set(331 / g_graphicsScale, -245.5 / g_graphicsScale);
    vs[i++].Set(356 / g_graphicsScale, -245.5 / g_graphicsScale);
    vs[i++].Set(379 / g_graphicsScale, -238.5 / g_graphicsScale);
    vs[i++].Set(390 / g_graphicsScale, -239.5 / g_graphicsScale);
    vs[i++].Set(394.5 / g_graphicsScale, -247 / g_graphicsScale);
    vs[i++].Set(393.5 / g_graphicsScale, -266 / g_graphicsScale);
    vs[i++].Set(385.5 / g_graphicsScale, -277 / g_graphicsScale);
    vs[i++].Set(376 / g_graphicsScale, -280.5 / g_graphicsScale);
    vs[i++].Set(373 / g_graphicsScale, -283.5 / g_graphicsScale);
    vs[i++].Set(349 / g_graphicsScale, -288.5 / g_graphicsScale);
    vs[i++].Set(327 / g_graphicsScale, -289.5 / g_graphicsScale);
    vs[i++].Set(292 / g_graphicsScale, -289.5 / g_graphicsScale);
    vs[i++].Set(281 / g_graphicsScale, -286.5 / g_graphicsScale);
    vs[i++].Set(260 / g_graphicsScale, -284.5 / g_graphicsScale);
    vs[i++].Set(256 / g_graphicsScale, -282.5 / g_graphicsScale);
    vs[i++].Set(243 / g_graphicsScale, -281.5 / g_graphicsScale);
    vs[i++].Set(240 / g_graphicsScale, -279.5 / g_graphicsScale);
    vs[i++].Set(235 / g_graphicsScale, -279.5 / g_graphicsScale);
    vs[i++].Set(232 / g_graphicsScale, -277.5 / g_graphicsScale);
    vs[i++].Set(217 / g_graphicsScale, -274.5 / g_graphicsScale);
    vs[i++].Set(211 / g_graphicsScale, -270.5 / g_graphicsScale);
    vs[i++].Set(206 / g_graphicsScale, -270.5 / g_graphicsScale);
    vs[i++].Set(183 / g_graphicsScale, -261.5 / g_graphicsScale);
    vs[i++].Set(180.5 / g_graphicsScale, -259 / g_graphicsScale);
    vs[i++].Set(168 / g_graphicsScale, -254.5 / g_graphicsScale);
    vs[i++].Set(162 / g_graphicsScale, -250.5 / g_graphicsScale);
    vs[i++].Set(155 / g_graphicsScale, -249.5 / g_graphicsScale);
    vs[i++].Set(138 / g_graphicsScale, -242.5 / g_graphicsScale);
    vs[i++].Set(126 / g_graphicsScale, -240.5 / g_graphicsScale);
    vs[i++].Set(116 / g_graphicsScale, -233.5 / g_graphicsScale);
    vs[i++].Set(108 / g_graphicsScale, -230.5 / g_graphicsScale);
    vs[i++].Set(86 / g_graphicsScale, -228.5 / g_graphicsScale);
    vs[i++].Set(69 / g_graphicsScale, -224.5 / g_graphicsScale);
    vs[i++].Set(33 / g_graphicsScale, -224.5 / g_graphicsScale);
    vs[i++].Set(27 / g_graphicsScale, -230.5 / g_graphicsScale);
    vs[i++].Set(25.5 / g_graphicsScale, -235 / g_graphicsScale);
    vs[i++].Set(35 / g_graphicsScale, -240.5 / g_graphicsScale);
    vs[i++].Set(50 / g_graphicsScale, -243.5 / g_graphicsScale);
    vs[i++].Set(63 / g_graphicsScale, -248.5 / g_graphicsScale);
    vs[i++].Set(63.5 / g_graphicsScale, -250 / g_graphicsScale);
    vs[i++].Set(68 / g_graphicsScale, -250.5 / g_graphicsScale);
    vs[i++].Set(73 / g_graphicsScale, -254.5 / g_graphicsScale);
    vs[i++].Set(80 / g_graphicsScale, -255.5 / g_graphicsScale);
    vs[i++].Set(86 / g_graphicsScale, -261.5 / g_graphicsScale);
    vs[i++].Set(91.5 / g_graphicsScale, -275 / g_graphicsScale);
    vs[i++].Set(91.5 / g_graphicsScale, -287 / g_graphicsScale);
    vs[i++].Set(88.5 / g_graphicsScale, -293 / g_graphicsScale);
    vs[i++].Set(88.5 / g_graphicsScale, -297 / g_graphicsScale);
    vs[i++].Set(85.5 / g_graphicsScale, -301 / g_graphicsScale);
    vs[i++].Set(80 / g_graphicsScale, -303.5 / g_graphicsScale);
    vs[i++].Set(36 / g_graphicsScale, -303.5 / g_graphicsScale);
    vs[i++].Set(30 / g_graphicsScale, -301.5 / g_graphicsScale);
    vs[i++].Set(22 / g_graphicsScale, -301.5 / g_graphicsScale);
    vs[i++].Set(-3 / g_graphicsScale, -296.5 / g_graphicsScale);
    vs[i++].Set(-32 / g_graphicsScale, -285.5 / g_graphicsScale);
    vs[i++].Set(-37 / g_graphicsScale, -285.5 / g_graphicsScale);
    vs[i++].Set(-46 / g_graphicsScale, -281.5 / g_graphicsScale);
    vs[i++].Set(-54 / g_graphicsScale, -280.5 / g_graphicsScale);
    vs[i++].Set(-239 / g_graphicsScale, -280.5 / g_graphicsScale);
    vs[i++].Set(-270.5 / g_graphicsScale, -312 / g_graphicsScale);
    vs[i++].Set(-320 / g_graphicsScale, -312.5 / g_graphicsScale);
    vs[i++].Set(-352 / g_graphicsScale, -344.5 / g_graphicsScale);
    vs[i++].Set(-544 / g_graphicsScale, -344.5 / g_graphicsScale);
    vs[i++].Set(-559.5 / g_graphicsScale, -305 / g_graphicsScale);
    vs[i++].Set(-634.5 / g_graphicsScale, -86 / g_graphicsScale);
    vs[i++].Set(-640.5 / g_graphicsScale, -73 / g_graphicsScale);
    vs[i++].Set(-640.5 / g_graphicsScale, -360 / g_graphicsScale);
    vs[i++].Set(-639 / g_graphicsScale, -360.5 / g_graphicsScale);
    b2ChainShape chain;
    chain.CreateChain(vs, 118);

    b2BodyDef bodyDef;
    bodyDef.position.Set(6.4, 3.6); // 1280 / 2 / 100, 720 / 2 / 100
    m_body = world.CreateBody(&bodyDef);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &chain;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    m_body->CreateFixture(&fixtureDef);

    ConvexShape* cshape = new ConvexShape();
    cshape->setPointCount(117);
    cshape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    i = 0;
    cshape->setPoint(i++, Vector2f(-638, -360.5));
    cshape->setPoint(i++, Vector2f(511, -360.5));
    cshape->setPoint(i++, Vector2f(511.5, 359));
    cshape->setPoint(i++, Vector2f(-640, 359.5));
    cshape->setPoint(i++, Vector2f(-640.5, 344));
    cshape->setPoint(i++, Vector2f(-639, 343.5));
    cshape->setPoint(i++, Vector2f(317, 343.5));
    cshape->setPoint(i++, Vector2f(334, 341.5));
    cshape->setPoint(i++, Vector2f(366, 333.5));
    cshape->setPoint(i++, Vector2f(399, 318.5));
    cshape->setPoint(i++, Vector2f(425, 300.5));
    cshape->setPoint(i++, Vector2f(447, 279.5));
    cshape->setPoint(i++, Vector2f(467.5, 252));
    cshape->setPoint(i++, Vector2f(480.5, 227));
    cshape->setPoint(i++, Vector2f(490.5, 197));
    cshape->setPoint(i++, Vector2f(495.5, 165));
    cshape->setPoint(i++, Vector2f(494.5, -27));
    cshape->setPoint(i++, Vector2f(492.5, -43));
    cshape->setPoint(i++, Vector2f(488.5, -67));
    cshape->setPoint(i++, Vector2f(479.5, -90));
    cshape->setPoint(i++, Vector2f(474.5, -98));
    cshape->setPoint(i++, Vector2f(472.5, -105));
    cshape->setPoint(i++, Vector2f(462.5, -119));
    cshape->setPoint(i++, Vector2f(457.5, -129));
    cshape->setPoint(i++, Vector2f(449.5, -139));
    cshape->setPoint(i++, Vector2f(445, -141.5));
    cshape->setPoint(i++, Vector2f(443.5, -145));
    cshape->setPoint(i++, Vector2f(430, -152.5));
    cshape->setPoint(i++, Vector2f(421.5, -160));
    cshape->setPoint(i++, Vector2f(405, -169.5));
    cshape->setPoint(i++, Vector2f(384, -177.5));
    cshape->setPoint(i++, Vector2f(368, -178.5));
    cshape->setPoint(i++, Vector2f(365, -180.5));
    cshape->setPoint(i++, Vector2f(323, -180.5));
    cshape->setPoint(i++, Vector2f(298, -177.5));
    cshape->setPoint(i++, Vector2f(272, -167.5));
    cshape->setPoint(i++, Vector2f(258, -167.5));
    cshape->setPoint(i++, Vector2f(250, -172.5));
    cshape->setPoint(i++, Vector2f(246.5, -180));
    cshape->setPoint(i++, Vector2f(244.5, -191));
    cshape->setPoint(i++, Vector2f(244.5, -200));
    cshape->setPoint(i++, Vector2f(246, -200.5));
    cshape->setPoint(i++, Vector2f(246.5, -206));
    cshape->setPoint(i++, Vector2f(258.5, -220));
    cshape->setPoint(i++, Vector2f(268, -224.5));
    cshape->setPoint(i++, Vector2f(271, -227.5));
    cshape->setPoint(i++, Vector2f(300, -238.5));
    cshape->setPoint(i++, Vector2f(312, -239.5));
    cshape->setPoint(i++, Vector2f(318, -242.5));
    cshape->setPoint(i++, Vector2f(328, -243.5));
    cshape->setPoint(i++, Vector2f(331, -245.5));
    cshape->setPoint(i++, Vector2f(356, -245.5));
    cshape->setPoint(i++, Vector2f(379, -238.5));
    cshape->setPoint(i++, Vector2f(390, -239.5));
    cshape->setPoint(i++, Vector2f(394.5, -247));
    cshape->setPoint(i++, Vector2f(393.5, -266));
    cshape->setPoint(i++, Vector2f(385.5, -277));
    cshape->setPoint(i++, Vector2f(376, -280.5));
    cshape->setPoint(i++, Vector2f(373, -283.5));
    cshape->setPoint(i++, Vector2f(349, -288.5));
    cshape->setPoint(i++, Vector2f(327, -289.5));
    cshape->setPoint(i++, Vector2f(292, -289.5));
    cshape->setPoint(i++, Vector2f(281, -286.5));
    cshape->setPoint(i++, Vector2f(260, -284.5));
    cshape->setPoint(i++, Vector2f(256, -282.5));
    cshape->setPoint(i++, Vector2f(243, -281.5));
    cshape->setPoint(i++, Vector2f(240, -279.5));
    cshape->setPoint(i++, Vector2f(235, -279.5));
    cshape->setPoint(i++, Vector2f(232, -277.5));
    cshape->setPoint(i++, Vector2f(217, -274.5));
    cshape->setPoint(i++, Vector2f(211, -270.5));
    cshape->setPoint(i++, Vector2f(206, -270.5));
    cshape->setPoint(i++, Vector2f(183, -261.5));
    cshape->setPoint(i++, Vector2f(180.5, -259));
    cshape->setPoint(i++, Vector2f(168, -254.5));
    cshape->setPoint(i++, Vector2f(162, -250.5));
    cshape->setPoint(i++, Vector2f(155, -249.5));
    cshape->setPoint(i++, Vector2f(138, -242.5));
    cshape->setPoint(i++, Vector2f(126, -240.5));
    cshape->setPoint(i++, Vector2f(116, -233.5));
    cshape->setPoint(i++, Vector2f(108, -230.5));
    cshape->setPoint(i++, Vector2f(86, -228.5));
    cshape->setPoint(i++, Vector2f(69, -224.5));
    cshape->setPoint(i++, Vector2f(33, -224.5));
    cshape->setPoint(i++, Vector2f(27, -230.5));
    cshape->setPoint(i++, Vector2f(25.5, -235));
    cshape->setPoint(i++, Vector2f(35, -240.5));
    cshape->setPoint(i++, Vector2f(50, -243.5));
    cshape->setPoint(i++, Vector2f(63, -248.5));
    cshape->setPoint(i++, Vector2f(63.5, -250));
    cshape->setPoint(i++, Vector2f(68, -250.5));
    cshape->setPoint(i++, Vector2f(73, -254.5));
    cshape->setPoint(i++, Vector2f(80, -255.5));
    cshape->setPoint(i++, Vector2f(86, -261.5));
    cshape->setPoint(i++, Vector2f(91.5, -275));
    cshape->setPoint(i++, Vector2f(91.5, -287));
    cshape->setPoint(i++, Vector2f(88.5, -293));
    cshape->setPoint(i++, Vector2f(88.5, -297));
    cshape->setPoint(i++, Vector2f(85.5, -301));
    cshape->setPoint(i++, Vector2f(80, -303.5));
    cshape->setPoint(i++, Vector2f(36, -303.5));
    cshape->setPoint(i++, Vector2f(30, -301.5));
    cshape->setPoint(i++, Vector2f(22, -301.5));
    cshape->setPoint(i++, Vector2f(-3, -296.5));
    cshape->setPoint(i++, Vector2f(-32, -285.5));
    cshape->setPoint(i++, Vector2f(-37, -285.5));
    cshape->setPoint(i++, Vector2f(-46, -281.5));
    cshape->setPoint(i++, Vector2f(-54, -280.5));
    cshape->setPoint(i++, Vector2f(-239, -280.5));
    cshape->setPoint(i++, Vector2f(-270.5, -312));
    cshape->setPoint(i++, Vector2f(-320, -312.5));
    cshape->setPoint(i++, Vector2f(-352, -344.5));
    cshape->setPoint(i++, Vector2f(-544, -344.5));
    cshape->setPoint(i++, Vector2f(-559.5, -305));
    cshape->setPoint(i++, Vector2f(-634.5, -86));
    cshape->setPoint(i++, Vector2f(-640.5, -73));
    cshape->setPoint(i++, Vector2f(-640.5, -360));
    cshape->setPoint(i++, Vector2f(-639, -360.5));

    cshape->setPosition(640, 360);
    renderer->add(cshape);

    b2Vec2 rightWallVerts[32];
    for (i = 0; i < 64; i+=2) {
        rightWallVerts[i].Set(m_rightWall[i] / g_graphicsScale, m_rightWall[i + 1] / g_graphicsScale);
    }
    b2BodyDef bodyDef2;
    bodyDef2.position.Set(6.4, 3.6); // 1280 / 2 / 100, 720 / 2 / 100
    b2Body* body = world.CreateBody(&bodyDef2);
    b2ChainShape chain2;
    chain2.CreateChain(rightWallVerts, 32);
    b2FixtureDef fixtureDef2;
    fixtureDef2.shape = &chain2;
    fixtureDef2.density = 1.0f;
    fixtureDef2.friction = 0.3f;
    body->CreateFixture(&fixtureDef2);

    ConvexShape* rightWallShape = new ConvexShape();
    rightWallShape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
    rightWallShape->setPointCount(32);
    int vertCount = 0;
    for (i = 0; i < 64; i+=2) {
        rightWallShape->setPoint(vertCount, Vector2f(m_rightWall[i], m_rightWall[i + 1]));
        vertCount++;
    }
    rightWallShape->setPosition(640, 360);
    renderer->add(rightWallShape);
}
