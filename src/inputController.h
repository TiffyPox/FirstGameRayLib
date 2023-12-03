#pragma once
#include "raylib.h"
#include "paddle.h"

class InputController
{
public:
    InputController(Paddle* paddle, float speed, KeyboardKey keyUp, KeyboardKey keyDown)
    : paddle { paddle }, speed { speed }, keyUp { keyUp }, keyDown { keyDown } { }

    void Move();

public:
    float speed { 0 };
    KeyboardKey keyUp { KeyboardKey::KEY_W };
    KeyboardKey keyDown { KeyboardKey::KEY_S };
    Paddle* paddle { nullptr };
};