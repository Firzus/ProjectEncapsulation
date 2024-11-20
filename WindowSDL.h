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

	// Window
	void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    void clear(const ColorRGBA& color) override;
	void beginDrawing() override;
	void endDrawing() override;
    bool isOpen() const override;
	void close() override;

	// Entities
	void createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize) override;
	void removeText(const std::string& label) override;

	void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius) override;
	void removeCircle(const std::string& label) override;

	void createSprite(int x, int y, const std::string& filePath) override;
	
	// Utils
	void loadFont(const std::string& fontPath) override;
	void setFrameRate(int frameRate) override;
};