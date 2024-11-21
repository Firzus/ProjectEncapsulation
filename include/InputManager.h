#pragma once

enum class KeyCode
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class InputManager
{
public:

    InputManager() {}
    virtual ~InputManager() {}

    virtual void update() = 0;

    virtual bool isKeyHeld(KeyCode key) const = 0;

    virtual bool isQuitRequested() const = 0;
};

