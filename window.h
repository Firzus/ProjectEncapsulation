#pragma once

#include <iostream>
#include <unordered_map>
#include "ColorRGBA.h"
#include "Circle.h"
#include "Sprite.h"

class Window
{
protected:
    std::unordered_map<std::string, Circle*> circles;

public:
    virtual ~Window() = default;

	// Window
    virtual void init() = 0;
    virtual void createWindow(int width, int height, const std::string& title) = 0;
    virtual void clear(const ColorRGBA& color) = 0;
    virtual void beginDrawing() = 0;
	virtual void endDrawing() = 0;
	virtual void update();
    virtual bool isOpen() const = 0;
	virtual void close();

	// Entities
	virtual void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius);
	virtual void removeCircle(const std::string& label);
	virtual void createSprite(int x, int y, const std::string& filePath) = 0;

	// Utils
	virtual void setFrameRate(int frameRate) = 0;

	// Getters
	virtual Circle* getCircle(const std::string& label);
};