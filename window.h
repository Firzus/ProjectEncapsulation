#pragma once

#include <iostream>
#include <unordered_map>
#include "ColorRGBA.h"
#include "Entity.h"

class Window
{
protected:
	int windowWidth = 0, windowHeight = 0;

public:
    virtual ~Window() = default;

	// Window
    virtual void init() = 0;
    virtual void createWindow(int width, int height, const std::string& title);
    virtual void clear(const ColorRGBA& color) = 0;
    virtual void beginDrawing() = 0;
	virtual void endDrawing() = 0;
	virtual void draw(std::unordered_map<std::string, Entity*> entities);
    virtual bool isOpen() const = 0;
	virtual void close();

	// Utils
	virtual void setFrameRate(int frameRate) = 0;
	virtual int getFrameRate() const = 0;
};