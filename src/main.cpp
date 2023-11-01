#include "raylib.h"
#include "raymath.h"
#include "ball.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char menuText[] = "Tiff's Game!";
    const float fontSize = 40.0f;
    const float ballRadius = 30.0f;
    
    InitWindow(screenWidth, screenHeight, "Hello Github");

    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 }; 

    Vector2 paddlePosition = { 20, screenHeight / 2 - 80 };

    InitAudioDevice();

    Music music = LoadMusicStream("../res/menuMusic.mp3");

    Font font = LoadFont("../res/menuFont.otf");

    Vector2 textSize = MeasureTextEx(font, menuText, fontSize, 0);

    Vector2 ballSpeed = {4.0f, 4.0f};

    SetTargetFPS(60);

    PlayMusicStream(music);
    
    int textPos = screenWidth / 2.0f - textSize.x / 2.0f;

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();

        ClearBackground(GREEN);

        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;
        
        if ((ballPosition.x >= (screenWidth - ballRadius)) || (ballPosition.x <= ballRadius)) 
        {
            ballSpeed.x *= -1.0f;
        }

        if ((ballPosition.y >= (screenHeight - ballRadius)) || (ballPosition.y <= ballRadius)) 
        {
            ballSpeed.y *= -1.0f;
        }

        if (IsKeyDown(KEY_UP)) paddlePosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) paddlePosition.y += 2.0f;

        DrawCircleGradient(ballPosition.x, ballPosition.y, ballRadius, GOLD, MAROON);

        DrawRectangle(paddlePosition.x, paddlePosition.y, 30, 160, WHITE);

        DrawRectangle(750, screenHeight / 2 - 80, 30, 160, WHITE);

        DrawText(menuText, textPos, screenHeight / 2 - 200, fontSize, DARKGREEN);

        EndDrawing();
    }

    CloseWindow();
}