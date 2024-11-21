#pragma once

#include "Quadrilateral.h"

class QuadrilateralSDL : public Quadrilateral
{
protected:
	float width;
	float height;

public:
	QuadrilateralSDL(const std::string& label, int x, int y, const ColorRGBA& color, float width, float height, float rotation) : Quadrilateral(label, x, y, color, width, height, rotation), width(width), height(height) {}
	~QuadrilateralSDL() = default;

	void draw() const override;

	// Physics
	void bounceOfEntity(Entity* other) override;
	bool isColliding(Entity* other) override;

	// Getters - Setters
	float getWidth() const { return width; }
	float getHeight() const { return height; }
	void setWidth(float newWidth) { width = newWidth; }
	void setHeight(float newHeight) { height = newHeight; }
};