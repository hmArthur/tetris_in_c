#include "raylib.h"
#include "grid.h"
#include "piece.h"
#include "deltaTime.h"
#include "consts.h"
#include "hud.h"
#include <stdlib.h>


int main() {
	srand(time(NULL));
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
	SetTargetFPS(120);

	int** grid = generateGrid(GRID_WIDTH, GRID_HEIGHT);
	Piece* piece = createPiece(randomPiece());
	int* nextPiece = (int*) malloc(sizeof(int));
	*nextPiece = randomPiece();

	int bestScore = 0;
	int* gameOver = (int*) malloc(sizeof(int));
	*gameOver = 0;

	Rectangle gridBoard;
	Rectangle boardScore;
	Rectangle nextPieceBoard;
	Rectangle bestScores;

	int score;
	float* gravityClock = (float*) malloc(sizeof(float));
	*gravityClock;

	defineHud(&boardScore, &nextPieceBoard, &bestScores, &gridBoard);

	while(!WindowShouldClose()) {
		score=0;
		*gravityClock = 0.0;

		while(!(*gameOver)) {
			BeginDrawing();
			ClearBackground(BLACK);
			
			drawUserScore(&boardScore, score);
			drawNextPiece(&nextPieceBoard, *nextPiece);
			drawBestScores(&bestScores, &bestScore);
			drawGridBoard(&gridBoard);

			refreshGrid(grid, GRID_WIDTH, GRID_HEIGHT, SQUARE_SIZE, &score);
			refreshPiece(piece);
			
			if(deltaTime(gravityClock, 0.8-((score/10)*0.1)))
				gravity(piece, grid, nextPiece, gameOver);

			checkPiecePosition(piece, grid);
			EndDrawing();

			if(WindowShouldClose()) break;
		}
		
		while((*gameOver)) {
			BeginDrawing();
			gameOverScreen(gameOver);
			EndDrawing();
		}

		ClearBackground(BLACK);

		if(bestScore < score) 
			bestScore = score;

		restartGrid(grid, GRID_WIDTH, GRID_HEIGHT);
	}

	freeGrid(grid, GRID_WIDTH, GRID_HEIGHT);
	free(gravityClock);
	free(gameOver);
	free(nextPiece);
	free(piece);
	CloseWindow();

	return 0;
}