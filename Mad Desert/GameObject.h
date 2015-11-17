#pragma once
#include "sfwdraw.h"
#include "Animations.h"
#include <string>

struct vec2 {

	float x, y;
};

class GameObject{
public:
	vec2 pos;
	vec2 dim;
	float angle;
	int health;
	int speed;
	std::string textureName;
	std::string textureName2;
	float animTimer;
	unsigned currentFrame;

	virtual void update();
	virtual void onUpdate() {}

	virtual void draw(vec2 cam);
};