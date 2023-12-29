#pragma once
#include "raylib.h"
#include "paddle.h"

class Ball
{
    friend class Paddle;
public: 

    bool isReleased;
    bool isCollided;
    float x;
    float y;
    Vector2 center;
    float radius;
    float speedX;
    float speedY;

    Ball();

    Paddle* p1 { nullptr };

    Paddle* p2 { nullptr };

    void Begin();

    void Update();

    bool CheckForPaddle(const Paddle& p1, const Paddle& p2);
    
    void Reset();

    void Draw();
};