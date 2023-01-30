#pragma once
#include <string>
struct TransformComponent{
	int x_pos;
	int y_pos;

	//Defaut constructor if no args passed. Default position at (0,0).
	TransformComponent() : x_pos(0), y_pos(0) {
		
	}
	//Constructor with x & y coordenates.
	TransformComponent(int x,int y) : x_pos(x), y_pos(y) {

	}

	void move(int x,int y) {
		x_pos += x;
		y_pos += y;

	}

};

struct TagComponent {
	std::string Tag;

	//Defaut constructor if no args passed. Default tag "Entity".
	TagComponent(){

	}
	//Constructor with tag.
	TagComponent(std::string tag) : Tag(tag){

	}


};


