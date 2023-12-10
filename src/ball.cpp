#include "ball.h"
#include "raylib.h"
#include <iostream>

Ball::Ball()
{
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    Vector2 center = {x, y};
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
}

bool Ball::CheckForPaddle(Paddle p1, Paddle p2)
{
    if (!isReleased)
    {
        return false;
    }

    bool isCollided = CheckCollisionCircleRec(center, radius, p1.GetBounds());

    if (isCollided == true)
    {
        speedX = 0.0f;
        speedY = 0.0f;
    }
}

void Ball::Draw()
{
    DrawCircleGradient(x, y, radius, GOLD, MAROON);
}