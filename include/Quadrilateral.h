#pragma once

#include "Entity.h"

class Quadrilateral : public Entity {
protected:
	ColorRGBA color;
	float width;
	float height;
	float rotation;

public:
	Quadrilateral(const std::string& label, int x, int y, const ColorRGBA& color, float width, float height, float rotation) : Entity(), color(color), width(width), height(height), rotation(rotation) {}
	virtual ~Quadrilateral() = default;

	// Physics
	virtual void bounceOfEntity(Entity* other) override;
	virtual bool isColliding(Entity* other) override;

	// Getters - Setters
	ColorRGBA getColor() const { return color; }
	float getWidth() const { return width; }
	float getHeight() const { return height; }
	float getRotation() const { return rotation; }
	void setColor(const ColorRGBA& newColor) { color = newColor; }
	void setWidth(float newWidth) { width = newWidth; }
	void setHeight(float newHeight) { height = newHeight; }
	void setRotation(float newRotation) { rotation = newRotation; }
};

