#pragma once
#include "GameObject.h"


class GameState;

class EnemySpeedy : public GameObject {
public:
	vec2 dir;
	float angularSpeed;
	float goalAngle;
	float difAngle;

	float vel;
	float acc;
	float maxVel;
	float dragVel;

	bool inCollision;

	EnemySpeedy();
	void playerTracking(float posX, float posY);
	void checkCollision();
	void onCollision();
	void enUpdate();
};