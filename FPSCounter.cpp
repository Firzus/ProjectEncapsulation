#include "FpsCounter.h"

void FPSCounter::update(float dt)
{
    frames++;
    elapsed += dt;
    if (elapsed >= 1.0f) {
        fps = frames / elapsed;
        frames = 0;
        elapsed = 0;
    }
}
