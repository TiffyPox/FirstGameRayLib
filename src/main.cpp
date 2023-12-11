#include "raylib.h"
#include "raymath.h"
#include "ball.h"
#include "paddle.h"
#include "inputController.h"

constexpr int screenWidth = 800;
constexpr int screenHeight = 450;
constexpr int paddleWidth = 30;
constexpr int paddleHeight = 160;
constexpr int paddlePadding = 20;
constexpr char title[] = "Tiff's Game!";
constexpr char startText[] = "Press [SPACE] to start!";
constexpr float fontSize = 40.0f;
constexpr float pressSpaceFontSize = 20.0f;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Hello Github");

    InitAudioDevice();

    Font font = LoadFont("../res/menuFont.otf");

    Vector2 titleSize = MeasureTextEx(font, title, fontSize, 0);
    Vector2 startTextSize = MeasureTextEx(font, startText, pressSpaceFontSize, 0);

    const int textPosTitleX = screenWidth / 2.0f - titleSize.x / 2.0f;
    const int textPosTitleY = 50.0f;

    const int textPosXPressSpace = screenWidth / 2.0f - startTextSize.x / 2.0f;
    const int textPosYPressSpace = textPosTitleY + titleSize.y + 10.0f;

    Paddle paddle { paddlePadding, screenHeight / 2.0f - paddleHeight / 2.0f, paddleWidth, paddleHeight, WHITE };
    Paddle paddle2 { screenWidth - paddleWidth - paddlePadding, screenHeight / 2.0f - paddleHeight / 2.0f, paddleWidth, paddleHeight, WHITE };
    InputController player1Controller { &paddle, 3.0f, KeyboardKey::KEY_W, KeyboardKey::KEY_S };
    InputController player2Controller { &paddle2, 3.0f, KeyboardKey::KEY_UP, KeyboardKey::KEY_DOWN };
    Ball ball { };
    Music music = LoadMusicStream("../res/menuMusic.mp3");

    SetTargetFPS(60);

    PlayMusicStream(music);
    
    ball.Begin();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        BeginDrawing();

        ClearBackground(GREEN);

        DrawText(title, textPosTitleX, textPosTitleY, fontSize, DARKGREEN);

        ball.Draw();
        paddle.Draw();
        paddle2.Draw();

        if (!ball.isReleased)
        {
            DrawText(startText, textPosXPressSpace, textPosYPressSpace, pressSpaceFontSize, BLACK);
        }

        ball.Update();

        paddle.Update();
        paddle2.Update();

        ball.CheckForPaddle(paddle, paddle2);

        paddle.ConstrainPaddle( screenHeight, screenWidth );
        paddle2.ConstrainPaddle( screenHeight, screenWidth );

        player1Controller.Move();
        player2Controller.Move();

        EndDrawing();
    }

    CloseWindow();
}