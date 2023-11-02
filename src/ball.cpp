#include "ball.h"
#include "raylib.h"

//int random = GetRandomValue(1, 3);

Ball::Ball()
{
    x = GetScreenWidth() / 2.0f;
    y = GetScreenHeight() / 2.0f;
    radius = 30.0f;
    speedX = 4.0f;
    speedY = 4.0f;
}

bool isReleased;

//Vector2 startPosition {};

void Ball::Begin()
{
   isReleased = true;
   
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

void Ball::Update()
{

}

void Ball::Draw()
{
    DrawCircleGradient((int) x, (int)y, radius, GOLD, MAROON);
}