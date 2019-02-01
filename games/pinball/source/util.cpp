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
