#pragma once

#include "Entity.h"
#include "ColorRGBA.h"

class Circle : public Entity {
protected:
	ColorRGBA color;
	float radius;

public:
	Circle(const std::string& label, int x, int y, const ColorRGBA& color, float radius) : Entity(), color(color), radius(radius)
	{
		this->label = label;
		this->posX = x;
		this->posY = y;
	}

	virtual ~Circle() = default;

	// Physics
	virtual void bounceOfEntity(Entity* other) override;
	virtual bool isColliding(Entity* other) override;

	// Getters - Setters
	ColorRGBA getColor() const { return color; }
	float getRadius() const { return radius; }

	void setColor(const ColorRGBA& newColor) { color = newColor; }
	void setRadius(float newRadius) { radius = newRadius; }
};
