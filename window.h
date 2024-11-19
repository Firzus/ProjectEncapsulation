#pragma once

#include <unordered_map>
#include "ColorRGBA.h"
#include "Sprite.h"
#include "Circle.h"

class Window
{
protected:
    std::unordered_map<std::string, Circle*> circles;

public:
    virtual ~Window() = default;

    virtual void init() = 0;
    virtual void createWindow(int width, int height, const std::string& title) = 0;
    virtual bool isOpen() const = 0;
    virtual void clear(const ColorRGBA& color) = 0;
    virtual void beginDrawing() = 0;
	virtual void endDrawing() = 0;
	virtual void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius) = 0;
	virtual void createSprite(int x, int y, const std::string& filePath) = 0;
    virtual void drawSprite(std::string label) = 0;
	virtual void drawCircle(std::string label) = 0;
	virtual void close() = 0;
};