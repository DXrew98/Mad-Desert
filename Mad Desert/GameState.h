#pragma once
#include "Player.h"
#include "EnemySpeedy.h"
#include "GameObject.h"
#include "Animations.h"
#include "sfwdraw.h"
#include "Bullet.h"
#include <string>
#include <vector>

class GameState {

	Player Max;
	std::vector<Bullet> bullets;
	std::vector<EnemySpeedy> Enemy_N_S;
	std::vector<EnemySpeedy> Enemy_E_W;

	vec2 cam;
	std::string textureMap;

	EnemySpeedy ESOne;
	

public:
	GameState();

	void update();
	void draw();

	void makeBullets(float x, float y, float dx, float dy, float lifespan);
	void bulletUpdate();
	void Enemy_E_W_Update();
};


