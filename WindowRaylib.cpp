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
	Window::createCircle(label, x, y, color, radius);

    circles[label] = new CircleRaylib(label, x, y, color, radius);
}

void WindowRaylib::createSprite(int x, int y, const std::string& filePath)
{

}

void WindowRaylib::close()
{
	CloseWindow();
}

void WindowRaylib::setFrameRate(int frameRate)
{
	SetTargetFPS(frameRate);
}