#pragma once

#include "raylib.h"
#include "Quadrilateral.h"

class QuadrilateralRaylib : public Quadrilateral
{
public:
	QuadrilateralRaylib(const std::string& label, int x, int y, const ColorRGBA& color, float width, float height, float rotation) : Quadrilateral(label, x, y, color, width, height, rotation) {}

	void draw() const override;
};

