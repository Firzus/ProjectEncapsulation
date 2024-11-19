#include "TextRaylib.h"

void TextRaylib::draw() const
{
	DrawText(content.c_str(), posX, posY, fontSize, Color{ static_cast<unsigned char>(color.R()), static_cast<unsigned char>(color.G()), static_cast<unsigned char>(color.B()), static_cast<unsigned char>(color.A()) });
}
