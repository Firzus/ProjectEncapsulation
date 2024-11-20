#include "WindowSDL.h"

WindowSDL::~WindowSDL() {
    close();
}

void WindowSDL::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw std::runtime_error("SDL n'a pas pu �tre initialis� : " + std::string(SDL_GetError()));
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
        throw std::runtime_error("Impossible de cr�er une fen�tre SDL : " + std::string(SDL_GetError()));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        throw std::runtime_error("Impossible de cr�er un renderer SDL : " + std::string(SDL_GetError()));
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

    // Cap to chosen FPS
    SDL_Delay(floor((1000 / wantedFrameRate) - elapsedMS));

    SDL_RenderPresent(renderer);
}

//void WindowSDL::createCircle(std::string label, int x, int y, const ColorRGBA& color, float radius)
//{
//    Window::createCircle(label, x, y, color, radius);
//
//    circles[label] = new CircleSDL(label, x, y, color, radius, renderer);
//}
//
//void WindowSDL::removeCircle(const std::string& label)
//{
//    Window::removeCircle(label);
//}
//
//void WindowSDL::createSprite(int x, int y, const std::string& filePath)
//{
//
//}

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

//void WindowSDL::createText(std::string label, int x, int y, const ColorRGBA& color, std::string content, int fontSize)
//{
//
//}
//
//void WindowSDL::removeText(const std::string& label)
//{
//
//}

//void WindowSDL::loadFont(const std::string& fontPath)
//{
//}

void WindowSDL::setFrameRate(int frameRate)
{
    wantedFrameRate = frameRate;
}

int WindowSDL::getFrameRate() const
{
    return 0;
}