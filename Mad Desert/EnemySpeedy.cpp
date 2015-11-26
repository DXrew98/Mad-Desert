#include "EnemySpeedy.h"
#include "Player.h"
#include "GameObject.h"
#include "Animations.h"
#include "sfwdraw.h"
#include "GameState.h"
#include "collisionsTest.h"


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

//Tring to get the ai to track the player
//inline float normAngle(float ang) {
//	float M_PI = 0;
//	return ang < -M_PI ? ang + 2.0*M_PI : (ang > M_PI ? ang - 2.0*M_PI : ang);
//}
//
//inline float limitValue(float x, float min, float max) {
//	return x < min ? min : (x > max ? max : x);
//}
//
//void EnemySpeedy::playerTracking(float posX, float posY)
//{
//	
//	///*Direction choosing*/
//	//dir.x = posX - pos.x;
//	//dir.y = posY - pos.y;
//
//	//goalAngle =  atan2(dir.y, dir.x);
//
//	///*difAngle = angle - goalAngle;
//	//if (difAngle < PI) difAngle += 2 * PI;
//	//else if (difAngle > PI) difAngle -= 2 * PI;
//	//if (difAngle > 0.0) angle -= sfw::getDeltaTime() * angularSpeed;
//	//else if (difAngle < 0.0) angle += sfw::getDeltaTime() * angularSpeed;*/
//
//	//if (angle < goalAngle) angle += sfw::getDeltaTime() * angularSpeed;
//	//else				   angle -= sfw::getDeltaTime() * angularSpeed;
//
//
//	//AI Movement 
//	acc = speed;
//
//	vel = vel + (acc - dragVel) * sfw::getDeltaTime();
//
//	vel = std::fmaxf(0, vel);
//	vel = std::fminf(vel, maxVel);
//
//	pos = { pos.x + vel * cosf(angle * PI / 180) * sfw::getDeltaTime(),
//		    pos.y + vel * sinf(angle * PI / 180) * sfw::getDeltaTime() };
//
//	//Direction choosing, pos is a member of EnemySpeedy
//	float dirX = posX - pos.x;
//	float dirY = posY - pos.y;
//
//	//Angle choosing; angle, angularSpeed and angularSpeedMax are members of EnemySpeedy
//	float goalAngle = atan2(dirY, dirX);
//	float difAngle = normAngle(angle - goalAngle);
//	angularSpeed = limitValue(-difAngle, -angularSpeedMax, angularSpeedMax);
//	float dt = sfw::getDeltaTime();
//	angle = normAngle(angle + dt * angularSpeed);
//
//	// Update speed; acc, vel, etc. are members of EnemySpeedy class
//	// acc = speed;         // it seems odd to me...
//	// vel = limitValue(vel + (acc - dragVel) * dt, 0.0, maxVel);
//	// what about:
//	acc = (difAngle > 1.5 || difAngle < -1.5) ? -maxAcc / 2.0 : maxAcc*(maxVel - vel) / maxVel;
//	//          brake if direction is wrong, go to limit velocity otherwise
//	acc = limitValue(acc, -maxAcc, maxAcc);
//	vel = limitValue(vel + acc * dt, 0.0, maxVel);
//
//	// Update position
//	pos.x += vel * cos(angle) * dt;
//	pos.y += vel * sin(angle) * dt;
//}

void EnemySpeedy::checkCollision()
{
}

void EnemySpeedy::onCollision()
{
}

void EnemySpeedy::enUpdate()
{
	/*acc = speed;*/

	vel = vel + (acc - dragVel) * sfw::getDeltaTime();

	vel = std::fmaxf(0, vel);
	vel = std::fminf(vel, maxVel);

	pos = { pos.x + vel * cosf(angle * PI / 180) * sfw::getDeltaTime(),
		pos.y + vel * sinf(angle * PI / 180) * sfw::getDeltaTime() };
}
