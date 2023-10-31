#include "raylib.h"
#include "raymath.h"
#include "ball.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char menuText[] = "Tiff's Game!";
    const float fontSize = 50.0f;
    
    InitWindow(screenWidth, screenHeight, "Hello Github");

    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 }; 

    InitAudioDevice();

    Music music = LoadMusicStream("../res/menuMusic.mp3");

    Font font = LoadFont("../res/menuFont.otf");

    Vector2 textSize = MeasureTextEx(font, menuText, fontSize, 0);

    Ball ball{};

    SetTargetFPS(60);

    PlayMusicStream(music);
    
    int textPos = screenWidth / 2.0f - textSize.x / 2.0f;

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();

        ClearBackground(GREEN);

        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

        DrawCircleGradient(ballPosition.x, ballPosition.y, 30, GOLD, MAROON);

        DrawRectangle(20, screenHeight / 2 - 80, 30, 160, WHITE);

        DrawText(menuText, textPos, screenHeight / 2 - textSize.y * 0.5f, fontSize, DARKGREEN);

        EndDrawing();
    }

    CloseWindow();
}