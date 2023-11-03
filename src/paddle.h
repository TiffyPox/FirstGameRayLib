#pragma once
#include "raylib.h"

class Paddle
{
public:

    float x;
    float y;
    int width;
    int height;

    Paddle();

    void Begin();

    void Update();

    void Draw();
};