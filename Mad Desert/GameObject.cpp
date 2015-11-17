#include "GameObject.h"
#include "Player.h"



void GameObject::draw(vec2 cam) {
	sfw::drawTexture(getTexture(textureName), cam.x - pos.x, cam.y - pos.y, dim.x, dim.y, angle-90, true);
	
}

void GameObject::update() {
	animTimer += sfw::getDeltaTime();
	currentFrame;

	onUpdate();
}