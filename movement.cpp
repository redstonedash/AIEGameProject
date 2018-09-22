#include "vectorMath.h"
#include "raylib.h"
#include "vectorMath.h"
#include "movement.h"
#include <cstdio>
#include <cmath>

void Accelerate(PlayerMovement *pm, Vector2 wishdir, float wishspeed, float accel, float dt) {
	int			i;
	float		addspeed, accelSpeed, currentSpeed;

	currentSpeed = dotProduct(pm->velocity, wishdir);
	addspeed = wishspeed - currentSpeed;
	if (addspeed <= 0) {
		return;
	}
	accelSpeed = accel * dt*wishspeed;

	if (accelSpeed > addspeed) {
		accelSpeed = addspeed;
	}

		pm->velocity = (pm->velocity) + (accelSpeed * wishdir);
	
}

void UpdatePos(PlayerMovement *pm, float dt) 
{
	Vector2 temp = b2Vec2toVector2(pm->body->GetPosition()) + pm->velocity*dt;
	pm->body->SetTransform(b2Vec2(temp.x, temp.y), pm->body->GetAngle());
}
