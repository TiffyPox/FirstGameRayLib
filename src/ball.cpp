#include "ball.h"
#include "raylib.h"

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
                        x = GetScreenWidth() / 2.f;
            y = GetScreenHeight() / 2.f;

            // Reset the ball to center
            x = GetScreenWidth() / 2.f;
            y = GetScreenHeight() / 2.f;
            speedX = 4.0f;
            speedY = 4.0f;
        }

        if ((y >= (GetScreenHeight() - radius)) || (y <= radius)) 
        {
            speedY *= -1.0f;
        }
    }
}

bool Ball::CheckForPaddle(const Paddle& p1, const Paddle& p2)
{
    if (!isReleased)
    {
        return false;
    }

    Vector2 center = {x, y};

    // check for collision with paddle 1
    if (CheckCollisionCircleRec(center, radius, p1.GetBounds()))
    {
        if(x - radius >= p1.GetBounds().x + p1.GetBounds().width / 2.f)
        {
            isCollided = true;
            speedX *= -1.1f;
            x = p1.GetBounds().x + p1.GetBounds().width + radius; // Correction
        }
    }

    // check for collision with paddle 2
    if (CheckCollisionCircleRec(center, radius, p2.GetBounds()))
    {
        if(x + radius <= p2.GetBounds().x + p2.GetBounds().width / 2.f)
        {
            isCollided = true;
            speedX *= -1.1f;
            x = p2.GetBounds().x - radius; // Correction
        }
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