#include "raylib.h"
#include "raymath.h"
#include "ball.h"
#include "paddle.h"

Rectangle GetRect(Paddle paddle)
{
    return Rectangle
    { 
        paddle.x - paddle.width / 2, paddle.y - paddle.height / 2, (float)paddle.width, (float)paddle.height 
    };
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

    Font font = LoadFont("../res/menuFont.otf");

    Vector2 textSize = MeasureTextEx(font, title, fontSize, 0);

    int textPos = screenWidth / 2.0f - textSize.x / 2.0f;

    Paddle paddle;
    Paddle paddle2;
    
    // To do: create separate game screen to initialize paddles
    paddle.x = 20.0f;
    paddle.y = screenHeight / 2.0f - 80.0f;
    paddle2.x = 750.0f;
    paddle2.y = screenHeight / 2 - 80.0f;
    const float bounds = paddle.width / 2.0f;
    const float bounds2 = paddle2.width / 2.0f;

    Music music = LoadMusicStream("../res/menuMusic.mp3");

    SetTargetFPS(60);

    PlayMusicStream(music);
    
    Ball ball;

    ball.Begin();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();

        ClearBackground(GREEN);

        DrawText(title, textPos, screenHeight / 2 - 200, fontSize, DARKGREEN);

        ball.Draw();
        paddle.Draw();
        paddle2.Draw();

        // To do: Move ball and paddle logic to separate game screen
        if (!ball.isReleased)
        {
            DrawText(startText, textPos, screenHeight / 2 - -150, 20.0f, BLACK);
        }

        // paddle 1
        if (IsKeyDown(KEY_W)) paddle.y -= 2.0f;
        if (IsKeyDown(KEY_S)) paddle.y += 2.0f;

        if ((paddle.y - bounds) < 0)
        {
            paddle.y = bounds;
        }

        // need to fix
        if (paddle.y > screenHeight - paddle.height)
        {
            paddle.y = screenHeight - paddle.height;
        }

        // paddle 2
        if (IsKeyDown(KEY_UP)) paddle2.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) paddle2.y += 2.0f;

        ball.Update();

        // To do: fix collision detection
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