#ifndef GRID
#define GRID

#include "raylib.h"
#include "consts.h"
#include <stdlib.h>

int** generateGrid(int width, int height);
void restartGrid(int** grid, int width, int height);
void refreshGrid(int** grid, int columns, int lines, int square_size, int* score);
void freeGrid(int** grid, int width, int height);

#endif