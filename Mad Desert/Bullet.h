#pragma once
#include "GameObject.h"

class Bullet : public GameObject{

	float velx, vely;
	float lifespan;
	std::string BulletTexture;
	

public:
	Bullet(float a_x, float a_y, float dx, float dy, float lifetime); 


	virtual void update();
	virtual void draw(vec2 cam);

	void onCollision(GameObject &go, float distance);
};