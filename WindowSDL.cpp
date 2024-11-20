#include "WindowSDL.h"

WindowSDL::~WindowSDL() {
    close();
}

void WindowSDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::runtime_error("SDL n'a pas pu être initialisé : " + std::string(SDL_GetError()));
	}
}

void WindowSDL::createWindow(int width, int height, const std::string& title)
{
    Window::createWindow(width, height, title);

    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        throw std::runtime_error("Impossible de créer une fenêtre SDL : " + std::string(SDL_GetError()));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        throw std::runtime_error("Impossible de créer un renderer SDL : " + std::string(SDL_GetError()));
    }

    open = true;
}

bool WindowSDL::isOpen() const
{
    return open;
}

void WindowSDL::clear(const ColorRGBA& color)
{
	SDL_SetRenderDrawColor(renderer, color.R(), color.G(), color.B(), color.A());
	SDL_RenderClear(renderer);
}

void WindowSDL::beginDrawing() {}

void WindowSDL::endDrawing()
{
    SDL_RenderPresent(renderer);
}

void WindowSDL::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
{

}

void WindowSDL::removeCircle(const std::string& label)
{

}

void WindowSDL::createSprite(int x, int y, const std::string& filePath)
{

}

void WindowSDL::close()
{
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
    open = false;
}

void WindowSDL::createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize)
{

}

void WindowSDL::removeText(const std::string& label)
{

}

void WindowSDL::loadFont(const std::string& fontPath)
{
}

void WindowSDL::setFrameRate(int frameRate)
{
}