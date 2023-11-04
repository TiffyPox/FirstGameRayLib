#include "paddle.h"
#include "raylib.h"

Paddle::Paddle()
{
    x = 0;
    y = 0;
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