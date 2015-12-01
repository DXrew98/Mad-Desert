#include "Bullet.h"
#include "GameState.h"
#include <iostream>


Bullet::Bullet(float a_x, float a_y, float dx, float dy, float lifetime){

		pos.x = a_x;
		pos.y = a_y;

		velx = -dx;
		vely = -dy;

		radius = 10;
		lifespan = lifetime;

		BulletTexture = "Bullet";
}

void Bullet::onCollision(GameObject &go, float distance) {
	isActive = false;
}

void Bullet::update()
{
	GameObject::update();
	lifespan -= sfw::getDeltaTime();
	isActive = lifespan > 0;

	pos.x += velx * sfw::getDeltaTime();
	pos.y += vely * sfw::getDeltaTime();
}

void Bullet::draw(vec2 cam) {
	sfw::drawTexture(getTexture(BulletTexture),  pos.x - cam.x, pos.y - cam.y, sfw::getTextureWidth(getTexture(BulletTexture)) / 3, sfw::getTextureHeight(getTexture(BulletTexture)) / 3); }