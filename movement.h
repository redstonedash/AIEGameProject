#pragma once
#include "Box2D/Box2D.h"
struct PlayerMovement {
	//Vector2 pos = {0.0f,0.0f};
	b2Body* body;
	Vector2 velocity = {0.0f,0.0f};
};
void Accelerate(PlayerMovement *pm, Vector2 wishdir, float wishspeed, float accel, float dt);
void UpdatePos(PlayerMovement *pm, float dt);
