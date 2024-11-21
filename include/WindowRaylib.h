#pragma once

#include <iostream>
#include "raylib.h"
#include "Window.h"

class WindowRaylib : public Window {
public:
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