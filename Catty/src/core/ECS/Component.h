#pragma once
#include <string>
#include "../TextureManager.h"

struct TransformComponent{
	int x_pos;
	int y_pos;
	SDL_Rect srcRect, destRect;

	//Defaut constructor if no args passed. Default position at (0,0).
	TransformComponent() : x_pos(0), y_pos(0) {
		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 0;
		srcRect.y = 0;

		destRect.x = x_pos;
		destRect.y = y_pos;
		destRect.w = srcRect.w * 2;
		destRect.h = srcRect.h * 2;
	}
	//Constructor with x & y coordenates.
	TransformComponent(int x,int y,int width,int heigth) : x_pos(x), y_pos(y)  {
		
	}

	void move(int x,int y) {
		x_pos += x;
		y_pos += y;

	}

};

struct TagComponent {
	std::string Tag;

	TagComponent(){
	}
	TagComponent(std::string tag) : Tag(tag){
	}


};

struct TextureComponent {
	SDL_Texture* texture;

	TextureComponent(const char* textureLoad) {
		texture= TextureManager::LoadTexture(textureLoad);
	}


};


