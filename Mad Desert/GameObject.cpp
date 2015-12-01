#include "GameObject.h"
#include <iostream>



void GameObject::draw(vec2 cam, int drawAngle)
{
	sfw::drawTexture(getTexture(textureName), pos.x - cam.x, pos.y - cam.y, dim.x, dim.y, angle - drawAngle, true);	
}

//void GameObject::draw2(vec2 cam, int drawAngle) {
//	sfw::drawTexture(getTexture(textureName), pos.x - cam.x, pos.y - cam.y, 40, 40, angle - drawAngle, true);
//}

void GameObject::onCollision(GameObject & go, float distance)
{
}


GameState *& GameObject::gs()
{
	static GameState *game;
	return game;
}

void GameObject::update() {
	onUpdate();
}
