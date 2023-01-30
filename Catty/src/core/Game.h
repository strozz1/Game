#include "SDL.h"
#include "../Logger/Logger.h"
class Game
{
public:
	Game();
	~Game();
	
	//Init game with a title, screen position and screen size. Fullscreen option
	void init(const char* title,int xpos, int ypos, int width, int height, bool fullscreen);

	//Function for handling events
	void handleEvents();

	//Updates necesaries values
	void update();

	//Render the game

	//Clean game
	void render();
	void clean();

	//Check if game is running
	bool isRunning() { return running; }

	//Game main renderer that will manage almost everything
	static SDL_Renderer* renderer;

private:
	bool running;
	SDL_Window* window;


};

