#pragma once

#include "Window.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class WindowSDL : public Window {
public:
    void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    bool isOpen() const override;
    void clear() override;
	void beginDrawing() override;
	void endDrawing() override;
	void drawSprite(const Sprite& sprite) override;
	void drawShape(const Shape& shape) override;
	void close() override;
};