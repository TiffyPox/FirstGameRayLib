#pragma once
#include "raylib.h"

class Paddle
{
    friend class InputController;

public:
    Paddle(float x, float y, int paddleWidth, int paddleHeight, Color color);

    int _points;

    void Begin();

    void Update();
    
    void ConstrainPaddle(float screenHeight, float screenWidth);

    Rectangle GetBounds() const;

    void AwardPoint(int point);

    void Draw();

private:
    float x;
    float y;
    int width;
    int height;
    Color color;
};