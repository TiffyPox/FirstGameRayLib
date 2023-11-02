#pragma once

class Ball
{
public: 

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