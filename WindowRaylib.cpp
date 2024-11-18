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
    BeginDrawing();

    ClearBackground(RAYWHITE);
}

void WindowRaylib::draw(const Sprite& sprite)
{

}

void WindowRaylib::display()
{
    EndDrawing();
}

void WindowRaylib::close()
{
	CloseWindow();
}
