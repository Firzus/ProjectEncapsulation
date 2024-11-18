#pragma once

#include "Window.h"
#include <stdexcept>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class WindowSDL : public Window {
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
bool open = false;

public:
	~WindowSDL() override;

	void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    bool isOpen() const override;
    void clear(const ColorRGBA& color) override;
	void beginDrawing() override;
	void endDrawing() override;
	void drawSprite(const Sprite& sprite) override;
	void drawShape(const Shape& shape) override;
	void close() override;
};