#pragma once
#define SDL_MAIN_HANDLED

#include "Window.h"
#include "CircleSDL.h"
#include "TextSDL.h"
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

class WindowSDL : public Window {
SDL_Window* window = nullptr;
SDL_Event event;
SDL_Renderer* renderer = nullptr;
SDL_Surface* image = NULL;
SDL_Texture* texture = NULL;
SDL_Rect dstrect;
Uint64 start;
Uint64 end;
TTF_Font* customFont;
int currentFrameRate = 0;
int wantedFrameRate = 0;
bool isImageLoaded = false;
bool open = false;

public:
	~WindowSDL() override;

	// Window
	void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    void clear(const ColorRGBA& color) override;
	void beginDrawing() override;
	void endDrawing() override;
    bool isOpen() const override;
	void close() override;
	
	// Utils
	void setFrameRate(int frameRate) override;
	int getFrameRate() const override;
};