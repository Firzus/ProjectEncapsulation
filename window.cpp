#include "window.h"

void Window::createWindow(int width, int height, const std::string& title)
{
	windowWidth = width;
	windowHeight = height;
}

void Window::draw()
{
    for (std::pair<const std::string, Circle*>& pair : circles) {
        pair.second->draw();
    }

	for (std::pair<const std::string, Text*>& pair : texts) {
		pair.second->draw();
	}
}

void Window::close()
{
    delete this;
}

void Window::createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize)
{
	if (texts.find(label) != texts.end()) {
		std::cerr << "Un texte avec l'identifiant '" << label << "' existe d�j�.\n";
		return;
	}
}

void Window::removeText(const std::string& label)
{
	std::unordered_map<std::string, Text*>::iterator it = texts.find(label);
	if (it != texts.end()) {
		delete it->second;
		texts.erase(it);
	}
}

void Window::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{
    if (circles.find(label) != circles.end()) {
        std::cerr << "Un cercle avec l'identifiant '" << label << "' existe d�j�.\n";
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

Text* Window::getText(const std::string& label)
{
    std::unordered_map<std::string, Text*>::iterator it = texts.find(label);
    if (it != texts.end()) {
        return it->second;
    }

    return nullptr;
}
