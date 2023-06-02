#pragma once

#include <iostream>
#include "sdl2/SDL.h"
#include "sdl2/SDL_main.h"
#include "sdl2/SDL_image.h"
#include "init.h"
#include "input.h"
#include "logic.h"
#include "draw.h"
using namespace std;

void clear() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 200, 255);

}

void run() {

	initSDL();
	initGame();
	initMapPoints();
	

	while (true) {


		clear();
		doInput();
		drawMap();

	

		doLogic();
		draw();
		SDL_RenderPresent(app.renderer);

		SDL_Delay(16);
	}


}