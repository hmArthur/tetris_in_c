#include "grid.h"


void restartGrid(int** grid, int width, int height) {
	int i, j;

	for(i = 0; i < height; i++) 
		for(j = 0; j < width; j++) 
			grid[i][j] = 0;
}

int** generateGrid(int width, int height) {
	int i, j;

	int** grid = (int**) malloc(sizeof(int*) * (height));

	for(i = 0; i < height; i++)
		grid[i] = (int*) malloc(sizeof(int) * (width));

    for(i = 0; i < height; i++)
        for(j = 0; j < width; j++) 
            grid[i][j] = 0;

	return grid;
}

void freeGrid(int** grid, int width, int height) {
	int i;

	for(i = 0; i < height; i++)
		free(grid[i]);
	
	free(grid);
}

void refreshGrid(int** grid, int columns, int lines, int square_size, int* score) {
	int i, j, k, l;
	Rectangle rec;
	int isCompleted;
  

	rec.width = square_size;
	rec.height = square_size;

	for(i = 0; i < lines; i++) {
		isCompleted = 1;
		for(j = 0; j < columns; j++) {
			rec.x = X_GRID + (square_size * j);
			rec.y = Y_GRID + (square_size * i);

            if(grid[i][j])
                DrawRectangle(X_GRID+j*square_size, Y_GRID+i*square_size, square_size, square_size, pallete[grid[i][j]-1]);
            else {
				isCompleted=0;
			    DrawRectangleRec(rec, BLACK);
			}
		}

		/* 
		checks for completed lines,
		then refresh the entire matrix from that line above
		*/
		if(isCompleted) {
			*score+=1;
			for(k = i; k > 0; k--) {
				for(l = 1; l < columns-1; l++) {
					grid[k][l] = grid[k-1][l];
				}
			}	
		}
	}
}