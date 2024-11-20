#pragma once
#define SDL_MAIN_HANDLED

#include "Circle.h"
#include <stdexcept>
#include <SDL2/SDL.h>

class CircleSDL : public Circle
{

public:
	CircleSDL(std::string label, int x, int y, const ColorRGBA& color, float radius, void* renderer)
		: Circle(label, x, y, color, radius, renderer) {
	}

	void draw() const override;
};