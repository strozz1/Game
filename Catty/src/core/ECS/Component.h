#pragma once
#include <string>
#include "../TextureManager.h"
#include "../Vector2D.h"

struct TransformComponent{

	Vector2D position;
	Vector2D size;
	float scale;

	//Defaut constructor if no args passed. Default position at (0,0) size (32,32).
	TransformComponent() :position(0.0f,0.0f),size(32.0f,32.0f),scale(1.0f) {
	}
	//Constructor with x & y coordenates.
	TransformComponent(float x,float y, float width, float heigth,float scaleProp) : position(x, y), size(width, heigth),scale(scaleProp) {
	}

	void move(int x,int y) {

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


