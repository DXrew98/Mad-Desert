#pragma once
#include "GameObject.h"


class GameState;

class EnemySpeedy : public GameObject {
public:
	vec2 dir;
	float angularSpeed;
	float goalAngle;
	float difAngle;

	std::string carTexture;

	float vel;
	float acc;
	float maxVel;
	float dragVel;
	//float maxAcc;
	//float angularSpeedMax;
	
	float numberOfEnemies;

	bool inCollision;

	EnemySpeedy();
	EnemySpeedy(float x, float y, float enemyNum);
	void playerTracking(float posX, float posY);
	void checkCollision();
	void onCollision(GameObject &go, float distance);
	void enUpdate();

	void draw2(vec2 cam, int drawAngle);
};