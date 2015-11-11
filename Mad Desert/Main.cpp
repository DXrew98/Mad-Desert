#include "sfwdraw.h"
#include "GameObject.h"
#include "Player.h"
#include "Animations.h"


int main() {

	sfw::initContext(800, 600, "NSFW Draw");

	unsigned b = sfw::loadTextureMap("./Art_Assets/0.png");
	loadTexture("PlayerTruck", "./Art_Assets/truck.png", 1, 1);
	Player Max;
	Max.textureName = "PlayerTruck"; 


	while (sfw::stepContext()) {
		sfw::drawTexture(b, 0, 600, 800, 600, false, 0, 0x00000000);
		Max.draw();
	}

	sfw::termContext();
}