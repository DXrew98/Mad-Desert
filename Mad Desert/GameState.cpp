#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "EnemySpeedy.h"
#include "collisionsTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

GameState::GameState()
{
	textureMap = "GameMap";
	GameObject::gs() = this;
}

void GameState::makeBullets(float x, float y, float dx, float dy, float lifetime)
{
	for (int i = 0; i < bullets.size(); ++i){
		if (!bullets[i].isActive){
			bullets[i] = Bullet(x, y, dx, dy, lifetime);
				return;
		}
	}
	bullets.push_back(Bullet(x, y, dx, dy, lifetime));
}

void GameState::bulletUpdate()
{
	int nBulletsActive = 0;

	for (int i = 0; i < bullets.size(); ++i)
		if (bullets[i].isActive) {
			bullets[i].update();
		}
		else nBulletsActive++;
}

void GameState::makeEnemyS(float x, float y, float enemyNum)
{
	// search for an inactive enemy to recycle
	for (int i = 0; i < enemyS.size(); ++i)
		if (!enemyS[i].isActive) {
			enemyS[i] = EnemySpeedy(x, y, enemyNum);
			return;
		}

	enemyS.push_back(EnemySpeedy(x, y, enemyNum));
}

void GameState::EnemySUpdate()
{
	int nEnemySActive = 0;

	for (int i = 0; i < enemyS.size(); ++i) {
		if (enemyS[i].isActive) {
			enemyS[i].playerTracking(Max.pos.x, Max.pos.y);
			enemyS[i].enUpdate();
		}
		else nEnemySActive++;
	}
}

float GameState::randX()
{
	float x = rand() % 2000;
	if (rand() % 2 == 0) x = x * -1;
	return x;
}

float GameState::randY()
{
	float y = rand() % 2000;
	if (rand() % 2 == 0) y = y * -1;
	return y;
}





void GameState::update()
{
	if (Max.isActive) Max.update();
	cam = { Max.pos.x - 400, Max.pos.y - 300 };
	for (int i = 0; i < bullets.size(); ++i) {
		if (bullets[i].isActive)
			bulletUpdate();
	}
	

	int activeEnemyCount = 0;
	int desiredEnemyCount = 10;

	for (int i = 0; i < enemyS.size(); ++i) {
		if (enemyS[i].isActive)
			activeEnemyCount++;
	}

	for (int i = activeEnemyCount; i < desiredEnemyCount; ++i)
	{
		makeEnemyS(randX(), randY(), 0);
	}

	EnemySUpdate();
	
	for (int i = 0; i < enemyS.size(); ++i) 
		doCollision(Max, enemyS[i]);

	for (int i = 0; i < bullets.size(); ++i){
		for (int j = 0; j < enemyS.size(); ++j)
		{
			doCollision(bullets[i], enemyS[j]);
		}
	}
	
}

void GameState::draw()
{
	sfw::drawTexture(getTexture(textureMap), -3500 - cam.x, 3500 - cam.y, 8000, 6000, true, 0, 0x00000000);
	if(Max.isActive) Max.draw(cam, 90);
	for (int i = 0; i < enemyS.size(); ++i) {
		if (enemyS[i].isActive)
			enemyS[i].draw2(cam, 90);
	}
	sfw::drawTexture(getTexture("PlayerAim"), sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(getTexture("PlayerAim")) / 15, sfw::getTextureHeight(getTexture("PlayerAim")) / 15);
	for (int i = 0; i < bullets.size(); ++i) {
		if (bullets[i].isActive)
			bullets[i].draw(cam);
	}
}


