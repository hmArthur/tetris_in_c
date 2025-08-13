#include "hud.h"


void gameOverScreen(int* gameOver) {
    Rectangle gameOverBoard;
    gameOverBoard.height = SCREEN_HEIGHT/2;
    gameOverBoard.width = SCREEN_WIDTH/2;
    gameOverBoard.x = (SCREEN_WIDTH-gameOverBoard.width)/2;
    gameOverBoard.y = (SCREEN_HEIGHT-gameOverBoard.height)/2;
    int xPos = gameOverBoard.x+(-70)+(gameOverBoard.width/2);
    int yPos = gameOverBoard.y+SPACING; 

    DrawRectangleLines(gameOverBoard.x-2,gameOverBoard.y-2, gameOverBoard.width+4, gameOverBoard.height+4, WHITE);
    DrawRectangleRec(gameOverBoard, GRAY);
    DrawText("Game Over", xPos, yPos, 30, BLACK);
    DrawText("Try Again?", xPos, yPos+30, 30, BLACK);
    DrawText("Y - Continue", xPos-30, yPos+90, 30, BLACK);
    DrawText("ESC - Give Up", xPos-30, yPos+120, 30, BLACK);

    if(GetKeyPressed() == KEY_Y)
        *gameOver = 0;
    
    if(GetKeyPressed() == KEY_ESCAPE)
        CloseWindow();

    if(WindowShouldClose()) CloseWindow();
}

void defineHud(Rectangle* scoreBoard, Rectangle* nextPieceBoard, Rectangle* bestScores, Rectangle* gridBoard) {
    scoreBoard->height = SCORE_BOARD_H;
    scoreBoard->width = SCORE_BOARD_W;
    scoreBoard->x = X_GRID - (SCORE_BOARD_W + SPACING);
    scoreBoard->y = Y_GRID;

    nextPieceBoard->height = NEXT_PIECE_H;
    nextPieceBoard->width = NEXT_PIECE_W;
    nextPieceBoard->x = X_GRID - (NEXT_PIECE_W + SPACING);
    nextPieceBoard->y = Y_GRID + (SCORE_BOARD_H + SPACING);

    bestScores->height = BEST_SCORES_H;
    bestScores->width = BEST_SCORES_W;
    bestScores->x = X_GRID + (GRID_WIDTH*SQUARE_SIZE) + SPACING;
    bestScores->y = Y_GRID;

	gridBoard->height = GRID_HEIGHT*SQUARE_SIZE + 4;
	gridBoard->width = GRID_WIDTH*SQUARE_SIZE + 4;
	gridBoard->x = X_GRID-2;
	gridBoard->y = Y_GRID-2;
}

void drawGridBoard(Rectangle* gridBoard) {
	DrawRectangleLinesEx(*gridBoard, 2, WHITE);
}

void drawBestScores(Rectangle* bestScoreBoard, int* bestScores) {
    int i;

    DrawRectangleLinesEx(*bestScoreBoard, 2, WHITE);
    DrawText("PERSONAL BEST", bestScoreBoard->x + SPACING, bestScoreBoard->y + SPACING, FONTSIZE, WHITE);
    DrawText(
        TextFormat("%i", *bestScores),
        bestScoreBoard->x + SPACING,
        bestScoreBoard->y + SPACING + (1*FONTSIZE),
        FONTSIZE, WHITE
    );
}

void drawPieceOnHud(Rectangle* nextPieceBoard, int nextPiece) {
    int i, j;

    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {

            if(shapes[nextPiece][i][j])
            DrawRectangle(
                nextPieceBoard->x+(NEXT_PIECE_W/2-(SQUARE_SIZE*2.5))+(j*SQUARE_SIZE)+SPACING,
                nextPieceBoard->y+(NEXT_PIECE_H/2-(SQUARE_SIZE*2.5))+(i*SQUARE_SIZE)+SPACING,
                SQUARE_SIZE, SQUARE_SIZE,
                pallete[nextPiece]
            );
        }
    }
}

void drawNextPiece(Rectangle* nextPieceBoard, int nextPiece) {
    DrawRectangleLinesEx(*nextPieceBoard, 2, WHITE);
    drawPieceOnHud(nextPieceBoard, nextPiece);
}

void drawUserScore(Rectangle* boardScore, int score) {
    DrawRectangleLinesEx(*boardScore, 2, WHITE);
	DrawText(TextFormat("SCORE: %i", score), boardScore->x+SPACING, boardScore->y+SPACING, FONTSIZE, WHITE);
}