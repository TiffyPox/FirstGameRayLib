#pragma once
#include "raylib.h"

class Ball
{
public: 

    bool isReleased;
    Vector2 startPosition{};
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