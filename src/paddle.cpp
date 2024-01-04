#include "paddle.h"
#include "raylib.h"

Paddle::Paddle(float x, float y, int paddleWidth, int paddleHeight, Color color)
{
    this->x = x;
    this->y = y;
    this->width = paddleWidth;
    this->height = paddleHeight;
    this->color = color;
}

void Paddle::Begin()
{

}

void Paddle::Update()
{

}

void Paddle::ConstrainPaddle(float screenHeight, float screenWidth)
{
    if (y < 0)
    {
        y = 0;
    } 
    else if (y > screenHeight - height)
    {
        y = screenHeight - height;
    }
}

Rectangle Paddle::GetBounds() const
{
    return Rectangle {x, y, (float) width, (float) height};
}

void Paddle::AwardPoint(int point)
{
    _points += point;
}

void Paddle::Draw()
{
    DrawRectangle(x, y, width, height, color);
}