#include "window.h"

void Window::update()
{
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