#include "CircleRaylib.h"

void CircleRaylib::draw() const
{
	DrawCircle(posX, posY, radius, Color{ static_cast<unsigned char>(color.R()), static_cast<unsigned char>(color.G()), static_cast<unsigned char>(color.B()), static_cast<unsigned char>(color.A()) });
}

void* CircleRaylib::getData() const
{
	return nullptr;
}

void CircleRaylib::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

void CircleRaylib::moove(int x, int y)
{
	posX += x;
	posY += y;
}

void CircleRaylib::setColor(const ColorRGBA& newColor)
{
	color = newColor;
}
