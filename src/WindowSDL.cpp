#include "WindowSDL.h"

WindowSDL::~WindowSDL() {
    close();
}

void WindowSDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::runtime_error("SDL n'a pas pu être initialisé : " + std::string(SDL_GetError()));
	}

    if (TTF_Init() == -1) {
        throw std::runtime_error("Erreur d'initialisation de SDL_ttf : " + std::string(SDL_GetError()));
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

void WindowSDL::beginDrawing() 
{
    while (SDL_PollEvent(&event)) 
    {
        if (event.type == SDL_QUIT) 
        { 
            open = false;
        }

        // Events
    }

    // Start FPS counter
    start = SDL_GetPerformanceCounter();

    /*
    SDL_Rect rect;
    rect.x = 250;
    rect.y = 150;
    rect.w = 200;
    rect.h = 200;

    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
    */

    /*
    SDL_RenderDrawCircle(renderer, 200, 200, 50);
    SDL_RenderFillCircle(renderer, 200, 200, 50);
    */

    /*
    if (!isImageLoaded)
    {
        image = SDL_LoadBMP("x64/Debug/tree.bmp");
        texture = SDL_CreateTextureFromSurface(renderer, image);
        dstrect = { 50, 20, 700, 400 };   // posx, posy, length, height

        isImageLoaded = true;
    }
    // copy the texture to the rendering context
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    */

}

void WindowSDL::endDrawing()
{
    // End FPS counter
    end = SDL_GetPerformanceCounter();
    float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

    //currentFrameRate = 1.0f / (elapsedMS / 1000);

    // Calculer le délai restant pour atteindre le FPS souhaité
    float delay = 1000.0f / wantedFrameRate;

    // Ne pas appeler SDL_Delay si le délai est négatif ou nul
    if (elapsedMS < delay) {
        SDL_Delay(static_cast<Uint32>(floor(delay - elapsedMS)));
    }

    currentFrameRate = 1000.0f / (elapsedMS + (delay - elapsedMS > 0 ? delay - elapsedMS : 0));

    SDL_RenderPresent(renderer);
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
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    if (image) {
        SDL_FreeSurface(image);
        image = nullptr;
    }

    SDL_Quit();
    open = false;
}

void WindowSDL::setFrameRate(int frameRate)
{
    wantedFrameRate = frameRate;
}

int WindowSDL::getFrameRate() const
{
    return currentFrameRate;
}
