#pragma once
#define SDL_MAIN_HANDLED

#include "Circle.h"
#include <stdexcept>
#include <SDL2/SDL.h>

class CircleSDL : public Circle
{
public:
	CircleSDL(std::string label, int x, int y, const ColorRGBA& color, float radius)
		: Circle(label, x, y, color, radius) {
	}

	void draw(void* renderer) const override;
	void* getData() const override;
	void setPosition(int x, int y) override;
	void setColor(const ColorRGBA& newColor) override;
};
