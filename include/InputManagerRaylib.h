#pragma once

#include "InputManager.h"
#include <raylib.h>

class InputManagerRaylib : public InputManager
{
private:

    int mapKeyCodeToRaylibKey(KeyCode key) const 
    {
        switch (key) {
        case KeyCode::UP: return KEY_UP;
        case KeyCode::DOWN: return KEY_DOWN;
        case KeyCode::LEFT: return KEY_LEFT;
        case KeyCode::RIGHT: return KEY_RIGHT;
        default: return -1;
        }
    }

public:
    void update() override {}

    bool isKeyHeld(KeyCode key) const override { return IsKeyDown(mapKeyCodeToRaylibKey(key)); }

    bool isQuitRequested() const override { return WindowShouldClose(); }
};

