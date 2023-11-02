#include "raylib.h"
#include "raymath.h"
#include "ball.h"

Rectangle GetRect(Rectangle paddle)
{
    return Rectangle{ paddle.x - paddle.width / 2, paddle.y - paddle.height / 2, paddle.width, paddle.height };
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char menuText[] = "Tiff's Game!";
    const float fontSize = 40.0f;
    
    InitWindow(screenWidth, screenHeight, "Hello Github");

    InitAudioDevice();

    Music music = LoadMusicStream("../res/menuMusic.mp3");

    Font font = LoadFont("../res/menuFont.otf");

    Vector2 textSize = MeasureTextEx(font, menuText, fontSize, 0);

    Ball ball;

    // To Do: Create Paddle Class
    Rectangle paddle;
    paddle.x = 20;
    paddle.y = screenHeight / 2 - 80;
    paddle.width = 30;
    paddle.height = 160;

    SetTargetFPS(60);

    PlayMusicStream(music);
    
    int textPos = screenWidth / 2.0f - textSize.x / 2.0f;

    ball.Begin();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();

        ClearBackground(GREEN);

        if (IsKeyDown(KEY_UP)) paddle.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) paddle.y += 2.0f;

        ball.Draw();

        ball.Update();

        DrawRectangle(paddle.x, paddle.y, 30, 160, WHITE);

        DrawRectangle(750, screenHeight / 2 - 80, 30, 160, WHITE);

        DrawText(menuText, textPos, screenHeight / 2 - 200, fontSize, DARKGREEN);

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