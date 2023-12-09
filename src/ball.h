#pragma once
#include "raylib.h"
#include "paddle.h"

class Ball
{
    friend class Paddle;
public: 

    bool isReleased;
    float x;
    float y;
    float radius;
    float speedX;
    float speedY;

    Ball();

    Paddle* p1 { nullptr };

    Paddle* p2 { nullptr };

    void Begin();

    void Update();

    bool CheckForPaddle(Paddle p1, Paddle p2);

    void Draw();
};