#pragma once

#include "Component.h"
#include "TextRaylib.h"
#include "CircleRaylib.h"
#include "SpriteRaylib.h"

class ComponentRaylib : public Component
{
private:
	Font customFont;

public:
	ComponentRaylib() : customFont{} {}

	void createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize) override;
	void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius) override;
	void createSprite(std::string label, int x, int y, std::string texturePath, float rotation, float scale) override;

	// Utils
	void loadFont(const std::string& fontPath) override;
};

