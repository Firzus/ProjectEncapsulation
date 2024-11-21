#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(std::string label, int x, int y, std::string texturePath, float rotation, float scale, SDL_Renderer* renderer) : Sprite(label, x, y, texturePath, rotation, scale)
{
    this->renderer = renderer;

    image = SDL_LoadBMP(texturePath.c_str());

    if (!image) {
        std::cerr << "Error loading image: " << SDL_GetError() << std::endl;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, image);

    if (!texture) {
        std::cerr << "Error creating texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(image);
        return;
    }

    int intScale = scale;
    dstrect = { x, y, (image->w) * intScale, (image->h) * intScale };   // posx, posy, length, height

    // Rotation angle (in degrees)
    this->rotation = rotation;

    // Pivot point
    pivot = { dstrect.w / 2, dstrect.h / 2 };

    SDL_FreeSurface(image);
}

SpriteSDL::~SpriteSDL()
{
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    if (image) {
        SDL_FreeSurface(image);
        image = nullptr;
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
