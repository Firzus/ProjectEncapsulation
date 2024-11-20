#pragma once

#include <iostream>
#include <unordered_map>
#include "ColorRGBA.h"
#include "Circle.h"
#include "Sprite.h"
#include "Text.h"

class Window
{
protected:
	int windowWidth = 0, windowHeight = 0;

	std::unordered_map<std::string, Text*> texts;
    std::unordered_map<std::string, Circle*> circles;

public:
    virtual ~Window() = default;

	// Window
    virtual void init() = 0;
    virtual void createWindow(int width, int height, const std::string& title);
    virtual void clear(const ColorRGBA& color) = 0;
    virtual void beginDrawing() = 0;
	virtual void endDrawing() = 0;
	virtual void draw();
    virtual bool isOpen() const = 0;
	virtual void close();

	// Entities
	virtual void createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize);
	virtual void removeText(const std::string& label);

	virtual void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius);
	virtual void removeCircle(const std::string& label);

	virtual void createSprite(int x, int y, const std::string& filePath) = 0;

	// Utils
	virtual void loadFont(const std::string& fontPath) = 0;
	virtual void setFrameRate(int frameRate) = 0;
	virtual int getFrameRate() const = 0;

	// Getters
	Circle* getCircle(const std::string& label);
	Text* getText(const std::string& label);
};