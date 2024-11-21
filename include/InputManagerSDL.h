#pragma once
#define SDL_MAIN_HANDLED

#include "InputManager.h"
#include <SDL2/SDL.h>

class InputManagerSDL : public InputManager
{
private:
    SDL_Event event;
    const Uint8* keyStates;
    bool quitRequested = false;

    SDL_Scancode mapKeyCodeToSDLScancode(KeyCode key) const 
    {
        switch (key) {
        case KeyCode::UP: return SDL_SCANCODE_UP;
        case KeyCode::DOWN: return SDL_SCANCODE_DOWN;
        case KeyCode::LEFT: return SDL_SCANCODE_LEFT;
        case KeyCode::RIGHT: return SDL_SCANCODE_RIGHT;
        default: return SDL_SCANCODE_UNKNOWN;
        }
    }

public:
    InputManagerSDL() { keyStates = SDL_GetKeyboardState(nullptr); }

    void update() override;

    bool isKeyHeld(KeyCode key) const override { return keyStates[mapKeyCodeToSDLScancode(key)]; }

    bool isQuitRequested() const override { return quitRequested; }
};

