#pragma once
#include "sfwdraw.h"
#include "Animations.h"
#include <string>

struct vec2 {

	int x, y;
};

class GameObject{
public:
	vec2 pos;
	vec2 dim;
	int angle;
	int health;
	int speed;
	std::string textureName;

	virtual void draw()
	{
		sfw::drawTexture(getTexture(textureName), pos.x, pos.y, dim.x, dim.y, angle, true);
	}
};