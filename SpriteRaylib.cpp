#include "SpriteRaylib.h"

void SpriteRaylib::loadImage(const std::string& filePath)
{
	Image image = LoadImage(filePath.c_str());  // Charge l'image depuis le fichier
	texture = LoadTextureFromImage(image);     // Convertit l'image en texture
	UnloadImage(image);
}

void* SpriteRaylib::getData() const
{
	return nullptr;
}

void SpriteRaylib::setPosition(float x, float y)
{
	/*x = xPos;
	y = yPos;*/
}
