#include "raylib.h"
#include "raymath.h"
#include "ball.h"
#include "paddle.h"

Rectangle GetRect(Paddle paddle)
{
    return Rectangle{ paddle.x - paddle.width / 2, paddle.y - paddle.height / 2, (float)paddle.width, (float)paddle.height };
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char title[] = "Tiff's Game!";
    const char startText[] = "Press [SPACE] to start!";
    const float fontSize = 40.0f;
    
    InitWindow(screenWidth, screenHeight, "Hello Github");

    InitAudioDevice();

    Music music = LoadMusicStream("../res/menuMusic.mp3");

    Font font = LoadFont("../res/menuFont.otf");

    Vector2 textSize = MeasureTextEx(font, title, fontSize, 0);

    Ball ball;

    Paddle paddle;

    SetTargetFPS(60);

    PlayMusicStream(music);
    
    int textPos = screenWidth / 2.0f - textSize.x / 2.0f;

    ball.Begin();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();

        ClearBackground(GREEN);

        ball.Draw();
        paddle.Draw();

        if (!ball.isReleased)
        {
            DrawText(startText, textPos, screenHeight / 2 - -150, 20.0f, BLACK);
        }

        if (IsKeyDown(KEY_UP)) paddle.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) paddle.y += 2.0f;

        ball.Update();

        DrawRectangle(750, screenHeight / 2 - 80, 30, 160, WHITE);

        DrawText(title, textPos, screenHeight / 2 - 200, fontSize, DARKGREEN);

         if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, GetRect(paddle)))
        {
            if (ball.speedX > 0)
            {
                ball.speedX *= -1.1f;
            }
        }

        EndDrawing();
    }

    CloseWindow();
}