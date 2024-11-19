#pragma once

#include <string>
#include "ColorRGBA.h"
#include "Entity.h"

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

	// Getters
	ColorRGBA getColor() const { return color; }
	float getRadius() const { return radius; }
};
