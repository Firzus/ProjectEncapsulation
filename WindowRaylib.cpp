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
	Window::close();

	CloseWindow();
}

void WindowRaylib::createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize)
{
	Window::createText(label, x, y, color, content, fontSize);

	texts[label] = new TextRaylib(customFont, label, x, y, color, content, fontSize);
}

void WindowRaylib::removeText(const std::string& label)
{
	Window::removeText(label);
}

void WindowRaylib::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{
	Window::createCircle(label, x, y, color, radius);

    circles[label] = new CircleRaylib(label, x, y, color, radius, NULL);
}

void WindowRaylib::removeCircle(const std::string& label)
{
	Window::removeCircle(label);
}

void WindowRaylib::createSprite(int x, int y, const std::string& filePath)
{

}

void WindowRaylib::loadFont(const std::string& fontPath)
{
	customFont = LoadFont(fontPath.c_str());
}

void WindowRaylib::setFrameRate(int frameRate)
{
	SetTargetFPS(frameRate);
}