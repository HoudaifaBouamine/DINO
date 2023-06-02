#pragma once
#include "global.h"

bool areOverlaped(SDL_Rect rect1, SDL_Rect rect2) {

	return (rect1.x <= rect2.x + rect2.w && rect1.x + rect1.w >= rect2.x && rect1.y <= rect2.y + rect2.h && rect1.y + rect1.h >= rect2.y);

}

void doLogic() {

	SDL_Rect tmp = player.rect;

	if (app.keyboard[SDL_SCANCODE_LEFT])player.rect.x--;
	for (SDL_Rect block : map_points) {

		if (areOverlaped(player.rect, block)) {

			player.rect = tmp;
			break;
		}
	}
	tmp = player.rect;
	if (app.keyboard[SDL_SCANCODE_RIGHT]) player.rect.x++;
	for (SDL_Rect block : map_points) {

		if (areOverlaped(player.rect, block)) {

			player.rect = tmp;
			break;
		}
	}
	tmp = player.rect;

	if (app.keyboard[SDL_SCANCODE_UP]) player.rect.y--;
	for (SDL_Rect block : map_points) {

		if (areOverlaped(player.rect, block)) {

			player.rect = tmp;
			break;
		}
	}
	tmp = player.rect;

	if (app.keyboard[SDL_SCANCODE_DOWN]) player.rect.y++;
	for (SDL_Rect block : map_points) {

		if (areOverlaped(player.rect, block)) {

			player.rect = tmp;
			break;
		}
	}
	tmp = player.rect;

	if (app.keyboard[SDL_SCANCODE_R])player.view.angle+= 0.03;
	if (app.keyboard[SDL_SCANCODE_E])player.view.angle -= 0.03;


}