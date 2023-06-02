#pragma once
#pragma once

#include <iostream>
#include "sdl2/SDL.h"
#include "sdl2/SDL_main.h"
#include "sdl2/SDL_image.h"
using namespace std;
void doKeydown(SDL_KeyboardEvent);
void doKeyup(SDL_KeyboardEvent);


void doInput() {

	SDL_Event event ;

	while (SDL_PollEvent(&event)) {

		switch (event.type)
		{
		case SDL_QUIT:
		{
			exit(1);
		}
		case SDL_KEYDOWN:
		{
			doKeydown(event.key);
			break;
		}
		case SDL_KEYUP:
		{
			doKeyup(event.key);
			break;
		}
		default:
			break;
		}

	}
}


void doKeydown(SDL_KeyboardEvent key) {

	if (!key.repeat) {

		app.keyboard[key.keysym.scancode] = true;
	}

}

void doKeyup(SDL_KeyboardEvent key)
{



	if (!key.repeat) {

		app.keyboard[key.keysym.scancode] = false;
	}

}