#include "Game.h"

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	//Check if fullscreen option is true. If so, set fullscreen flag for the window
	int flags = 0;
	if (fullscreen) flags= SDL_WINDOW_FULLSCREEN;

	//Init SDL2 
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		Logger::LOG("Subsystems initialised", Logger::INFO);

		//Create window component
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		//Check if window is created succesfully
		if (window) Logger::LOG("Window created succesfully", Logger::INFO);
		
		//Instantiate renderer
		renderer = SDL_CreateRenderer(window, -1, 0);
		//Check if renderer is created succesfully
		if (renderer) Logger::LOG("Renderer created succesfully", Logger::INFO);
		
		running = true;
	}
	else {
		running = false;
	}



}


void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			//If X button is pressed, set running to false
			running = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
}

void Game::render()
{
}

void Game::clean()
{
	//Destroy everything
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	Logger::LOG("Closing game", Logger::INFO);

}
