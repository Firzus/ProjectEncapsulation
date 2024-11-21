#pragma once

#include "Component.h"
#include "TextSDL.h"
#include "CircleSDL.h"
#include "SpriteSDL.h"

class ComponentSDL : public Component
{
private:
	TTF_Font* customFont;
	SDL_Renderer* renderer;

public:
	void createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize) override;
	void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius) override;
	void createSprite(std::string label, int x, int y, std::string texturePath, float rotation, float scale) override;

	// Utils
	void loadFont(const std::string& fontPath) override;

	// Setter
	void setRenderer(SDL_Renderer* renderer) { this->renderer = renderer; }
};

