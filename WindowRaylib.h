#pragma once

#include "Window.h"
#include "raylib.h"

class WindowRaylib : public Window {
public:
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