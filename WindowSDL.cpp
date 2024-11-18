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

    // Drawing color
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

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

    if (!isImageLoaded)
    {
        image = SDL_LoadBMP("x64/Debug/tree.bmp");
        texture = SDL_CreateTextureFromSurface(renderer, image);
        dstrect = { 20, 20, 400, 600 };   // posx, posy, length, height

        isImageLoaded = true;
    }
    // copy the texture to the rendering context
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

}

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


WindowSDL::~WindowSDL() {
    close();
}


void WindowSDL::SDL_RenderDrawCircle(SDL_Renderer* renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2 * offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}


void WindowSDL::SDL_RenderFillCircle(SDL_Renderer* renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;

    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
            x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
            x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
            x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
            x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2 * offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}