#pragma once

#include <iostream>
#include "sdl2/SDL.h"
#include "sdl2/SDL_main.h"
#include "sdl2/SDL_image.h"
#include "global.h"
#include "defs.h"
using namespace std;






























void initSDL() {

	int rendererFlags = SDL_RENDERER_ACCELERATED, windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	app.window = SDL_CreateWindow("Shooter", 200,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}


void initGame() {

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);

	
	player.rect.x = 8;
	player.rect.y = 8;
	player.rect.w = 4;
	player.rect.h = 4;
	player.view.angle = 0;
	player.view.distance = 40;
	


	map[0] =  "##############################";;
	map[1] =  "#    #     #       #    ##   #";
	map[2] =  "#    #     #       #     #   #";
	map[3] =  "#    #     #####   #    ##   #";
	map[4] =  "#    #     #   #   #    ##   #";
	map[5] =  "#    #     #   #   #     #   #";
	map[6] =  "#    #     #       #    ##   #";
	map[7] =  "#    #             #    ##   #";
	map[8] =  "#    #             #     #   #";
	map[9] =  "#    #     #       #    ##   #";
	map[10] = "#    #     #       #    ##   #";
	map[11] = "#    # #####       #     #   #";
	map[12] = "#    #     #       #    ##   #";
	map[13] = "#    #     #       #    ##   #";
	map[14] = "#    #     #       #    ##   #";
	map[15] = "#                            #";
	map[16] = "#                            #";
	map[17] = "##################  ##########";
	map[18] = "#                            #";
	map[19] = "#                            #";
	map[20] = "#                            #";
	map[21] = "#    #     #       #    ##   #";
	map[22] = "#    #     #       #    ##   #";
	map[23] = "#    #     #       #    ##   #";
	map[24] = "#    #     #       #    ##   #";
	map[25] = "#                            #";
	map[26] = "#                            #";
	map[27] = "#                            #";
	map[28] = "#                            #";
	map[29] = "##############################";;

	rec.h = 5;
	rec.w = 5;

	for (size_t i = 0; i < 200; i++)
	{
		player.view.dis.push_back({});
	}

}




void initMapPoints() {

	for (char i = 0; i < 30; i++)
	{
		for (char j = 0; j < map[i].length(); j++)
		{
			if (map[i][j] == '#') {
				rec.x = j * rec.w;
				rec.y = i * rec.h;

				map_points.push_back(rec);
			}
		}
	}

}



