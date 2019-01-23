#include "util.h"

float g_graphicsScale = 100.0f;

Vector2<float> rotateVector(Vector2<float> in, double radians) {
    float x = cos(radians) * in.x + sin(radians) * in.y;
    float y = sin(radians) * in.x - cos(radians) * in.y;
    Vector2<float> result(x, y);
    return result;
}