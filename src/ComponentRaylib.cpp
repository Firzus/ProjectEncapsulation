#include "ComponentRaylib.h"

void ComponentRaylib::createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize)
{
	Component::createEntity(label, entities[label] = new TextRaylib(customFont, label, x, y, color, content, fontSize));
}

void ComponentRaylib::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{
	Component::createEntity(label, entities[label] = new CircleRaylib(label, x, y, color, radius));
}

void ComponentRaylib::createQuadrilateral(std::string label, int x, int y, const ColorRGBA& color, float width, float height, float rotation)
{
	Component::createEntity(label, entities[label] = new QuadrilateralRaylib(label, x, y, color, width, height, rotation));
}

void ComponentRaylib::createSprite(std::string label, int x, int y, std::string texturePath, float rotation, float scale)
{
	Component::createEntity(label, entities[label] = new SpriteRaylib(label, x, y, texturePath, rotation, scale));
}

void ComponentRaylib::loadFont(const std::string& fontPath)
{
	customFont = LoadFont(fontPath.c_str());
}
