#pragma once

#include "ColorRGBA.h"

#include <string>

class Circle
{
protected:
	std::string label;
	int posX, posY;
	ColorRGBA color;
	float radius;

public:
	Circle(std::string label, int x, int y, const ColorRGBA& color, int radius)
		: label(label), posX(x), posY(y), color(color), radius(radius) {
	}

	virtual ~Circle() = default;

	virtual void draw() const = 0;
	// Renvoie un pointeur générique vers les données
	virtual void* getData() const = 0;
	virtual void setPosition(int x, int y) = 0;
	virtual void setColor(const ColorRGBA& newColor) = 0;

	// Getters
	std::string getLabel() const { return label; }
	int getPosX() const { return posX; }
	int getPosY() const { return posY; }
	ColorRGBA getColor() const { return color; }
	float getRadius() const { return radius; }
};
