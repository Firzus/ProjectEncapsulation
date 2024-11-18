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

void WindowRaylib::clear()
{
    ClearBackground(BLACK);

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

void WindowRaylib::drawSprite(const Sprite& sprite)
{
}

void WindowRaylib::drawShape(const Shape& shape)
{
}

void WindowRaylib::close()
{
	CloseWindow();
}
