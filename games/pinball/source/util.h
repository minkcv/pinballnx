#ifndef UTIL_H_
#define UTIL_H_

#include <Box2D/Box2D.h>
#include <vector>
#include "cross2d/c2d.h"

#define DEBUG 1

using namespace c2d;


// You can change the 60.0f to the refresh rate of your monitor.
// If you have a 120hz monitor and you leave this at 1/60 then 
// the game runs twice as fast as on the switch and the physics can get messed up.
// Like the flippers can fall off the board, so this really has to match the monitor rate.
// And in the case of the switch, the refresh rate is 60.
// Anything that counts frames during table update needs to divide by this.
// See trigger.h kicker.h
extern float g_displayFrameRate;

// The box2d coordinates are not pixel coordinates because they are in meters.
// The graphics need to be 1280x720, but it would be very bad if the pinball table was 
// 1280 meters long. 
extern float g_graphicsScale;

b2Vec2* getVertexArray(std::vector<float> points, float xOffset = 0, float yOffset = 0);

void addPointsToShape(ConvexShape* shape, std::vector<float> points, float xOffset = 0, float yOffset = 0);

#endif
