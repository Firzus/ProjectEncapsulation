#include "ComponentSDL.h"

void ComponentSDL::createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize)
{
    Component::createEntity(label, entities[label] = new TextSDL(customFont, label, x, y, color, content, fontSize, renderer));
}

void ComponentSDL::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{
    Component::createEntity(label, entities[label] = new CircleSDL(label, x, y, color, radius, renderer));
}

void ComponentSDL::createQuadrilateral(std::string label, int x, int y, const ColorRGBA& color, float width, float height, float rotation)
{
	Component::createEntity(label, entities[label] = new QuadrilateralSDL(label, x, y, color, width, height, rotation));
}

void ComponentSDL::createSprite(std::string label, int x, int y, std::string texturePath, float rotation, float scale)
{
    Component::createEntity(label, entities[label] = new SpriteSDL(label, x, y, texturePath, rotation, scale, renderer));
}

void ComponentSDL::loadFont(const std::string& fontPath)
{
    customFont = TTF_OpenFont(fontPath.c_str(), 16);
    if (!customFont) {
        std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        return;
    }
}