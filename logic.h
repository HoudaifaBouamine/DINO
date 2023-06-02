#pragma once
#include "global.h"

bool areOverlaped(SDL_FRect rect1, SDL_FRect rect2) {

	return (rect1.x <= rect2.x + rect2.w && rect1.x + rect1.w >= rect2.x && rect1.y <= rect2.y + rect2.h && rect1.y + rect1.h >= rect2.y);

}

void raycasting(float& distance,float a) {



	SDL_FRect rec = {};
	distance = 0;

	rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle + a) * distance;
	rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle + a) * distance;
	char step = 4;
	for (size_t i = 0; i < 20; i++)
	{



		for (SDL_FRect block : map_points) {

			if (areOverlaped(rec, block)) {

				if (distance > step)
					distance -= step;
				else
					distance = 0;

				rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle + a) * distance;
				rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle + a) * distance;
				while (!areOverlaped(rec, block)) {
					distance++;
					rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle + a) * distance;
					rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle + a) * distance;
				}
				distance--;

				return;
			}


		}

		distance += step;
		rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle+a) * distance;
		rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle+a) * distance;


	}


	for (SDL_FRect block : map_points) {

		if (areOverlaped(rec, block)) {

			if (distance > step)
				distance -= step;
			else
				distance -= 0;

			rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle + a) * distance;
			rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle + a) * distance;
			while (!areOverlaped(rec, block)) {
				distance += 2;
				rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle + a) * distance;
				rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle + a) * distance;
			}
			distance--;

			return;
		}


	}

}

void doLogic() {

	Player tmp1 = player;
	

	SDL_FRect tmp = player.rect;

	if (app.keyboard[SDL_SCANCODE_LEFT]) {
		player.rect.x -= cos(player.view.angle + PI/2);
		for (SDL_FRect block : map_points) {

			if (areOverlaped(player.rect, block)) {

				player.rect = tmp;


				break;
			}
		}
		player.rect.y -= sin(player.view.angle + PI/2);
		for (SDL_FRect block : map_points) {

			if (areOverlaped(player.rect, block)) {

				player.rect = tmp;


				break;
			}
		}
	};
	


	tmp = player.rect;
	if (app.keyboard[SDL_SCANCODE_RIGHT]) {
		//player.rect.x++
		player.rect.x += cos(player.view.angle + PI/2);
		for (SDL_FRect block : map_points) {

			if (areOverlaped(player.rect, block)) {

				player.rect = tmp;


				break;
			}
		}
		player.rect.y += sin(player.view.angle + PI/2);
		for (SDL_FRect block : map_points) {

			if (areOverlaped(player.rect, block)) {

				player.rect = tmp;


				break;
			}
		}
	};

	tmp = player.rect;

	if (app.keyboard[SDL_SCANCODE_UP]) {

		player.rect.x += cos(player.view.angle );
		for (SDL_FRect block : map_points) {

			if (areOverlaped(player.rect, block)) {

				player.rect = tmp;


				break;
			}
		}
		player.rect.y += sin(player.view.angle );
		for (SDL_FRect block : map_points) {

			if (areOverlaped(player.rect, block)) {

				player.rect = tmp;


				break;
			}
		}
	};
	
	tmp = player.rect;

	if (app.keyboard[SDL_SCANCODE_DOWN]) {
		player.rect.x -= cos(player.view.angle);
		for (SDL_FRect block : map_points) {

			if (areOverlaped(player.rect, block)) {

				player.rect = tmp;


				break;
			}
		}
		player.rect.y -= sin(player.view.angle);
		for (SDL_FRect block : map_points) {

			if (areOverlaped(player.rect, block)) {

				player.rect = tmp;


				break;
			}
		}
	};
	

	tmp = player.rect;

	if (app.keyboard[SDL_SCANCODE_R])player.view.angle+= 0.03;
	if (app.keyboard[SDL_SCANCODE_E])player.view.angle -= 0.03;
	
	
	raycasting(player.view.distance,0);

	for (float i = 0; i < player.view.dis.size(); i++)
	{
		raycasting(player.view.dis[i],( - 1 * float(player.view.dis.size()) / (2 * player.view.dis.size()) + i / player.view.dis.size()));
	}
}



/*


	SDL_FRect rec = {};
	player.view.distance = 0;

	rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle) * player.view.distance;
	rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle) * player.view.distance;
	 char step = 10;
	for (size_t i = 0; i < 10; i++)
	{



		for (SDL_FRect block : map_points) {

			if (areOverlaped(rec, block)) {

					if (player.view.distance > step)
						player.view.distance -= step;
					else
						player.view.distance -= 0;

					rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle) * player.view.distance;
					rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle) * player.view.distance;
					while (!areOverlaped(rec, block)) {
						player.view.distance+=2;
						rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle) * player.view.distance;
						rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle) * player.view.distance;
					}
						player.view.distance--;

					return;
			}


		}

		player.view.distance += step;
		rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle) * player.view.distance;
		rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle) * player.view.distance;


	}

	for (SDL_FRect block : map_points) {

		if (areOverlaped(rec, block)) {

			if (player.view.distance > step)
				player.view.distance -= step;
			else
				player.view.distance -= 0;

			rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle) * player.view.distance;
			rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle) * player.view.distance;
			while (!areOverlaped(rec, block)) {
				player.view.distance++;
				rec.x = player.rect.x + player.rect.w / 2 + cos(player.view.angle) * player.view.distance;
				rec.y = player.rect.y + player.rect.h / 2 + sin(player.view.angle) * player.view.distance;
			}
			player.view.distance--;

			return;
		}


	}

*/