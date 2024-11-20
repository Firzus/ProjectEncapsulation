#include "TextRaylib.h"

void TextRaylib::draw() const
{
	DrawTextEx(customFont, content.c_str(), Vector2{ static_cast<float>(posX), static_cast<float>(posY) }, static_cast<float>(fontSize), 0, Color{ static_cast<unsigned char>(color.R()), static_cast<unsigned char>(color.G()), static_cast<unsigned char>(color.B()), static_cast<unsigned char>(color.A()) });
}
