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
};

