#ifndef HUD
#define HUD

#include "raylib.h"
#include "consts.h"
#include "piece.h"

#define SCORE_BOARD_H 100
#define SCORE_BOARD_W 200

#define NEXT_PIECE_H 150
#define NEXT_PIECE_W 200

#define BEST_SCORES_H 100
#define BEST_SCORES_W 200

#define FONTSIZE 20

#define SPACING 15

void defineHud(Rectangle* scoreBoard, Rectangle* nextPieceBoard, Rectangle* bestScores, Rectangle* gridBoard);
void drawUserScore(Rectangle* boardScore, int score);
void drawBestScores(Rectangle* bestScoreBoard, int* bestScores);
void drawNextPiece(Rectangle* nextPieceBoard, int nextPiece);
void drawPieceOnHud(Rectangle* nextPieceBoard, int nextPiece);
void drawGridBoard(Rectangle* gridBoard);
void gameOverScreen(int* gameOver);

#endif