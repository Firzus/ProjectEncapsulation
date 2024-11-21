#pragma once
#define SDL_MAIN_HANDLED

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SpriteSDL : public Sprite
{
private:
	SDL_Renderer* renderer = NULL;
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	SDL_Rect dstrect = { 0,0,0,0 };
	SDL_Point pivot;

	float rotation = 0;

public:
	SpriteSDL(std::string label, int x, int y, std::string texturePath, float rotation, float scale, SDL_Renderer* renderer);
	~SpriteSDL() override;

	void draw() const override;

	bool isColliding(Entity* other) override;
	void bounceOfEntity(Entity* other) override;

	// Getters - Setters
	int getHeight() const override { return dstrect.h; }
	int getWidth() const override { return dstrect.w; }
};

