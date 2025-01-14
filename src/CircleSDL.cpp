#include "CircleSDL.h"

void CircleSDL::draw() const
{
    SDL_SetRenderDrawColor(renderer, color.R(), color.G(), color.B(), color.A());

    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawPoint(renderer, posX + offsetx, posY + offsety);
        status += SDL_RenderDrawPoint(renderer, posX + offsety, posY + offsetx);
        status += SDL_RenderDrawPoint(renderer, posX - offsetx, posY + offsety);
        status += SDL_RenderDrawPoint(renderer, posX - offsety, posY + offsetx);
        status += SDL_RenderDrawPoint(renderer, posX + offsetx, posY - offsety);
        status += SDL_RenderDrawPoint(renderer, posX + offsety, posY - offsetx);
        status += SDL_RenderDrawPoint(renderer, posX - offsetx, posY - offsety);
        status += SDL_RenderDrawPoint(renderer, posX - offsety, posY - offsetx);

        status += SDL_RenderDrawLine(renderer, posX - offsety, posY + offsetx,
            posX + offsety, posY + offsetx);
        status += SDL_RenderDrawLine(renderer, posX - offsetx, posY + offsety,
            posX + offsetx, posY + offsety);
        status += SDL_RenderDrawLine(renderer, posX - offsetx, posY - offsety,
            posX + offsetx, posY - offsety);
        status += SDL_RenderDrawLine(renderer, posX - offsety, posY - offsetx,
            posX + offsety, posY - offsetx);

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
