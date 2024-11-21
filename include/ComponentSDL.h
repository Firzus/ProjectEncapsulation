#pragma once

#include "Component.h"

class ComponentSDL : public Component
{
public:
	void createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize) override;
	void createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius) override;
	void createSprite(std::string label, int x, int y, std::string texturePath, float rotation, float scale) override;

	// Utils
	void loadFont(const std::string& fontPath) override;
};

