#include "QuadrilateralSDL.h"

void QuadrilateralSDL::draw() const
{
    SDL_Surface* rectSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_FillRect(rectSurface, NULL, SDL_MapRGBA(rectSurface->format, color.R(), color.G(), color.B(), color.A()));

    SDL_Texture* rectTexture = SDL_CreateTextureFromSurface(renderer, rectSurface);
    SDL_FreeSurface(rectSurface);

    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    rect.w = width;
    rect.h = height;

    SDL_Point center = { rect.w / 2, rect.h / 2 };
    SDL_RenderCopyEx(renderer, rectTexture, NULL, &rect, rotation, &center, SDL_FLIP_NONE);
    SDL_DestroyTexture(rectTexture);
}
