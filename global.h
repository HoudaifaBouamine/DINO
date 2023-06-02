#pragma once


#include <iostream>
#include "sdl2/SDL.h"
#include "sdl2/SDL_main.h"
#include "sdl2/SDL_image.h"
#include "struct.h"
#include <vector>
using namespace std;


App app = {};
Player player = {};
SDL_FRect rec = {};
string map[30] = {};
vector<SDL_FRect> map_points = {};
