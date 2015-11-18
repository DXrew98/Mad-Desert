#pragma once
#include "sfwdraw.h"
#include "Animations.h"
#include <string>

class GameState;

struct vec2 {

	float x, y;
};



class GameObject{
public:
	static GameState *&gs();

	GameObject() : isActive(true) {}

	vec2 pos;
	vec2 dim;

	float angle;
	int health;
	float speed;
	bool isActive;

	float animTimer;
	unsigned currentFrame;

	std::string textureName;
	std::string textureName2;

	virtual void update();
	virtual void onUpdate() {}

	virtual void draw(vec2 cam);
};