#ifndef PIECE
#define PIECE

#include "raylib.h"
#include <unistd.h>
#include "consts.h"
#include "math.h"
#include "time.h"
#include <stdlib.h>

#define SPEED 25

typedef struct {
	Vector2 velocity;
	Color color;
	int (*shape)[4];
} Piece;


Piece* createPiece(int shape);
int randomPiece();
void refreshPiece(Piece* piece);
void fixPieceOnBoard(Piece* piece, int** grid);
void checkPiecePosition(Piece* piece, int** grid);
void gravity(Piece* piece, int** grid, int* nextPiece, int* gameOver);
void resetPiece(Piece* piece, int shapeIndex);
void rotatePiece(Piece* piece, int** grid);
int checkCollision(int shape[4][4], Piece* piece, int** grid, int offsetX, int offsetY);

#endif