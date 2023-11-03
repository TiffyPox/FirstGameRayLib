#include "ball.h"
#include "raylib.h"

//int random = GetRandomValue(1,2);
Vector2 startPosition{};
bool isReleased;

Ball::Ball()
{
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    radius = 30.0f;
    speedX = 4.0f;
    speedY = 4.0f;
}

void Ball::Begin()
{
   isReleased = false;

   startPosition = {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
}

void Ball::Update()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        isReleased = true;
    }

    if (isReleased)
    {
        x += speedX;
        y += speedY;

        if ((x >= (GetScreenWidth() - radius)) || (x <= radius)) 
        {
            speedX *= -1.0f;
        }

        if ((y >= (GetScreenHeight() - radius)) || (y <= radius)) 
        {
            speedY *= -1.0f;
        }
    }

    // To do: check for collision with paddle
}

void Ball::Draw()
{
    DrawCircleGradient(x, y, radius, GOLD, MAROON);
}