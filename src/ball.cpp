#include "ball.h"
#include "raylib.h"

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