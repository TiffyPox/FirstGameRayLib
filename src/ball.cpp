#include "ball.h"
#include "raylib.h"
#include <iostream>

Ball::Ball()
{
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    isCollided = false;
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

    Vector2 center = {x, y};

    // check for collision with paddle 1
    if (CheckCollisionCircleRec(center, radius, p1.GetBounds()))
    {
        isCollided = true;

        speedX *= -1.1f;
    }

    // check for collision with paddle 2
    if (CheckCollisionCircleRec(center, radius, p2.GetBounds()))
    {
        isCollided = true;

        speedX *= -1.1f;
    }
}

void Ball::Draw()
{
    if (isCollided)
    {
        DrawText("COLLIDED!", GetScreenWidth() / 2, GetScreenHeight() / 2, 50, BLACK);
    }

    DrawCircleGradient(x, y, radius, GOLD, MAROON);
}