#pragma once
#include "sfwdraw.h"
#include "GameObject.h"
#include "Animations.h"

class GameState;

class Player : public GameObject {
public:
	float angularSpeed;

	float vel;
	float acc;
	float maxVel;
	float dragVel;

	float bulletSpeed;
	float firedelay;
	float rateOfFire;

	Player();
	void playerMove();
	void playerGun();
	void onUpdate();
	
};