#pragma once
#include "Sprite.h"

class Window
{
public:
    virtual ~Window() = default;

    virtual void init() = 0;
    virtual void createWindow(int width, int height, const std::string& title) = 0;
    virtual bool isOpen() const = 0;
    virtual void clear() = 0;
    virtual void draw(const Sprite& sprite) = 0;
    virtual void display() = 0;
};