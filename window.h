#pragma once

#include "Sprite.h"
#include "Shape.h"

class Window
{
public:
    virtual ~Window() = default;

    virtual void init() = 0;
    virtual void createWindow(int width, int height, const std::string& title) = 0;
    virtual bool isOpen() const = 0;
    virtual void clear() = 0;
    virtual void beginDrawing() = 0;
	virtual void endDrawing() = 0;
    virtual void drawSprite(const Sprite& sprite) = 0;
	virtual void drawShape(const Shape& shape) = 0;
	virtual void close() = 0;
};