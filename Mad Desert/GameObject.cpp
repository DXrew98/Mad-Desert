#include "GameObject.h"




void GameObject::draw(vec2 cam) {
	sfw::drawTexture(getTexture(textureName), cam.x - pos.x, cam.y - pos.y, dim.x, dim.y, angle-90, true);
	
}

GameState *& GameObject::gs()
{
	static GameState *game;
	return game;
}

void GameObject::update() {
	animTimer += sfw::getDeltaTime();
	currentFrame;

	onUpdate();
	
}
