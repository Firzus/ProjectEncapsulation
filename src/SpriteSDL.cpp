#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(std::string label, int x, int y, std::string texturePath, float rotation, float scale, SDL_Renderer* renderer) : Sprite(label, x, y, texturePath, rotation, scale)
{
    this->renderer = renderer;

    surface = IMG_Load(texturePath.c_str());

    if (!surface) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (!texture) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    int intScale = scale;
    dstrect = { x, y, (surface->w) * intScale, (surface->h) * intScale };   // posx, posy, length, height

    // Rotation angle (in degrees)
    this->rotation = rotation;

    // Pivot point
    pivot = { dstrect.w / 2, dstrect.h / 2 };

    SDL_FreeSurface(surface);
}

SpriteSDL::~SpriteSDL()
{
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    if (surface) {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }
}

void SpriteSDL::draw() const
{
    // Copy the texture to the renderer
    SDL_RenderCopyEx(renderer, texture, nullptr, &dstrect, rotation, &pivot, SDL_FLIP_NONE);
}

bool SpriteSDL::isColliding(Entity* other)
{
	return false;
}
