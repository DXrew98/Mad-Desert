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
	std::vector<EnemySpeedy> enemyS;
	

	vec2 cam;
	std::string textureMap;

	EnemySpeedy ESOne;
	

public:
	GameState();

	void update();
	void draw();

	void makeBullets(float x, float y, float dx, float dy, float lifespan);
	void bulletUpdate();
	void makeEnemyS(float x, float y, float enemyNum);
	void EnemySUpdate();

	float randX();
	float randY();
};


