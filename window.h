#pragma once

#include "Sprite.h"
#include "Shape.h"

class Window
{
public:
    struct ColorRGBA {
        unsigned char r, g, b, a;

        // Constructeur pour initialiser la couleur
        ColorRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
            : r(r), g(g), b(b), a(a) {
        }
    };

    virtual ~Window() = default;

    virtual void init() = 0;
    virtual void createWindow(int width, int height, const std::string& title) = 0;
    virtual bool isOpen() const = 0;
    virtual void clear(const ColorRGBA& color) = 0;
    virtual void beginDrawing() = 0;
	virtual void endDrawing() = 0;
    virtual void drawSprite(const Sprite& sprite) = 0;
	virtual void drawShape(const Shape& shape) = 0;
	virtual void close() = 0;
};