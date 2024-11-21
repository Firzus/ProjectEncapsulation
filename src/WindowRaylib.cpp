#include "WindowRaylib.h"

void WindowRaylib::init() {}

void WindowRaylib::createWindow(int width, int height, const std::string& title)
{
	Window::createWindow(width, height, title);

    InitWindow(width, height, title.c_str());
}

void WindowRaylib::clear(const ColorRGBA& color)
{
    ClearBackground(Color{ static_cast<unsigned char>(color.R()), static_cast<unsigned char>(color.G()), static_cast<unsigned char>(color.B()), static_cast<unsigned char>(color.A()) });
}

void WindowRaylib::beginDrawing()
{
	BeginDrawing();
}

void WindowRaylib::endDrawing()
{
	EndDrawing();
}

bool WindowRaylib::isOpen() const
{
	return !WindowShouldClose();
}

void WindowRaylib::close()
{
	CloseWindow();
}

void WindowRaylib::setFrameRate(int frameRate)
{
	SetTargetFPS(frameRate);
}

int WindowRaylib::getFrameRate() const
{
	return GetFPS();;
}
