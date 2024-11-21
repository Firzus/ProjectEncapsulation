#pragma once
#define SDL_MAIN_HANDLED
#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Text.h"

class TextSDL : public Text
{
private:
	TTF_Font* customFont;
	SDL_Renderer* renderer;
	SDL_Color sdlColor;

public:
	TextSDL(TTF_Font* customFont, const std::string& label, int x, int y, const ColorRGBA& color, std::string content, int fontSize, SDL_Renderer* renderer) : Text(label, x, y, color, content, fontSize)
	{
		this->customFont = customFont;
		this->renderer = renderer;

		sdlColor.r = static_cast<Uint8>(color.R());
		sdlColor.g = static_cast<Uint8>(color.G());
		sdlColor.b = static_cast<Uint8>(color.B());
		sdlColor.a = static_cast<Uint8>(color.A());
	}

	void draw() const override;
};

