#include "core/Game.h"

Game* game = nullptr;
const int FPS = 60;

//Time between frames
const int frameDelay = 1000/FPS;

int main(int argc, char* argv[]) {

	game = new Game();
	//Init game
	game->init("Prueba de juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	int frameTime;
	Uint32 frameStart;

	//Main while game loop
	while (game->isRunning()) {
		//Get current time in ms
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		//Get time since last frame
		frameTime = SDL_GetTicks() - frameStart;

		//If frame time is less than the minimun frameDelay, wait the remaning time
		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
	}

	game->clean();
	return 0;
}