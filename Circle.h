#pragma once

#include <string>
#include "ColorRGBA.h"
#include "Entity.h"

class Circle : public Entity {
protected:
	ColorRGBA color;
	float radius;
	void* renderer;

public:
	Circle(const std::string& label, int x, int y, const ColorRGBA& color, float radius, void* renderer) : Entity(), color(color), radius(radius)
	{
		this->label = label;
		this->posX = x;
		this->posY = y;
		this->renderer = renderer;
	}

	virtual ~Circle() = default;

	void setColor(const ColorRGBA& newColor);

	// Physics
	virtual void bounceOfEntity(Entity* other) override;
	virtual bool isColliding(Entity* other) override;

	// Getters
	ColorRGBA getColor() const { return color; }
	float getRadius() const { return radius; }
};
