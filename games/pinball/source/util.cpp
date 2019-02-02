#include "util.h"

float g_graphicsScale = 100.0f;

b2Vec2* getVertexArray(std::vector<float> points) {
    b2Vec2* vs = (b2Vec2*)malloc(sizeof(b2Vec2) * points.size() / 2);
    for (size_t i = 0; i < points.size(); i+=2) {
        vs[i / 2].Set(points.at(i) / g_graphicsScale, points.at(i + 1) / g_graphicsScale);
    }
    return vs;
}

void addPointsToShape(ConvexShape* shape, std::vector<float> points) {
    shape->setPointCount(points.size() / 2);
    int vertCount = 0;
    for (size_t i = 0; i < points.size(); i+=2) {
        shape->setPoint(vertCount, Vector2f(points.at(i), points.at(i + 1)));
        vertCount++;
    }
}