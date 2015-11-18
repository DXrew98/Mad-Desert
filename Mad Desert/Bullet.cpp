#include "Bullet.h"

Bullet::Bullet(float a_x, float a_y, float dx, float dy, float lifetime){

		pos.x = a_x;
		pos.y = a_y;

		velx = dx;
		vely = dy;

		lifespan = lifetime;
}

void Bullet::update()
{
	GameObject::update();
	lifespan -= sfw::getDeltaTime();
	isActive = lifespan > 0;

	pos.x += velx * sfw::getDeltaTime();
	pos.y += vely * sfw::getDeltaTime();
}

void Bullet::draw() { sfw::drawLine(pos.x, pos.y, dim.x, dim.y + 20, YELLOW); }