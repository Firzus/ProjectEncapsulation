#pragma once

#include "Window.h"

#include "raylib.h"

class WindowRaylib : public Window {
public:
    void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    bool isOpen() const override;
    void clear() override;
    void draw(const Sprite& sprite) override;
    void display() override;
	void close() override;
};

