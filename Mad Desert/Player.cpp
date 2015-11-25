#include "Player.h"
#include "GameObject.h"
#include "Animations.h"
#include "sfwdraw.h"
#include"GameState.h"

Player::Player() {

	textureName =  "PlayerTruck";
	textureName2 = "PlayerAim";

	pos			 = { -750,-750 };
	vel			 = 0;
	acc			 = 0;
	dim			 = { 75, 75 };
	angle		 = 90;
	angularSpeed = 60;
	speed		 = 120;
	
	dragVel		 = 20;
	maxVel		 = 320;

	bulletSpeed = 10;
	rateOfFire = .2f;
	firedelay = .0f;
}

void Player::playerMove()
{
	acc = 0;
	if (sfw::getKey('W'))
	{
		acc = speed;
	}

	if (sfw::getKey('S'))
	{
		acc -=  (speed * 2);
	}

	if (sfw::getKey('A') && vel > 10.f)
	{
		Player::angle += sfw::getDeltaTime() * angularSpeed;
	}

	if (sfw::getKey('D') && vel > 10.f)
	{
		Player::angle -= sfw::getDeltaTime() * angularSpeed;
	}


	vel = vel + (acc - dragVel) * sfw::getDeltaTime();
	
	vel = std::fmaxf(0, vel);
	vel = std::fminf(vel, maxVel);

	pos = { pos.x + vel * cosf(angle * PI / 180) * sfw::getDeltaTime(),
			pos.y + vel * sinf(angle * PI / 180) * sfw::getDeltaTime() };

}


void Player::playerGun(){
	firedelay -= sfw::getDeltaTime();
	if (sfw::getMouseButton(0) && firedelay < 0) {
 		firedelay = rateOfFire;

		// direction from the truck to the mouse position
		// cam = { Max.pos.x + 400, Max.pos.y + 300 };
		//
		
		float dirx = 400 - sfw::getMouseX();
		float diry = 300 - sfw::getMouseY();

		float distance = sqrt(dirx*dirx + diry*diry);		

		float velx = dirx/distance * 1000;
		float vely = diry/distance * 1000;

		//float angle = atan2f(diry, dirx);
		//velx = cos(angle) * 1000;
		//vely = sin(angle) * 1000;

		gs()->makeBullets(pos.x, pos.y, velx, vely, 0.5f);
	}
}

void Player::onUpdate()
{
	playerMove();
	playerGun();
}


