#include "sfwdraw.h"
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Animations.h"



int main() {

	sfw::initContext(800, 600, "NSFW Draw");

	
	//unsigned b = sfw::loadTextureMap("./Art_Assets/GameMap.png");
	loadTexture("PlayerTruck", "./Art_Assets/truck.png", 1, 1);
	loadTexture("PlayerAim", "./Art_Assets/clover.png", 1, 1);
	loadTexture("GameMap", "./Art_Assets/GameMap.png", 1, 1);

	GameState game;
	
	while (sfw::stepContext()) {
		game.update();
		game.draw();
	}

	sfw::termContext();
}