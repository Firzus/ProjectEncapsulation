#include "InputManagerSDL.h"

void InputManagerSDL::update()
{
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quitRequested = true;
        }
    }
}
