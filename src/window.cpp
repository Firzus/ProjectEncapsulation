#include "window.h"

void Window::createWindow(int width, int height, const std::string& title)
{
	windowWidth = width;
	windowHeight = height;
}

void Window::draw(std::unordered_map<std::string, Entity*> entities)
{
	for (std::pair<const std::string, Entity*>& pair : entities) {
		pair.second->draw();
	}
}