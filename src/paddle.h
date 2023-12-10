#pragma once
#include "raylib.h"

class Paddle
{
    friend class InputController;

public:
    Paddle(float x, float y, int paddleWidth, int paddleHeight, Color color);

    void Begin();

    void Update();
    
    void ConstrainPaddle(float screenHeight, float screenWidth);

    Rectangle GetBounds();

    void Draw();

private:
    float x;
    float y;
    int width;
    int height;
    Color color;
};