#pragma once

class FPSCounter {
private:
    int frames;
    float elapsed;
    float fps;

public:
    FPSCounter() : frames(0), elapsed(0), fps(0) {}
    void update(float dt);
    float getFPS() const { return fps; }
};