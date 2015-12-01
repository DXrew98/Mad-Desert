#include "Menu.h"
#include "Animations.h"
#include "sfwdraw.h"

void splash()
{
	
}

STATE mainMenu(){
	draw();
	if (sfw::getMouseButton(0)) { return PLAY; }
	if (sfw::getMouseButton(1)) { return EXIT; }
	
}

void draw()
{
	sfw::drawTexture(getTexture("Splash"), 400, 150, 1000, 1000, 0, true);
	sfw::drawTexture(getTexture("Exit"), 400, -50, 400, 400, 0, true);
	sfw::drawTexture(getTexture("PlayerAim"), sfw::getMouseX(), sfw::getMouseY(), sfw::getTextureWidth(getTexture("PlayerAim")) / 15, sfw::getTextureHeight(getTexture("PlayerAim")) / 15);
}

