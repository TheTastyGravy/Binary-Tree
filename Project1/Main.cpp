#include "raylib.h"


int main()
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HIGHT = 450;

	InitWindow(SCREEN_WIDTH, SCREEN_HIGHT, "raylib [core] example - basic window");
	SetTargetFPS(60);



	// Main loop
	while (!WindowShouldClose())
	{
		







		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);

		
		EndDrawing();
	}


	CloseWindow();
	return 0;
}