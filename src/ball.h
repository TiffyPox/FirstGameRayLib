#pragma once
#include "raylib.h"

class Ball
{
public: 

    bool isReleased;
    float x;
    float y;
    float radius;
    float speedX;
    float speedY;

    Ball();

    void Begin();

    void Update();

    void Draw();
};