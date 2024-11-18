#pragma once

#include "Window.h"
#include <iostream>
//#include <SDL.h>

using namespace std;


class WindowSDL : public Window {
public:
    void init() override;
    void createWindow(int width, int height, const std::string& title) override;
    bool isOpen() const override;
    void clear() override;
    void draw(const Sprite& sprite) override;
    void display() override;
};
