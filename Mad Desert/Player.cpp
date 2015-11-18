#include "Player.h"
#include "GameObject.h"
#include "Animations.h"
#include "sfwdraw.h"
#include"GameState.h"

Player::Player() {

	textureName =  "PlayerTruck";
	textureName2 = "PlayerAim";

	pos			 = { 0,0 };
	vel			 = 0;
	acc			 = 0;
	dim			 = { 75, 75 };
	angle		 = 90;
	angularSpeed = 60;
	speed		 = 120;
	
	dragVel		 = 10;
	maxVel		 = 320;

	bulletSpeed = 100;
	rateOfFire = 0.1f;
	firedelay = 0.f;
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
	if (sfw::getMouseButton('0') && firedelay < 0) {
		firedelay = rateOfFire;
		gs()->makeBullets(pos.x, pos.y, 0, 300, 4.f);
	}
}

void Player::onUpdate()
{
	playerMove();
	playerGun();
}


