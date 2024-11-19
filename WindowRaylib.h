#pragma once

#include <iostream>
#include "raylib.h"
#include "Window.h"
#include "CircleRaylib.h"

class WindowRaylib : public Window {
public:
    void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    bool isOpen() const override;
    void clear(const ColorRGBA& color) override;
    void beginDrawing() override;
    void endDrawing() override;
    void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius) override;
	void createSprite(int x, int y, const std::string& filePath) override;
    void drawSprite(std::string label) override;
    void drawCircle(std::string label) override;
	void close() override;
};