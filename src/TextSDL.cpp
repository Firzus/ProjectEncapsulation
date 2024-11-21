#include "TextSDL.h"

void TextSDL::draw() const
{
	TTF_SetFontSize(customFont, fontSize);

	if (!customFont) {
		std::cerr << "Error: Font is not loaded or initialized!" << std::endl;
		return;
	}

	SDL_Surface* surfaceMessage = 
		TTF_RenderText_Solid(customFont, content.c_str(), sdlColor);

	if (!surfaceMessage) {
		std::cerr << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
		return;
	}

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	if (!Message) {
		std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(surfaceMessage);
		return;
	}

	SDL_Rect Message_rect;
	Message_rect.x = posX;
	Message_rect.y = posY;

	int textWidth, textHeight;
	TTF_SizeText(customFont, content.c_str(), &textWidth, &textHeight);

	Message_rect.w = textWidth;
	Message_rect.h = textHeight;

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}
