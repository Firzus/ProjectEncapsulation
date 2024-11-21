#include "SpriteRaylib.h"

SpriteRaylib::SpriteRaylib(std::string label, int x, int y, std::string texturePath, float rotation, float scale) : Sprite(label, x, y, texturePath, rotation, scale)
{
	texture = LoadTexture(texturePath.c_str());
}

SpriteRaylib::~SpriteRaylib()
{
	UnloadTexture(texture);
}

void SpriteRaylib::draw() const
{
	DrawTextureEx(texture, { (float)posX, (float)posY }, rotation, scale, WHITE);
}

bool SpriteRaylib::isColliding(Entity* other)
{
	return false;
}

void SpriteRaylib::bounceOfEntity(Entity* other)
{
}
