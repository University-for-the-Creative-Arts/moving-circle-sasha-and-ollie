#include "raylib.h"



int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int score = 0;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    Vector2 coinPosition = { (float)screenWidth/2+100, (float)screenHeight/2+100 };
    Color coinColor = {255,200,0,255,};

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        
        if (IsKeyDown(KEY_RIGHT) and IsKeyDown(KEY_R)) ballPosition.x += 4.0f;
        if (IsKeyDown(KEY_LEFT)and IsKeyDown(KEY_R)) ballPosition.x -= 4.0f;
        if (IsKeyDown(KEY_UP)and IsKeyDown(KEY_R)) ballPosition.y -= 4.0f;
        if (IsKeyDown(KEY_DOWN)and IsKeyDown(KEY_R)) ballPosition.y += 4.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("Move the ball with arrow keys. Hold 'R' to run", 10, 10, 20, DARKGRAY);
            DrawText(TextFormat("Score: %d", score), 10, 30, 20, DARKGRAY);
            DrawText("COINS AND SCORE DON'T WORK. WE TRIED :)", 10, 50, 20, coinColor);
            

            DrawCircleV(ballPosition, 50, MAROON);
            DrawCircleV(coinPosition, 25, coinColor);

        EndDrawing();
        
        
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}