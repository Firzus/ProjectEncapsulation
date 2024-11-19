#pragma once

#include "raylib.h"
#include "Circle.h"

class CircleRaylib : public Circle
{
public:
	CircleRaylib(std::string label, int x, int y, const ColorRGBA& color, float radius, void* renderer)
		: Circle(label, x, y, color, radius, renderer) {
	}

	void draw() const override;
	void* getData() const override;
	void setPosition(int x, int y) override;
	void moove(int x, int y) override;
	void setColor(const ColorRGBA& newColor) override;
};

