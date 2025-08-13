#ifndef CONSTS
#define CONSTS


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define GRID_WIDTH 10
#define GRID_HEIGHT 20

#define SQUARE_SIZE 25


#define X_GRID (SCREEN_WIDTH/2)-(GRID_WIDTH*SQUARE_SIZE/2)
#define Y_GRID (SCREEN_HEIGHT/2)-(GRID_HEIGHT*SQUARE_SIZE/2)

#define X_LIMIT X_GRID+(SQUARE_SIZE*GRID_WIDTH)
#define Y_LIMIT Y_GRID+(SQUARE_SIZE*GRID_HEIGHT)

#define GRAVITY 1

#include "raylib.h"

extern const Color pallete[7];
extern const int shapes[7][4][4];

#endif