#include "inputController.h"
#include "raylib.h"

void InputController::Move()
{
    if (IsKeyDown(keyUp))
    {
        paddle->y -= speed;
    }

    if (IsKeyDown(keyDown))
    {
        paddle->y += speed;
    }
}