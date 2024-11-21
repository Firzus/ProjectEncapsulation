#pragma once
#define SDL_MAIN_HANDLED

#include "Circle.h"
#include <stdexcept>
#include <SDL2/SDL.h>

class CircleSDL : public Circle
{
private:
	SDL_Renderer* renderer;

public:
	CircleSDL(std::string label, int x, int y, const ColorRGBA& color, float radius, SDL_Renderer* renderer)
		: Circle(label, x, y, color, radius) 
	{
		this->renderer = renderer;

	}

	void draw() const override;
};
