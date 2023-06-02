#pragma once
#include "global.h"

void drawMap() {
	
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 200, 255);
	for (char i = 0; i < 30; i++)
	{
		for (char j = 0; j < map[i].length(); j++)
		{
			if (map[i][j] == '#') {
				rec.x = j * rec.w;
				rec.y = i * rec.h;
				SDL_RenderDrawRect(app.renderer, &rec);

				map_points.push_back(rec);
			}
		}
	}
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 200, 255);

}

void drawPlayer() {

	SDL_SetRenderDrawColor(app.renderer, 200, 0, 0, 255);
	
	SDL_RenderDrawRect(app.renderer,&player.rect);
	
	SDL_RenderDrawLine(app.renderer, player.rect.x + player.rect.w  / 2, player.rect.y + player.rect.h / 2, player.rect.x + player.rect.w/2 + cos(player.view.angle) * player.view.distance, player.rect.y + player.rect.h / 2 + sin(player.view.angle) * player.view.distance);
}

void draw() {

	drawPlayer();

}
