#include "Game.h"
#include "ECS/Entity.h"
#include "ECS/Component.h"

SDL_Renderer* Game::renderer = nullptr;
Scene* scene= nullptr;
Entity player;


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
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

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
		SDL_SetRenderDrawColor(renderer, 255, 5, 155, 233);

		running = true;
	}
	else {
		running = false;
	}
	

	scene = new Scene();

	player = scene->CreateEntity("Player1");
	player.AddComponent<TextureComponent>("./src/assets/player.png");
	TransformComponent trans = player.GetComponent<TransformComponent>();
	trans.scale = 5.0f;
	trans.position = { 500.0f,120.0f };
	player.ReplaceComponent<TransformComponent>(trans.position.x, trans.position.y, trans.size.x, trans.size.y,trans.scale);


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


	scene->onUpdate();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	scene->onRender();
	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	//Destroy everything
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	Logger::LOG("Closing game", Logger::INFO);

}
