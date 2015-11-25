#include"EnemySpeedy.h"
#include"Player.h"
#include "GameObject.h"
#include "Animations.h"
#include "sfwdraw.h"
#include"GameState.h"


EnemySpeedy::EnemySpeedy() {

	textureName = "EnemyS";

	dir = { 0,0 };
	pos = { 0,0 };
	vel = 0;
	acc = 0;
	dim = { 50, 50 };
	angle = -180;
	angularSpeed = 40.0f;
	speed = 120;

	dragVel = 20;
	maxVel = 320;
}

void EnemySpeedy::playerTracking(float posX, float posY)
{
	
	/*Direction choosing*/
	dir.x = posX - pos.x;
	dir.y = posY - pos.y;

	goalAngle =  atan2(dir.y, dir.x);

	/*difAngle = angle - goalAngle;
	if (difAngle < PI) difAngle += 2 * PI;
	else if (difAngle > PI) difAngle -= 2 * PI;
	if (difAngle > 0.0) angle -= sfw::getDeltaTime() * angularSpeed;
	else if (difAngle < 0.0) angle += sfw::getDeltaTime() * angularSpeed;*/

	if (angle < goalAngle) angle += sfw::getDeltaTime() * angularSpeed;
	else				   angle -= sfw::getDeltaTime() * angularSpeed;


	//AI Movement 
	/*acc = speed;*/

	vel = vel + (acc - dragVel) * sfw::getDeltaTime();

	vel = std::fmaxf(0, vel);
	vel = std::fminf(vel, maxVel);

	pos = { pos.x + vel * cosf(angle * PI / 180) * sfw::getDeltaTime(),
		    pos.y + vel * sinf(angle * PI / 180) * sfw::getDeltaTime() };
}

void EnemySpeedy::checkCollision()
{
}

void EnemySpeedy::onCollision()
{
}

void EnemySpeedy::enUpdate()
{
}
