#include "paddle.h"
#include "raylib.h"

Paddle::Paddle()
{
    x = 20.0f;
    y = GetScreenHeight() / 2.0f - 80.0f;
    width = 30;
    height = 160;
}

void Paddle::Begin()
{

}

void Paddle::Update()
{

}

void Paddle::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}