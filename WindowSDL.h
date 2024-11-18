#pragma once
#define SDL_MAIN_HANDLED

#include "Window.h"
#include <stdexcept>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class WindowSDL : public Window {
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Event event;
SDL_Surface* image = NULL;
SDL_Texture* texture = NULL;
SDL_Rect dstrect;
bool isImageLoaded = false;
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

	void SDL_RenderDrawCircle(SDL_Renderer* renderer, int x, int y, int radius);
	void SDL_RenderFillCircle(SDL_Renderer* renderer, int x, int y, int radius);
};
