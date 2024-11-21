#pragma once

#include "Sprite.h"
#include "raylib.h"

class SpriteRaylib : public Sprite {
private:
	Texture2D texture;

public:
	SpriteRaylib(std::string label, int x, int y, std::string texturePath, float rotation, float scale);
	~SpriteRaylib() override;

	void draw() const override;

	bool isColliding(Entity* other) override;
	void bounceOfEntity(Entity* other) override;

	// Getters - Setters
	int getHeight() const override { return texture.width; }
	int getWidth() const override { return texture.height; }
};
