#pragma once

#include <iostream>
#include "sdl2/SDL.h"
#include "sdl2/SDL_main.h"
#include "sdl2/SDL_image.h"
#include "defs.h"
#include <vector>
using namespace std;

struct App {

	SDL_Renderer* renderer;
	SDL_Window* window;
	bool keyboard[MAX_KEYBOARD_KEYS];
};

struct Point {

	float x, y;

	Point(){}

	Point(float x, float y) {
		this->x = x;
		this->y = y;
	}

};

struct View {

	float angle;
	vector<Point> points = {};
	short distance;
	
};

struct Player {

	SDL_Rect rect;
	View view;
};
