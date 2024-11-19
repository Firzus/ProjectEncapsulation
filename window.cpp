#include "window.h"

void Window::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{
    if (circles.find(label) != circles.end()) {
        std::cerr << "Un cercle avec l'identifiant '" << label << "' existe déjà.\n";
        return;
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
