#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Utils.hpp"

int main(int argc, char* args[])
{	
	int SCREEN_WIDTH = 1280;
	int SCREEN_HEIGHT = 720;
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderWindow window("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);

	//SDL_Texture* grassTexture = window.loadTexture("res/img/grass_1.png");
	SDL_Texture* playerTexture = window.loadTexture("res/img/fox.png");

    // Entity entities[4] = {Entity(0, 0, grassTexture),
    //                       Entity(30, 0, grassTexture),
    //                       Entity(30, 30, grassTexture),
    //                       Entity(30, 60, grassTexture)};
    //Handy Example


    std::vector<Entity> entities = {};


	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	Player Chad(Vector2f(SCREEN_WIDTH/8 - 16,SCREEN_HEIGHT/4 - 32), playerTexture);
	

	const float dt = 0.01f;
	float accumulator = 0.01f;
	float currentTime = utils::higherTimeInSeconds();
	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning)
	{	
		float newTime = utils::higherTimeInSeconds();
		float frameTIme= newTime-currentTime;
		currentTime = newTime;
		accumulator+= frameTIme;
		while(accumulator>= dt)
		{


		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			
			switch(event.type){
				case SDL_QUIT:
					gameRunning = false;
					break;
				case SDL_KEYDOWN:

					Chad.getVel().x = Chad.getVel().x *0.2;
					Chad.playerMove(keystate,SCREEN_HEIGHT/4);
					break;
				case SDL_KEYUP:
					Chad.getVel().x = Chad.getVel().x *0.2;
					break;

				}
		}
		accumulator -= dt;
		}
		const float alpha = accumulator/dt;
		window.clear();
		

		for (Entity& e : entities)
		{ 
			window.render(e);
		}
		Chad.playerMove(keystate,SCREEN_HEIGHT/4);
		Chad.playerUpdate(SCREEN_WIDTH/4,SCREEN_HEIGHT/4);
		window.render(Chad);

		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
