#include "GameState.h"
#include "GameObject.h"
#include "Player.h"

GameState::GameState()
{
	textureMap = "GameMap";
	GameObject::gs() = this;
}

void GameState::makeBullets(float x, float y, float dx, float dy, float lifespan)
{
	for (int i = 0; i < bullets.size(); ++i){
		if (!bullets[i].isActive){
			bullets[i] = Bullet(x, y, dx, dy, lifespan);
				return;
		}
	}
	bullets.push_back(Bullet(x, y, dx, dy, lifespan));
}

void GameState::bulletUpdate()
{
	int nBulletsActive = 0;

	/*for (int i = 0; i < bullets.size(); ++i)
		if (bullets[i].isActive) {
			bullets[i].update();
			if (Max.isActive);
		}*/
}

void GameState::update()
{
	if (Max.isActive) Max.update();
	cam = { Max.pos.x + 400, Max.pos.y + 300 };
}

void GameState::draw()
{
	sfw::drawTexture(getTexture(textureMap), -3500 - cam.x, 3500 - cam.y, 8000, 6000, true, 0, 0x00000000);
	if(Max.isActive) Max.draw(cam);
	sfw::drawTexture(getTexture("PlayerAim"), sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(getTexture("PlayerAim")) / 14, sfw::getTextureHeight(getTexture("PlayerAim")) / 14);
	for (int i = 0; i < bullets.size(); ++i) {
		if (bullets[i].isActive)
			bullets[i].draw();
	}
}

