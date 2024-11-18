#include "WindowSDL.h"

void WindowSDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::runtime_error("SDL n'a pas pu être initialisé : " + std::string(SDL_GetError()));
	}
}

void WindowSDL::createWindow(int width, int height, const std::string& title)
{
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
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);
}

void WindowSDL::beginDrawing() {}

void WindowSDL::endDrawing()
{
    SDL_RenderPresent(renderer);
}

void WindowSDL::drawSprite(const Sprite& sprite)
{
}

void WindowSDL::drawShape(const Shape& shape)
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

WindowSDL::~WindowSDL() {
    close();
}