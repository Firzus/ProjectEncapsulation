#include "CircleRaylib.h"

void CircleRaylib::draw() const
{
	DrawCircle(posX, posY, radius, Color{ static_cast<unsigned char>(color.R()), static_cast<unsigned char>(color.G()), static_cast<unsigned char>(color.B()), static_cast<unsigned char>(color.A()) });
}