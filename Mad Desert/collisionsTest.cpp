#include <cmath>
#include "collisionsTest.h"
#include "GameObject.h"

float itest_Circle(float x1, float y1, float r1, float x2, float y2, float r2) {
					return (r1 + r2) - sqrtf((x1 - x2)*(x1 - x2) + (y1 - y2)* (y1 - y2));
}

float doCollision(GameObject &go1, GameObject &go2)
{
	float distance = itest_Circle(go1.pos.x, go1.pos.y, go1.radius, go2.pos.x, go2.pos.y, go2.radius);
	if (distance > 0)
	{
		go1.onCollision(go2, distance);
		go2.onCollision(go1, distance);
	}
	return distance;
}