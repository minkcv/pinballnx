#include "util.h"

float g_graphicsScale = 100.0f;

Vector2<float> rotateVector(Vector2<float> in, double radians) {
    float x = cos(radians) * in.x + sin(radians) * in.y;
    float y = sin(radians) * in.x - cos(radians) * in.y;
    Vector2<float> result(x, y);
    return result;
}

b2Vec2* getVertexArray(float* points, int numPoints) {
    b2Vec2* vs = (b2Vec2*)malloc(sizeof(b2Vec2) * numPoints);
    for (int i = 0; i < numPoints * 2; i+=2) {
        vs[i / 2].Set(points[i] / g_graphicsScale, points[i + 1] / g_graphicsScale);
    }
    return vs;
}

void addPointsToShape(ConvexShape* shape, float* points, int numPoints) {
    shape->setPointCount(numPoints);
    int vertCount = 0;
    for (int i = 0; i < numPoints * 2; i+=2) {
        shape->setPoint(vertCount, Vector2f(points[i], points[i + 1]));
        vertCount++;
    }
}

void createTriangles(C2DRenderer* renderer, float* points, int numTriangles) {
    for (int i = 0; i < numTriangles * 6; i+=6) {
        ConvexShape* shape = new ConvexShape();
        shape->setPointCount(3);
        shape->getVertexArray()->setPrimitiveType(PrimitiveType::LineStrip);
        for (int t = 0; t < 6; t+=2) {
            shape->setPoint(t / 2, Vector2f(points[i + t], points[i + t + 1]));
        }
        renderer->add(shape);
    }
}

void createFixturesFromPoints(b2Body* body, float* points, int numPoints) {
    b2FixtureDef fd;
    fd.friction = 0.6f;
    fd.density = 1.0f;
    for (int i = 0; i < numPoints; i+=6) {
        b2PolygonShape shape;
        b2Vec2 vs[3];
        vs[0].Set(points[i] / g_graphicsScale, points[i+1] / g_graphicsScale);
        vs[1].Set(points[i+2] / g_graphicsScale, points[i+3] / g_graphicsScale);
        vs[2].Set(points[i+4] / g_graphicsScale, points[i+5] / g_graphicsScale);
        shape.Set(vs, 3);
        fd.shape = &shape;
        body->CreateFixture(&fd);
    }
}