#include "WindowRaylib.h"

void WindowRaylib::init() {}

void WindowRaylib::createWindow(int width, int height, const std::string& title)
{
    InitWindow(width, height, title.c_str());
}

bool WindowRaylib::isOpen() const
{
	return !WindowShouldClose();
}

void WindowRaylib::clear(const ColorRGBA& color)
{
    ClearBackground(Color{ static_cast<unsigned char>(color.R()), static_cast<unsigned char>(color.G()), static_cast<unsigned char>(color.B()), static_cast<unsigned char>(color.A()) });

    BeginDrawing();
}

void WindowRaylib::beginDrawing()
{
	BeginDrawing();
}

void WindowRaylib::endDrawing()
{
	EndDrawing();
}

void WindowRaylib::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{
    if (circles.find(label) != circles.end()) {
        std::cerr << "Un cercle avec l'identifiant '" << label << "' existe déjà.\n";
        return;
    }

    circles[label] = new CircleRaylib(label, x, y, color, radius);
}

void WindowRaylib::createSprite(int x, int y, const std::string& filePath)
{
}

void WindowRaylib::drawSprite(std::string label)
{
}

void WindowRaylib::drawCircle(std::string label)
{
    std::unordered_map<std::string, Circle*>::iterator it = circles.find(label);
    if (it != circles.end()) {
        it->second->draw(NULL);
    }
    else {
        std::cerr << "Cercle avec l'identifiant '" << label << "' introuvable.\n";
    }
}

void WindowRaylib::close()
{
	CloseWindow();
}
