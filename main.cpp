/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "vectorMath.h"
#include "movement.h"
#include <iostream>
#include <string>
#include <math.h>
 
#if defined(PLATFORM_RPI)
#define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
#define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else
#define XBOX360_NAME_ID     "Xbox 360 Controller"
#define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	Vector2 temp;
	temp.x = 0;
	temp.y = 0;

	InitWindow(screenWidth, screenHeight, "Ooer - OMAN I'M NOT VERY GOOD WITH COMPUTER PLZ HELP");

	SetTargetFPS(60);

	///////DEFINE WORLD//////////////////////////////////////////////////////////////////////
																						   
	b2Vec2 gravity(0.0f, 0.0f);															   
	b2World world(gravity);																   
																						   
	///////DEFINE FLOOR//////////////////////////////////////////////////////////////////////
																						   
	b2BodyDef groundBodyDef;															   
	groundBodyDef.position.Set(0.0f, 450.0f);											   
	b2Body* groundBody = world.CreateBody(&groundBodyDef);								   
	b2PolygonShape groundBox;															   
	groundBox.SetAsBox(800.0f, 10.0f);													   
	groundBody->CreateFixture(&groundBox, 0.0f);										   
																						   
	///////DEFINE PLAYER/////////////////////////////////////////////////////////////////////
	
	PlayerMovement *player = new PlayerMovement();
	b2BodyDef playerBodyDef;															   
	playerBodyDef.position.Set(800.0f/2, 450.0f/2);
	b2Body* playerBody = world.CreateBody(&playerBodyDef);
	b2CircleShape playerSphere;															   
	playerSphere.m_p.Set(0.0f,0.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
	player->body = playerBody;
																						   
	/////////////////////////////////////////////////////////////////////////////////////////

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		{
			int x = 0;
		
		
		}


		int x = 0;

		// Update
		Vector2 wishDir = { 0.0f, 0.0f };
		if (IsKeyDown(KEY_W)) {
			wishDir.y -= 1;
		}
		if (IsKeyDown(KEY_A)) {
			wishDir.x -= 1;
		}
		if (IsKeyDown(KEY_S)) {
			wishDir.y += 1;
		}
		if (IsKeyDown(KEY_D)) {
			wishDir.x += 1;
		}
		if (IsGamepadAvailable(GAMEPAD_PLAYER1)) {
			wishDir.x = GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_XBOX_AXIS_LEFT_X);
			wishDir.y = GetGamepadAxisMovement(GAMEPAD_PLAYER1, GAMEPAD_XBOX_AXIS_LEFT_Y);
			if (0.2f>dist(wishDir, { 0.0f,0.0f })) {
				wishDir = { 0,0 };
			}
		}
		Accelerate(player, wishDir, 100.0f, 100.0f, GetFrameTime());
		player->velocity.y += (player->velocity.y>0) ? GetFrameTime() * 1000 : GetFrameTime() * 360;
		UpdatePos(player, GetFrameTime());

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawCircleV(b2Vec2toVector2(player->body->GetPosition()), 5.0f, RED);
		DrawRectangle(0, 440, 800, 10, BLACK);
		DrawText(std::to_string(GetFrameTime()).c_str(), 190, 200, 20, LIGHTGRAY);


		char buffer[50];

		sprintf_s(buffer, "x: %f, y: %f", wishDir.x, wishDir.y);

		DrawText(buffer, 190, 220, 20, GRAY);

		//std::cout << GetFPS() << std::endl;

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}