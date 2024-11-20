#include "window.h"

void Window::createWindow(int width, int height, const std::string& title)
{
	windowWidth = width;
	windowHeight = height;
}

void Window::update()
{
	// Draw
    for (auto& pair : circles) {
        pair.second->draw();
    }
}

void Window::close()
{
    delete this;
}

void Window::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{
    if (circles.find(label) != circles.end()) {
        std::cerr << "Un cercle avec l'identifiant '" << label << "' existe déjà.\n";
        return;
    }
}

void Window::removeCircle(const std::string& label)
{
	std::unordered_map<std::string, Circle*>::iterator it = circles.find(label);
	if (it != circles.end()) {
        delete it->second;
		circles.erase(it);
	}
}

Circle* Window::getCircle(const std::string& label)
{
    std::unordered_map<std::string, Circle*>::iterator it = circles.find(label);
    if (it != circles.end()) {
        return it->second;
    }

    return nullptr;
}

int Window::getWindowWidth()
{
    return windowWidth;
}

int Window::getWindowHeight()
{
    return windowHeight;
}
