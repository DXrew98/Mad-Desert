#include "Bullet.h"
#include "GameState.h"


Bullet::Bullet(float a_x, float a_y, float dx, float dy, float lifetime){

		pos.x = a_x;
		pos.y = a_y;

		velx = dx;
		vely = dy;

		lifespan = lifetime;

		BulletTexture = "Bullet";
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
	sfw::drawTexture(getTexture(BulletTexture), cam.x - pos.x, cam.y - pos.y, sfw::getTextureWidth(getTexture(BulletTexture)) / 3, sfw::getTextureHeight(getTexture(BulletTexture)) / 3); }