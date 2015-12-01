#include "sfwdraw.h"
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Animations.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {

	sfw::initContext(800, 600, "NSFW Draw");

	loadTexture("PlayerTruck", "./Art_Assets/truck.png", 1, 1);
	loadTexture("PlayerAim", "./Art_Assets/clover.png", 1, 1);
	loadTexture("GameMap", "./Art_Assets/GameMap.png", 1, 1);
	loadTexture("Bullet", "./Art_Assets/Bullet1.png", 1, 1);
	loadTexture("EnemyS", "./Art_Assets/Audi.png", 1, 1);

	GameState game;
	
	srand(time(NULL));

	while (sfw::stepContext()) {
		game.update();
		game.draw();
		std::cout << "You've been haaacked Boiiiiii" << std::endl;
	}

	sfw::termContext();
}