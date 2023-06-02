#pragma once

#include <iostream>
#include "sdl2/SDL.h"
#include "sdl2/SDL_main.h"
#include "sdl2/SDL_image.h"
#include "init.h"
#include "input.h"
#include "logic.h"
#include "draw.h"
#include "benchmark.h"
#include <windows.h>
using namespace std;

void clear() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
	SDL_RenderClear(app.renderer);
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 200, 255);

}

void clear_screen()

{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}

static void capFrameRate()
{

	static long then;
	static float remainder = 0;

	long wait, frameTime;

	wait = 16 + remainder;

	remainder -= (int)remainder;

	frameTime = SDL_GetTicks() - then;

	wait -= frameTime;

	if (wait < 1)
	{
		wait = 1;
	}

	SDL_Delay(wait);

	remainder += 0.667;

	then = SDL_GetTicks();
}






void run() {

	initSDL();
	initGame();
	initMapPoints();
	
	Benchmark test;

	while (true) {


		clear();

		test.start();

		doInput();
		drawMap();

	

		doLogic();
		draw();

		test.end();
		static int cpt = 10;
		static int prosses = 0;

		prosses += test.time;
		if (!--cpt) {

			clear_screen();
			printf("time : %d     \n",prosses/10);
			cpt = 10;
			prosses = 0;
		}

		SDL_RenderPresent(app.renderer);

		capFrameRate();
	}


}