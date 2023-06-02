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
				SDL_Rect r;
				r.x = rec.x;
				r.y = rec.y;
				r.w = rec.w;
				r.h = rec.h;

				SDL_RenderDrawRect(app.renderer, &r);
			}
		}
	}
	SDL_SetRenderDrawColor(app.renderer, 0, 0, 200, 255);

}

void drawPlayer() {

	SDL_SetRenderDrawColor(app.renderer, 200, 0, 0, 255);
	
	SDL_Rect r = player.GetRect();
	SDL_RenderDrawRect(app.renderer,&r);
	
	SDL_RenderDrawLine(app.renderer, player.rect.x + player.rect.w  / 2, player.rect.y + player.rect.h / 2, player.rect.x + player.rect.w/2 + cos(player.view.angle) * player.view.distance, player.rect.y + player.rect.h / 2 + sin(player.view.angle) * player.view.distance);

	for (float i = 0; i < player.view.dis.size(); i++)
	{
		SDL_RenderDrawLine(app.renderer, player.rect.x + player.rect.w / 2, player.rect.y + player.rect.h / 2, player.rect.x + player.rect.w / 2 + cos(player.view.angle - 1 * float(player.view.dis.size()) / (2 * player.view.dis.size()) + i / player.view.dis.size()) * player.view.dis[i], player.rect.y + player.rect.h / 2 + sin(player.view.angle - 1 * float(player.view.dis.size()) / (2 * player.view.dis.size()) + i / player.view.dis.size()) * player.view.dis[i]);

	}

}

void printline(float i, float j) {

	SDL_SetRenderDrawColor(app.renderer, 255 - player.view.dis[i] * 2,0,0,255);

	SDL_RenderDrawLine(app.renderer, i * 6 + j, SCREEN_HEIGHT / 2 - (10000 / player.view.dis[i])  / 5, i * 6 + j, SCREEN_HEIGHT / 2 + (10000 / player.view.dis[i]) / 5);

}

void drawFirstPerson() {

	for (size_t i = 0; i < player.view.dis.size(); i++)
	{
		for (size_t j = 0; j < 6; j+=1)
		{

			printline(i,j);
		}
		
	}
}

void draw() {

	drawPlayer();

	drawFirstPerson();
	drawMap();
}
