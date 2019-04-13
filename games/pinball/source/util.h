#ifndef UTIL_H_
#define UTIL_H_

#include <Box2D/Box2D.h>
#include <vector>
#include "cross2d/c2d.h"

#define DEBUG 1

using namespace c2d;

// The box2d coordinates are not pixel coordinates because they are in meters.
// The graphics need to be 1280x720, but it would be very bad if the pinball table was 
// 1280 meters long. 
extern float g_graphicsScale;

b2Vec2* getVertexArray(std::vector<float> points);

void addPointsToShape(ConvexShape* shape, std::vector<float> points);

#endif