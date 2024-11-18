#pragma once
#define SDL_MAIN_HANDLED

#include "Window.h"
#include <iostream>
#include <SDL2/SDL.h>


class WindowSDL : public Window {
public:
    void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    bool isOpen() const override;
    void clear() override;
    void draw(const Sprite& sprite) override;
    void display() override;
	void close() override;
};
