#pragma once
#include "SDL.h"
#include "SDL_image.h"
class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* file);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};