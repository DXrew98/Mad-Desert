#pragma once
#include "Player.h"
#include "GameObject.h"
#include "Animations.h"
#include "sfwdraw.h"
#include "Bullet.h"
#include <string>
#include <vector>

class GameState {

	Player Max;
	std::vector<Bullet> bullets;

	vec2 cam;
	std::string textureMap;

	

public:
	GameState();

	void update();
	void draw();

	void makeBullets(float x, float y, float dx, float dy, float lifespan);
	void bulletUpdate();
};


