#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char menuText[] = "Tiff's Game!";
    const float textSize = 50.0f;
    
    InitWindow(screenWidth, screenHeight, "Hello Github");

    InitAudioDevice();

    Music music = LoadMusicStream("../res/menuMusic.mp3");

    Font font = LoadFont("../res/menuFont.otf");

    SetTargetFPS(60);

    PlayMusicStream(music);
    
    int textPos = screenWidth / 2 - (MeasureText(menuText, textSize) / 2);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();

        ClearBackground(PINK);

        DrawText(menuText, textPos, screenHeight / 2 - font.baseSize, textSize, DARKPURPLE);

        EndDrawing();
    }

    CloseWindow();
}