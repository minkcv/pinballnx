#ifndef UTIL_H_
#define UTIL_H_

#include "cross2d/c2d.h"
#include <Box2D/Box2D.h>

using namespace c2d;

// The pinball is 0.1m in diameter in Box2D units.
// The graphical diameter of the pinball should be 10 pixels.
// Thus the conversion from Box2D units to pixels is a factor of 100.
extern float g_graphicsScale;

Vector2<float> rotateVector(Vector2<float> in, double radians);

b2Vec2* getVertexArray(float* points, int numPoints);

void addPointsToShape(ConvexShape* shape, float* points, int numPoints);

#endif