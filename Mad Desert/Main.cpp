#include "sfwdraw.h"
#include "GameObject.h"
#include "Player.h"
#include "Animations.h"


int main() {

	sfw::initContext(800, 600, "NSFW Draw");

	unsigned b = sfw::loadTextureMap("./Art_Assets/GameMap.png");
	loadTexture("PlayerTruck", "./Art_Assets/truck.png", 1, 1);
	loadTexture("PlayerAim", "./Art_Assets/clover.png", 1, 1);

	Player Max;
	
	while (sfw::stepContext()) {
		vec2 cam = { Max.pos.x + 400, Max.pos.y + 300 };
		sfw::drawTexture(b, -3500 - cam.x, 3500 - cam.y, 8000, 6000, true, 0, 0x00000000);
		Max.draw(cam);
		Max.update();
	}

	sfw::termContext();
}