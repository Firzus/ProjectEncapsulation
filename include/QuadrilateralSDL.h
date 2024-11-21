#pragma once
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include "Quadrilateral.h"

class QuadrilateralSDL : public Quadrilateral
{
protected:
	SDL_Renderer* renderer = NULL;

public:
	QuadrilateralSDL(const std::string& label, int x, int y, const ColorRGBA& color, float width, float height, float rotation, SDL_Renderer* renderer) : 
		Quadrilateral(label, x, y, color, width, height, rotation), renderer(renderer) {}
	~QuadrilateralSDL() = default;

	void draw() const override;
};