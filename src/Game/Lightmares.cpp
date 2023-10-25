#include "Lightmares.h"
#include "GameObject.h"

#include "raylib/raylib.h"

const char* GAME_NAME = "Lightmares";
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAME_RATE = 60;

const Color BACKGROUND_COLOR({ 255,255,255,127 });

Lightmares::Lightmares()
{
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
	SetTargetFPS(FRAME_RATE);
}

Lightmares::~Lightmares()
{
	CloseWindow();
}

void Lightmares::Setup()
{
	// Add any gameObject
}

void Lightmares::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();

		// Update the GameObjets
		Update();

		//Draw the GameObjects
		Draw();

		EndDrawing();
	}
}

void Lightmares::Update()
{
	for (GameObject* gameObject : mGameObjects)
	{
		if (!gameObject) continue;

		gameObject->Update();
	}
}

void Lightmares::Draw()
{
	// Clear the background with the background color
	ClearBackground(RAYWHITE);

	// Draw
	for (GameObject* gameObject : mGameObjects)
	{
		if (!gameObject) continue;

		gameObject->Draw();
	}
}

void Lightmares::AddGameObject(GameObject* gameObject)
{
	gameObject->Start();
	mGameObjects.push_back(gameObject);
}
