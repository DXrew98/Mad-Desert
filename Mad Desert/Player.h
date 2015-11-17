#pragma once
#include "sfwdraw.h"
#include "GameObject.h"
#include "Animations.h"

class Player : public GameObject {
public:
	float angularSpeed;

	float vel;
	float acc;
	float maxVel;
	float dragVel;

	Player();
	void playerMove();
	void playerGun();
	void onUpdate();
	
};