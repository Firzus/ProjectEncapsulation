#include "ComponentRaylib.h"

void ComponentRaylib::createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize)
{
	Component::createEntity(label, entities[label] = new TextRaylib(customFont, label, x, y, color, content, fontSize));
}

void ComponentRaylib::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{
	Component::createEntity(label, entities[label] = new CircleRaylib(label, x, y, color, radius, NULL));
}

void ComponentRaylib::loadFont(const std::string& fontPath)
{
	customFont = LoadFont(fontPath.c_str());
}
